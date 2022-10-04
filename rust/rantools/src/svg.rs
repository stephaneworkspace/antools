extern crate core;

use std::ffi::CStr;
use std::os::raw::c_float;
use crate::{SvgData, SvgPoint, SvgProperties, SvgStroke};
use svg::node::element::{Circle, Line, Path};
use svg::node::element::path::Data;

pub(crate) fn path_data(data: *const SvgData,
                            point: *const SvgPoint,
                            data_size: isize,
                            point_size: isize,
                            properties: SvgProperties) -> String {
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
        let c = char::from_u32(a.data as u32).unwrap();
        data_str += format!("{}", c.to_string()).as_str();
        for (j, b) in vec_point.iter()
            .filter(|f| a.point_idx == f.point_idx)
            .enumerate()
        {
            if a.point_size as usize == j {
                data_str += format!("{}", b.point).as_str();
            } else {
                data_str += format!("{},", b.point).as_str();
            }
        }
    }

    let data = Data::parse(data_str.as_str()).unwrap();

    let fill = unsafe { CStr::from_ptr(properties.fill.fill).to_str().unwrap() };
    let stroke = unsafe { CStr::from_ptr(properties.stroke.stroke).to_str().unwrap() };

    let path = Path::new()
        .set("fill", fill)
        .set("stroke", stroke)
        .set("stroke-width", properties.stroke.stroke_width)
        .set("d", data);

    let res = path.clone().to_string();
    res
}

pub(crate) fn circle(x: c_float,
                     y: c_float,
                     r: c_float,
                     properties: SvgProperties) -> String {
    let fill = unsafe { CStr::from_ptr(properties.fill.fill).to_str().unwrap() };
    let stroke = unsafe { CStr::from_ptr(properties.stroke.stroke).to_str().unwrap() };
    let circle = Circle::new()
        .set("fill", fill)
        .set("cx", x)
        .set("cy", y)
        .set("r", r)
        .set("stroke", stroke)
        .set("stroke-width", properties.stroke.stroke_width);
    circle.to_string()
}

pub(crate) fn line(x1: c_float,
                       y1: c_float,
                       x2: c_float,
                       y2: c_float,
                       stroke: SvgStroke) -> String {
    let stroke_str = unsafe { CStr::from_ptr(stroke.stroke).to_str().unwrap() };
    let line = Line::new()
        .set("x1", x1)
        .set("y1", y1)
        .set("x2", x2)
        .set("y2", y2)
        .set("stroke", stroke_str)
        .set("stroke-width", stroke.stroke_width);
    line.to_string()
}