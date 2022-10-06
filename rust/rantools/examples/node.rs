use std::{env, fmt};
use std::fs;
use std::path::PathBuf;

fn main() {
    node_to_pdf().expect("Impossible de lire le fichier");
}

pub enum AttrEnum {
    Width(i32),
    Height(i32),
    Border(i32),
    Align(AlignEnum),
    Text(String)
}

pub enum AlignEnum {
    Left,
    Center,
    Right
}

pub enum NodeEnum {
    Table(Vec<AttrEnum>),
    Tr(Vec<AttrEnum>),
    Td(Vec<AttrEnum>),
    Div(Vec<AttrEnum>,)
}

#[derive(Debug)]
pub struct NodeElement {
    pub node: NodeEnum,
    pub child: Vec<NodeEnum>
}

impl NodeEnum {
    fn text(&self) -> String {
        match self {
            NodeEnum::Table(_) => {
                "table".to_string()
            }
            NodeEnum::Tr(_) => {
                "tr".to_string()
            }
            NodeEnum::Td(_) => {
                "td".to_string()
            }
            NodeEnum::Div(_) => {
                "div".to_string()
            }
        }
    }
    fn debug(&self) -> String {
        match self {
            NodeEnum::Table(content) => {
                format!("{}, {:?}", self.text(), content)
            }
            NodeEnum::Tr(content) => {
                format!("{}, {:?}", self.text(), content)
            }
            NodeEnum::Td(content) => {
                format!("{}, {:?}", self.text(), content)
            }
            NodeEnum::Div(content) => {
                format!("{}, {:?}", self.text(), content)
            }
        }
    }
}

impl fmt::Display for NodeEnum {
    #[inline]
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        fmt::Display::fmt(&self.text(), f)
    }
}

impl fmt::Debug for NodeEnum {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{}", &self.debug().to_string())
    }
}

impl AttrEnum {
    fn text(&self) -> String {
        match self {
            AttrEnum::Width(_) => {
                "width".to_string()
            }
            AttrEnum::Height(_) => {
                "height".to_string()
            }
            AttrEnum::Border(_) => {
                "border".to_string()
            }
            AttrEnum::Align(_) => {
                "div".to_string()
            }
            AttrEnum::Text(_) => {
                "text".to_string()
            }
        }
    }
    fn debug(&self) -> String {
        match self {
            AttrEnum::Width(content) => {
                format!("{}, {:?}", self.text(), content)
            }
            AttrEnum::Height(content) => {
                format!("{}, {:?}", self.text(), content)
            }
            AttrEnum::Border(content) => {
                format!("{}, {:?}", self.text(), content)
            }
            AttrEnum::Align(content) => {
                format!("{}, {:?}", self.text(), content)
            }
            AttrEnum::Text(content) => {
                format!("{}, {:?}", self.text(), content)
            }
        }
    }
}

impl fmt::Display for AttrEnum {
    #[inline]
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        fmt::Display::fmt(&self.text(), f)
    }
}

impl fmt::Debug for AttrEnum {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{}", &self.debug().to_string())
    }
}

impl AlignEnum {
    fn text(&self) -> String {
        match self {
            AlignEnum::Left => {
                "left".to_string()
            }
            AlignEnum::Center => {
                "center".to_string()
            }
            AlignEnum::Right => {
                "right".to_string()
            }
        }
    }
}

impl fmt::Display for AlignEnum {
    #[inline]
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        fmt::Display::fmt(&self.text(), f)
    }
}

impl fmt::Debug for AlignEnum {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{}", &self.text().to_string())
    }
}

pub(crate) fn node_to_pdf() -> Result<(), String> {
    /*struct Fact<'s> { f: &'s dyn Fn(&Fact, u32) -> u32 }
    let fact = Fact {
        f: &|fact, x| if x == 0 {1} else {x * (fact.f)(fact, x - 1)}
    };
    fn closure_children<'a>(x: Node) -> Vec<NodeElement> {
        let mut vec_node_children: Vec<NodeElement> = Vec::new();
        for a in x.children().filter(|n| n.is_element()) {
            print!("{:?} {:?}\n", a, a.has_children());
            /*if a.has_children() {
                closure_children(a);
            } else {
            }*/
            vec_node_children.push()
        }
    }*/
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


    let mut vec_node: Vec<NodeEnum> = Vec::new();
    for a in doc.root().children().filter(|n| n.is_element()) {
        print!("{:?} {:?} {:?} {:?}\n", a, a.has_children(), a.text(), a.tag_name());
        match a.tag_name().name() {
            "table" => {
                vec_node.push(NodeEnum::Table(Vec::new()))
            },
            _ => {

            }
        }
        //if a.has_children() {
        //    closure_children(a);
        //}
    }

    println!("{:?}", vec_node);

    Ok(())
}
