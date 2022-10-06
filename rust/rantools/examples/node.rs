use std::env;
use std::fs;
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

pub(crate) fn node_to_pdf() -> Result<(), String> {
    let mut file_path = PathBuf::new();
    file_path.push(env::current_dir().unwrap().as_path());
    file_path.push("examples");
    file_path.push("template.an");

    let text = fs::read_to_string(file_path.clone()).unwrap();
/*
    let doc = roxmltree::Document::parse(&text).unwrap();

    println!("Elements count: {}",
             doc.root().descendants().filter(|n| n.is_element()).count());

    let attrs_count: usize = doc.root().descendants().map(|n| n.attributes().len()).sum();
    println!("Attributes count: {}", attrs_count);

    let ns_count: usize = doc.root().descendants().map(|n| n.namespaces().len()).sum();
*/
    // Allow DTD for this example.
    let opt = roxmltree::ParsingOptions {
        allow_dtd: true,
    };

    let doc = match roxmltree::Document::parse_with_options(&text, opt) {
        Ok(doc) => {
            //print!("{:?}", &doc);
            doc
        },
        Err(e) => return Err(format!("Error: {}.", e).to_string()),
    };

    let _vec_node: Vec<Node> = Vec::new();
    for x in doc.root().descendants().filter(|n| n.is_element()) {
        print!("{:?}", x);
    }

    Ok(())
}
