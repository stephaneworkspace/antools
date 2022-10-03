extern crate core;

use std::os::raw::{c_float, c_int};
use svg::Document;
use svg::node::element::Path;
use svg::node::element::path::{Data, Parameters, Position};

use svg::node::element::path::Command;

/*
 command
 0 = Move (Position, Parameters)
 1 = Line (Position, Parameters)
 2 = HorizonalLine (Position, Parameters)
 3 = VerticalLine (Position, Parameters)
 4 = QuadraticCurve (Position, Parameters)
 5 = SmoothQuadraticCurve (Position, Parameters)
 6 = CubicCurve (Position, Parameters)
 7 = SmoothCubicCurve (Position, Parameters)
 8 = EllipticalArc (Position, Parameters)
 99 = Close

 position
 0 = Absolute
 1 = Relative
 99 = Nothing
 */
#[repr(C)]
#[derive(Debug)]
pub struct SvgCommand {
    pub command: c_int,
    pub position: c_int,
    pub point: *const c_float,
    pub point_size: c_int
}

#[repr(C)]
#[derive(Debug)]
pub struct SvgDataCommand {
    pub svg_command: *const SvgCommand,
    pub size: c_int,
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

    let closure = |command: c_int, pos: &Position, param: &Parameters| -> SvgCommand {
        let position = match pos {
            Position::Absolute => {
                0
            }
            Position::Relative => {
                1
            }
        };
        let mut vec_point: Vec<c_float> = Vec::new();
        let point_size: c_int = param.len() as c_int;
        for i in 0..point_size as usize {
            vec_point.push(param[i])
        };
        let vec_point_slice = vec_point.as_slice();
        let point: *const c_float = vec_point_slice.as_ptr();
        SvgCommand {
            command,
            position,
            point,
            point_size
        }
    };

    for x in data.iter().as_slice() {
        let svg_command = match x {
            Command::Move(pos, param) => {
                closure(0, pos, param)
            }
            Command::Line(pos, param) => {
                closure(1, pos, param)
            }
            Command::HorizontalLine(pos, param) => {
                closure(2, pos, param)
            }
            Command::VerticalLine(pos, param) => {
                closure(3, pos, param)
            }
            Command::QuadraticCurve(pos, param) => {
                closure(4, pos, param)
            }
            Command::SmoothQuadraticCurve(pos, param) => {
                closure(5, pos, param)
            }
            Command::CubicCurve(pos, param) => {
                closure(6, pos, param)
            }
            Command::SmoothCubicCurve(pos, param) => {
                closure(7, pos, param)
            }
            Command::EllipticalArc(pos, param) => {
                closure(8, pos, param)
            },
            Command::Close => {
                let vec_point: Vec<c_float> = Vec::new();
                let vec_point_slice = vec_point.as_slice();
                let point: *const c_float = vec_point_slice.as_ptr();
                SvgCommand {
                    command: 99,
                    position: 99,
                    point,
                    point_size: 0,
                }
            }
        };
        vec.push(svg_command);
        //println!("{:?}", &x);
    }
    //println!("{:?}", &vec);
    let size_usize = vec.len();
    let size: c_int = size_usize as c_int;
    let svg_command_slice = vec.as_slice();
    let svg_command: *const SvgCommand = svg_command_slice.as_ptr();

    let cmd = SvgDataCommand {
        svg_command,
        size
    };
    //println!("{:?}", &cmd);

    let svg_command_extract = unsafe { cmd.svg_command.offset(1).as_ref().unwrap() };
    println!("{:?}", svg_command_extract);

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