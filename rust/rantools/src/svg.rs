extern crate core;

use crate::{SvgData, SvgPoint};
use svg::Document;
use svg::node::element::Path;
use svg::node::element::path::Data;

pub(crate) fn svg_rust_path(data: *const SvgData, point: *const SvgPoint, data_size: isize, point_size: isize) {
    // SvgData
    let mut vec_data: Vec<SvgData> = Vec::new();
    for i in 0..data_size {
        let svg_data = unsafe { data.offset(i).as_ref().unwrap() };
        vec_data.push(SvgData {
            data: svg_data.data,
            point_idx: svg_data.point_idx,
            point_size: svg_data.point_size
        });
    }
    // SvgPoint
    let mut vec_point: Vec<SvgPoint> = Vec::new();
    for i in 0..point_size {
        let svg_point = unsafe { point.offset(i).as_ref().unwrap() };
        vec_point.push(SvgPoint {
            point_idx: svg_point.point_idx,
            point: svg_point.point
        });
    }
    // Data
    let mut data_str: String = "".to_string();
    for a in vec_data.iter() {
        for (j, b) in vec_point.iter()
            .filter(|f| a.point_idx == f.point_idx)
            .enumerate()
        {
            let c = char::from_u32(a.data as u32).unwrap();
            data_str += format!("{}", c.to_string()).as_str();
            if a.point_size as usize == j {
                data_str += format!("{}", b.point).as_str();
            } else {
                data_str += format!("{},", b.point).as_str();
            }
        }
    }

    let data = Data::parse(data_str.as_str()).unwrap();

    let path = Path::new()
        .set("fill", "none")
        .set("stroke", "black")
        .set("stroke-width", 3)
        .set("d", data);

    let document = Document::new()
        .set("viewBox", (0, 0, 70, 70))
        .add(path);

    svg::save("image.svg", &document).unwrap();
    //println!("{:?}", &document.to_string());
}

