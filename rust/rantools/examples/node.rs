use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};
use std::path::PathBuf;

fn main() {
    node_to_pdf().expect("Impossible de lire le fichier");
}

pub enum Attr {
    Width(i32),
    Height(i32),
    Border(i32),
    Align(Align),
    Text(String)
}

pub enum Align {
    Left,
    Center,
    Right
}

pub enum Node {
    Table(Vec<Attr>),
    Tr(Vec<Attr>),
    Td(Vec<Attr>),
    Div(Vec<Attr>,)
}

pub(crate) fn node_to_pdf() -> std::io::Result<()> {

    let mut file_path = PathBuf::new();
    file_path.push(env::current_dir().unwrap().as_path());
    file_path.push("examples");
    file_path.push("template.an");
    let file = File::open(file_path.as_path())?;
    let reader = BufReader::new(&file);
    let mut template: String = "".to_string();
    for l in reader.lines() {
        template = format!("{}{}", template, l.unwrap());
    }
    println!("{}", template);
    Ok(())
}
