mod svg;

extern crate base64;

use std::ffi::{CStr, CString};
use std::os::raw::{c_char, c_float, c_int};
use base64::{encode, decode, DecodeError};
use image::{ColorType, GenericImageView, ImageFormat};
use miniz_oxide::deflate::{compress_to_vec_zlib, CompressionLevel};
use pdf_writer::{Content, Filter, Finish, Name, PdfWriter, Rect, Ref};

#[repr(C)]
#[derive(Debug)]
pub struct B64 {
    pub b_64: *const c_char,
    sw: bool,
    pub err: *const c_char,
}

#[no_mangle]
pub extern "C" fn create_png_b64(p_svg_b64: *const c_char) -> B64 {
    let cstr_svg_b64: &CStr = unsafe { CStr::from_ptr(p_svg_b64) };
    let base64_svg = match cstr_svg_b64.to_str() {
        Ok(ok) => {
            ok
        },
        Err(err) => {
            return B64 {
                b_64: CString::new("").unwrap().into_raw(),
                sw: false,
                err: CString::new(format!("Paramètre d'entrée \"p_svg_b64\" invalide {}", err)).unwrap().into_raw()
            }
        }
    };
    let svg_res: Result<Vec<u8>, DecodeError> = decode(base64_svg);
    let svg_v_u8 = match svg_res {
        Ok(ok) => {
            ok
        },
        Err(err) => {
            return B64 {
                b_64: CString::new("").unwrap().into_raw(),
                sw: false,
                err: CString::new(format!("Impossible de décoder le svg. {}", err)).unwrap().into_raw()
            };
        }
    };
    match create_png(svg_v_u8) {
        Ok(ok) => {
            B64 {
                b_64: CString::new(encode(ok)).unwrap().into_raw(),
                sw: true,
                err: CString::new("").unwrap().into_raw()
            }
        },
        Err(err) => {
            err
        }
    }
}

#[no_mangle]
pub extern "C" fn create_pdf_b64(p_svg_b64: *const c_char) -> B64 {
    let cstr_svg_b64: &CStr = unsafe { CStr::from_ptr(p_svg_b64) };
    let base64_svg = match cstr_svg_b64.to_str() {
        Ok(ok) => {
            ok
        },
        Err(err) => {
            return B64 {
                b_64: CString::new("").unwrap().into_raw(),
                sw: false,
                err: CString::new(format!("Paramètre d'entrée \"p_svg_b64\" invalide {}", err)).unwrap().into_raw()
            };
        }
    };

    let svg_res: Result<Vec<u8>, DecodeError> = decode(base64_svg);
    let svg_v_u8 = match svg_res {
        Ok(ok) => {
            ok
        },
        Err(err) => {
            return B64 {
                b_64: CString::new("").unwrap().into_raw(),
                sw: false,
                err: CString::new(format!("Impossible de décoder le svg. {}", err)).unwrap().into_raw()
            };
        }
    };
    let data = match create_png(svg_v_u8) {
        Ok(ok) => {
            ok
        },
        Err(err) => {
            return err;
        }
    };

    match create_pdf(data) {
        Ok(ok) => {
            B64 {
                b_64: CString::new(ok).unwrap().into_raw(),
                sw: true,
                err: CString::new("").unwrap().into_raw()
            }
        },
        Err(err) => {
            err
        }
    }
}

fn create_png(svg_v_u8: Vec<u8>) -> Result<Vec<u8>, B64> {
    let mut opt = usvg::Options::default();
    opt.fontdb.load_system_fonts();
    let rtree = match usvg::Tree::from_data(&svg_v_u8, &opt.to_ref()) {
        Ok(ok) => {
            ok
        },
        Err(err) => {
            return Err(B64 {
                b_64: CString::new("").unwrap().into_raw(),
                sw: false,
                err: CString::new(format!("Impossible de lire le svg. {}", err)).unwrap().into_raw()
            });
        }
    };

    let pixmap_size = rtree.svg_node().size.to_screen_size();
    let mut pixmap = tiny_skia::Pixmap::new(pixmap_size.width(), pixmap_size.height()).unwrap();
    resvg::render(&rtree, usvg::FitTo::Original, tiny_skia::Transform::default(), pixmap.as_mut());
    let png_res = match pixmap.encode_png() {
        Ok(ok) => {
            ok
        },
        Err(err) => {
            return Err(B64 {
                b_64: CString::new("").unwrap().into_raw(),
                sw: false,
                err: CString::new(format!("Impossible d'encoder le png en base64. {}", err)).unwrap().into_raw()
            });
        }
    };
    Ok(png_res)
}

