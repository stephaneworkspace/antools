extern crate core;

use std::ffi::{CStr, CString};
use std::os::raw::{c_char, c_float, c_int};
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

 */
#[repr(C)]
#[derive(Debug)]
pub struct SvgCommand {
    pub command: c_char,
    pub point: *const i32,
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

    let closure = |c: char, param: &Parameters| -> SvgCommand {
        let mut vec_point: Vec<i32> = Vec::new();
        let point_size: c_int = param.len() as c_int;
        for i in 0..point_size as usize {
            vec_point.push(param[i] as i32)
        };
        let vec_point_slice = vec_point.as_slice();
        let point: *const i32 = vec_point_slice.as_ptr();
        SvgCommand {
            command: c as c_char,
            point,
            point_size
        }
    };

    for x in data.iter().as_slice() {
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
                closure(c, param)
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
                closure(c, param)
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
                closure(c, param)
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
                closure(c, param)
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
                closure(c, param)
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
                closure(c, param)
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
                closure(c, param)
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
                closure(c, param)
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
                closure(c, param)
            },
            Command::Close => {
                let vec_point: Vec<i32> = Vec::new();
                let vec_point_slice = vec_point.as_slice();
                let point: *const i32 = vec_point_slice.as_ptr();
                SvgCommand {
                    command: 'Z' as c_char,
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

    let svg_command_extract = unsafe { cmd.svg_command.offset(0).as_ref().unwrap() };
    for i in 0..svg_command_extract.point_size as isize {
        let point = unsafe { svg_command_extract.point.offset(i).as_ref() }.unwrap();
        println!("{}", point);
    }
    let c = svg_command_extract.command;
    let cstr = char::from_u32(c as u32).unwrap();
    println!("{:?} - {}", &svg_command_extract, cstr);
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