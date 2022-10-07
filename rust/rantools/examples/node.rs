use std::env;
use std::path::PathBuf;
use rantools::read_template;

fn main() {
    let mut file_path = PathBuf::new();
    file_path.push(env::current_dir().unwrap().as_path());
    file_path.push("examples");
    file_path.push("template.an");

    println!("{:?}", read_template(file_path.to_str().unwrap().to_string()));
}