fn create_pdf(data: Vec<u8>) -> Result<String, B64> {
    // Start writing.
    let mut writer = PdfWriter::new();

    // Define some indirect reference ids we'll use.
    let catalog_id = Ref::new(1);
    let page_tree_id = Ref::new(2);
    let page_id = Ref::new(3);
    let image_id = Ref::new(4);
    let s_mask_id = Ref::new(5);
    let content_id = Ref::new(6);
    let image_name = Name(b"Im1");

    // Write a document catalog and a page tree with one A4 page that uses no resources.
    // Set up the page tree. For more details see `hello.rs`.
    writer.catalog(catalog_id).pages(page_tree_id);
    writer.pages(page_tree_id).kids([page_id]).count(1);

    // Specify one A4 page and map the image name "Im1" to the id of the
    // embedded image stream.
    let mut page = writer.page(page_id);
    let a4 = Rect::new(0.0, 0.0, 595.0, 842.0);
    page.media_box(a4);
    page.parent(page_tree_id);
    page.contents(content_id);
    page.resources().x_objects().pair(image_name, image_id);
    page.finish();

    // Decode the image.
    //let data = std::fs::read("examples/rhino.png").unwrap();
    let format = match image::guess_format(&data) {
        Ok(ok) => {
            ok
        },
        Err(_) => {
            return Err(B64 {
                b_64: CString::new("").unwrap().into_raw(),
                sw: false,
                err: CString::new(format!("Impossible de lire l'image via guess_format")).unwrap().into_raw()
            });
        }
    };
    let dynamic = match image::load_from_memory(&data) {
        Ok(ok) => {
            ok
        },
        Err(_) => {
            return Err(B64 {
                b_64: CString::new("").unwrap().into_raw(),
                sw: false,
                err: CString::new(format!("Impossible de lire l'image via load_from_memory")).unwrap().into_raw()
            });
        }
    };

    // Now, there are multiple considerations:
    // - Writing an XObject with just the raw samples would work, but lead to
    //   huge file sizes since the image would be embedded without any
    //   compression.
    // - We can encode the samples with a filter. However, which filter is best
    //   depends on the file format. For example, for JPEGs you should use
    //   DCT-Decode and for PNGs you should use Deflate.
    // - When the image has transparency, we need to provide that separately
    //   through an extra linked SMask image.
    let (filter, encoded, mask) = match format {
        // A JPEG is already valid DCT-encoded data.
        ImageFormat::Jpeg => {
            assert!(dynamic.color() == ColorType::Rgb8);
            (Filter::DctDecode, data, None)
        }

        // While PNGs uses deflate internally, we need to re-encode to get just
        // the raw coded samples without metadata. Also, we need to encode the
        // RGB and alpha data separately.
        ImageFormat::Png => {
            let level = CompressionLevel::DefaultLevel as u8;
            let encoded = compress_to_vec_zlib(dynamic.to_rgb8().as_raw(), level);

            // If there's an alpha channel, extract the pixel alpha values.
            let mask = dynamic.color().has_alpha().then(|| {
                let alphas: Vec<_> = dynamic.pixels().map(|p| (p.2).0[3]).collect();
                compress_to_vec_zlib(&alphas, level)
            });

            (Filter::FlateDecode, encoded, mask)
        }

        // You could handle other image formats similarly or just recode them to
        // JPEG or PNG, whatever best fits your use case.
        _ => panic!("unsupported image format"),
    };

    // Write the stream for the image we want to embed.
    let mut image = writer.image_xobject(image_id, &encoded);
    image.filter(filter);
    image.width(dynamic.width() as i32);
    image.height(dynamic.height() as i32);
    image.color_space().device_rgb();
    image.bits_per_component(8);
    if mask.is_some() {
        image.s_mask(s_mask_id);
    }
    image.finish();

    // Add SMask if the image has transparency.
    if let Some(encoded) = &mask {
        let mut s_mask = writer.image_xobject(s_mask_id, &encoded);
        s_mask.filter(filter);
        s_mask.width(dynamic.width() as i32);
        s_mask.height(dynamic.height() as i32);
        s_mask.color_space().device_gray();
        s_mask.bits_per_component(8);
    }

    // Size the image at 1pt per pixel.
    let w = (dynamic.width() / 2) as f32;
    let h = (dynamic.height() / 2) as f32;

    // Center the image on the page.
    let x = (a4.x2 - w) / 2.0;
    // center let y = (a4.y2 - h) / 2.0;
    let y = ((a4.y2 - h) / 1.0) - 100.0;

    // Place and size the image in a content stream.
    //
    // By default, PDF XObjects always have a size of 1x1 user units (and 1 user
    // unit is one 1pt if you don't change that). To position and size them, you
    // have to change the current transformation matrix, which is structured as
    // [scale_x, skew_x, skew_y, scale_y, translate_x, translate_y]. Also,
    // remember that the PDF coordinate system starts at the bottom left! When
    // you have other elements after the image, it's also important to save &
    // restore the state so that they are not affected by the transformation.
    let mut content = Content::new();
    content.save_state();
    content.transform([w, 0.0, 0.0, h, x, y]);
    content.x_object(image_name);
    content.restore_state();
    writer.stream(content_id, &content.finish());
    Ok(encode(writer.finish()))
}

