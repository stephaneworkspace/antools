extern crate core;

use std::ffi::{CStr, CString};
use std::os::raw::{c_char, c_float, c_int};
use svg::Document;
use svg::node::element::Path;
use svg::node::element::path::{Data, Parameters, Position};

use svg::node::element::path::Command;
use usvg::Point;

#[repr(C)]
#[derive(Debug)]
pub struct SvgCommand {
    pub command: c_char,
    pub point_i: i32,
    pub point_size: c_int
}

#[repr(C)]
#[derive(Debug)]
pub struct SvgPoint {
    pub i: i32,
    pub j: i32,
    pub point: f32,
}

#[repr(C)]
#[derive(Debug)]
pub struct SvgDataCommand {
    pub svg_command: *const SvgCommand,
    pub svg_command_size: c_int,
}


fn main() {
    let data = Data::new()
        .move_to((10, 10))
        .line_by((0, 50))
        .line_by((50, 0))
        .line_by((0, -50))
        .close();
    //println!("{:?}", &data);

    let mut vec: Vec<SvgCommand> = Vec::new();
    let mut vec_point: Vec<SvgPoint> = Vec::new();

    let closure = |i: usize, c: char, param: &Parameters| -> SvgCommand {
        let point_size: c_int = param.len() as c_int;
        let mut vec_point: Vec<SvgPoint> = Vec::new();
        for j in 0..point_size as usize {
            let point: f32 = *&param[j];
            vec_point.push(SvgPoint {
                i: i as i32,
                j: j as i32,
                point
            })
        };
        SvgCommand {
            command: c as c_char,
            point_i: i as i32,
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
                closure(i, c, param)
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
                closure(i, c, param)
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
                closure(i, c, param)
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
                closure(i, c, param)
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
                closure(i, c, param)
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
                closure(i, c, param)
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
                closure(i, c, param)
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
                closure(i, c, param)
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
                closure(i, c, param)
            },
            Command::Close => {
                SvgCommand {
                    command: 'Z' as c_char,
                    point_i: i as i32,
                    point_size: 0,
                }
            }
        };
        vec.push(svg_command);
    }
    //println!("{:?}", &vec);
    let size_usize = vec.len();
    let svg_command_size: c_int = size_usize as c_int;
    let svg_command_slice = vec.as_slice();
    let svg_command: *const SvgCommand = svg_command_slice.as_ptr();

    let cmd = SvgDataCommand {
        svg_command,
        svg_command_size
    };
    println!("{:?}", &cmd);

    /*
    for i in 0..cmd.size as isize {
        let svg_command_extract = unsafe { cmd.svg_command.offset(i).as_ref().unwrap() };
        unsafe {
            for j in 0..svg_command_extract.point_size as isize {
                let point = unsafe { svg_command_extract.point.offset(j).as_ref().unwrap() };
                println!("{:?}", point.point)
            }
        }
        let c = svg_command_extract.command;
        let cstr = char::from_u32(c as u32).unwrap();
        println!("{:?} - {}", &svg_command_extract, cstr);
    }

    */

/*
    let mut data2 = Data::new()
        .move_to((10, 10))
        .line_by((0, 50))
        .line_by((50, 0))
        .line_by((0, -50))
        .close();
    data2.move_to((1,2,2));

    let data = Data::parse("M1,2 l3,4").unwrap();
*/
    /*

    let path = Path::new()
        .set("fill", "none")
        .set("stroke", "black")
        .set("stroke-width", 3)
        .set("d", data);

    let document = Document::new()
        .set("viewBox", (0, 0, 70, 70))
        .add(path);

    //svg::save("image.svg", &document).unwrap();
    println!("{:?}", &document.to_string());*/
}