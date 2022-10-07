use printpdf::*;
use std::fs::File;
use std::io::BufWriter;
use std::iter::FromIterator;

//use pdf_writer::types::{ActionType, BorderType};
//use pdf_writer::{Content, Finish, Name, PdfWriter, Rect, Ref, Str, TextStr};
use crate::node::NodeElement;

// Set the size to A4
const MAX_WIDTH: f64 = 595.0;
const MAX_HEIGHT: f64 = 842.0;
const MARGIN_WIDTH: f64 = 90.0;
const MARGIN_HEIGHT: f64 = 90.0;
const TR_HEIGHT:f64 = 18.0;

pub fn create_pdf(_template: &[NodeElement]) {
    let (doc, page1, layer1) = PdfDocument::new("printpdf graphics test", Mm(MAX_WIDTH), Mm(MAX_HEIGHT), "Layer 1");
    let current_layer = doc.get_page(page1).get_layer(layer1);

    let current_y = MAX_HEIGHT - MARGIN_HEIGHT;
// Quadratic shape. The "false" determines if the next (following)
// point is a bezier handle (for curves)
// If you want holes, simply reorder the winding of the points to be
// counterclockwise instead of clockwise.
    let points1 = vec![(Point::new(Mm(MARGIN_WIDTH), Mm(current_y)), false),
                       (Point::new(Mm(MARGIN_WIDTH), Mm(current_y + TR_HEIGHT)), false),
                       (Point::new(Mm(MAX_WIDTH - MARGIN_WIDTH), Mm(current_y + TR_HEIGHT)), false),
                       (Point::new(Mm(MAX_WIDTH - MARGIN_WIDTH), Mm(current_y)), false)];

// Is the shape stroked? Is the shape closed? Is the shape filled?
    let line1 = Line {
        points: points1,
        is_closed: true,
        has_fill: true,
        has_stroke: true,
        is_clipping_path: false,
    };

// Triangle shape
// Note: Line is invisible by default, the previous method of
// constructing a line is recommended!
    let mut line2 = Line::from_iter(vec![
        (Point::new(Mm(150.0), Mm(150.0)), false),
        (Point::new(Mm(150.0), Mm(250.0)), false),
        (Point::new(Mm(300.0), Mm(250.0)), false)]);

    line2.set_stroke(true);
    line2.set_closed(false);
    line2.set_fill(false);
    line2.set_as_clipping_path(false);

    let fill_color = Color::Cmyk(Cmyk::new(0.0, 0.23, 0.0, 0.0, None));
    let outline_color = Color::Rgb(Rgb::new(0.75, 1.0, 0.64, None));
    let mut dash_pattern = LineDashPattern::default();
    dash_pattern.dash_1 = Some(20);

    current_layer.set_fill_color(fill_color);
    current_layer.set_outline_color(outline_color);
    current_layer.set_outline_thickness(10.0);

// Draw first line
    current_layer.add_shape(line1);

    let fill_color_2 = Color::Cmyk(Cmyk::new(0.0, 0.0, 0.0, 0.0, None));
    let outline_color_2 = Color::Greyscale(Greyscale::new(0.45, None));

// More advanced graphical options
    current_layer.set_overprint_stroke(true);
    current_layer.set_blend_mode(BlendMode::Seperable(SeperableBlendMode::Multiply));
    current_layer.set_line_dash_pattern(dash_pattern);
    current_layer.set_line_cap_style(LineCapStyle::Round);

    current_layer.set_fill_color(fill_color_2);
    current_layer.set_outline_color(outline_color_2);
    current_layer.set_outline_thickness(15.0);

// draw second line
    current_layer.add_shape(line2);
    doc.save(&mut BufWriter::new(File::create("target/hello.pdf").unwrap())).unwrap();
}