#[repr(C)]
#[derive(Debug)]
pub struct SvgData {
    pub data: c_char,
    pub point_idx: c_int,
    pub point_size: c_int
}

#[repr(C)]
#[derive(Debug)]
pub struct SvgPoint {
    pub point_idx: c_int,
    pub point: c_float,
}

#[no_mangle]
pub extern "C" fn svg_rust(data: *const SvgData, point: *const SvgPoint, data_size: c_int, point_size: c_int, path: *const c_char) -> *const c_char {
    let res= svg::svg_rust_path(data, point, data_size as isize, point_size as isize, path);
    let res_c_str = CString::new(res).unwrap();
    let res_ptr = res_c_str.into_raw();
    return res_ptr;
}


#[cfg(test)]
mod tests {
    use std::ffi::{CStr, CString};
    use std::os::raw::{c_char, c_float, c_int};
    use svg::node::element::path::{Command, Data, Parameters, Position};
    use crate::{svg_rust, SvgData, SvgPoint};

    #[test]
    fn it_works() {
        let result = 2 + 2;
        assert_eq!(result, 4);
    }
    #[test]
    fn svg_rust_works() {
        let data = Data::new()
            .move_to((10, 10))
            .line_by((0, 50))
            .line_by((50, 0))
            .line_by((0, -50))
            .close();

        let mut vec_data: Vec<SvgData> = Vec::new();
        let mut vec_point: Vec<SvgPoint> = Vec::new();

        let mut closure = |i: usize, c: char, param: &Parameters| -> SvgData {
            let point_size: c_int = param.len() as c_int;
            for j in 0..point_size as usize {
                let point: c_float = *&param[j];
                vec_point.push(SvgPoint {
                    point_idx: i as c_int,
                    point
                })
            };
            SvgData {
                data: c as c_char,
                point_idx: i as c_int,
                point_size
            }
        };

        for (i, x) in data.iter().enumerate().into_iter() {
            let svg_command = match x {
                Command::Move(pos, param) => {
                    let c = match pos {
                        Position::Absolute => {
                            'M' // Move to
                        }
                        Position::Relative => {
                            'm' // Move by
                        }
                    };
                    closure(i, c, &param)
                }
                Command::Line(pos, param) => {
                    let c = match pos {
                        Position::Absolute => {
                            'L' // Line to
                        }
                        Position::Relative => {
                            'l' // Line by
                        }
                    };
                    closure(i, c, &param)
                }
                Command::HorizontalLine(pos, param) => {
                    let c = match pos {
                        Position::Absolute => {
                            'H'
                        }
                        Position::Relative => {
                            'h'
                        }
                    };
                    closure(i, c, &param)
                }
                Command::VerticalLine(pos, param) => {
                    let c = match pos {
                        Position::Absolute => {
                            'V'
                        }
                        Position::Relative => {
                            'v'
                        }
                    };
                    closure(i, c, &param)
                }
                Command::QuadraticCurve(pos, param) => {
                    let c = match pos {
                        Position::Absolute => {
                            'Q'
                        }
                        Position::Relative => {
                            'q'
                        }
                    };
                    closure(i, c, &param)
                }
                Command::SmoothQuadraticCurve(pos, param) => {
                    let c = match pos {
                        Position::Absolute => {
                            'T'
                        }
                        Position::Relative => {
                            't'
                        }
                    };
                    closure(i, c, &param)
                }
                Command::CubicCurve(pos, param) => {
                    let c = match pos {
                        Position::Absolute => {
                            'C'
                        }
                        Position::Relative => {
                            'c'
                        }
                    };
                    closure(i, c, &param)
                }
                Command::SmoothCubicCurve(pos, param) => {
                    let c = match pos {
                        Position::Absolute => {
                            'S'
                        }
                        Position::Relative => {
                            's'
                        }
                    };
                    closure(i, c, &param)
                }
                Command::EllipticalArc(pos, param) => {
                    let c = match pos {
                        Position::Absolute => {
                            'A'
                        }
                        Position::Relative => {
                            'a'
                        }
                    };
                    closure(i, c, &param)
                },
                Command::Close => {
                    SvgData {
                        data: 'Z' as c_char,
                        point_idx: i as c_int,
                        point_size: 0,
                    }
                }
            };
            vec_data.push(svg_command);
        }

        let data = vec_data.as_ptr();
        let point = vec_point.as_ptr();
        let data_size = vec_data.len();
        let point_size = vec_point.len();
        let path_cstring = CString::new("svg_rust.svg").unwrap();
        let path = path_cstring.as_ptr();

        let res = svg_rust(data, point, data_size as c_int, point_size as c_int, path);

        let res_cstr = unsafe { CStr::from_ptr(res) };
        let res_str = res_cstr.to_str().unwrap();

        let assert = r#"<path d="M10,10 l0,50 l50,0 l0,-50 z" fill="none" stroke="black" stroke-width="3"/>"#;
        assert_eq!(assert, res_str);
    }
}