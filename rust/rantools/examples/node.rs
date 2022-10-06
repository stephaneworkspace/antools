use std::{env, fmt};
use std::fs;
use std::path::PathBuf;
use std::str::FromStr;

// any error type implementing Display is acceptable.
type ParseError = &'static str;

fn main() {
    node_to_pdf().expect("Impossible de lire le fichier");
}

#[derive(Debug)]
pub struct NodeElement {
    pub node: NodeEnum,
    pub child: Vec<NodeEnum>
}

pub enum NodeEnum {
    Table(Vec<AttrEnum>),
    Tr(Vec<AttrEnum>),
    Td(Vec<AttrEnum>),
    Div(Vec<AttrEnum>),
    Unknow
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
            },
            NodeEnum::Unknow => {
                "?".to_string()
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
            NodeEnum::Unknow => {
                format!("{}", self.text())
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

impl FromStr for NodeEnum {
    type Err = ParseError;
    fn from_str(attr: &str) -> Result<Self, Self::Err> {
        match attr {
            "table" => Ok(Self::Table(vec![])),
            "tr" => Ok(Self::Tr(vec![])),
            "td" => Ok(Self::Td(vec![])),
            "div" => Ok(Self::Div(vec![])),
            _ => Err("Could not parse a node"),
        }
    }
}

pub enum AttrEnum {
    Width(i32),
    Height(i32),
    Border(i32),
    Align(AlignEnum),
    Text(String)
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

impl FromStr for AttrEnum {
    type Err = ParseError;
    fn from_str(attr: &str) -> Result<Self, Self::Err> {
        match attr {
            "width" => Ok(Self::Width(0)),
            "height" => Ok(Self::Height(0)),
            "border" => Ok(Self::Border(0)),
            "align" => Ok(Self::Align(AlignEnum::Left)),
            "text" => Ok(Self::Text("".to_string())),
            _ => Err("Could not parse a attribute"),
        }
    }
}

pub enum AlignEnum {
    Left,
    Center,
    Right
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

    let mut vec_node_element: Vec<NodeElement> = Vec::new();
    for a in doc.root().children().filter(|n| n.is_element()) {
        //let mut vec_node: Vec<NodeEnum> = Vec::new();
        let mut node_element = NodeElement {
            node: NodeEnum::Unknow,
            child: vec![]
        };
        print!("{:?} {:?} {:?} {:?}\n", a, a.has_children(), a.text(), a.tag_name());
        match a.tag_name().name() {
            "table" => {
                let mut vec_attr: Vec<AttrEnum> = Vec::new();
                for a_attr in a.attributes() {
                    let attr_result = AttrEnum::from_str(a_attr.name());
                    match attr_result {
                        Ok(ok) => {
                            match ok {
                                AttrEnum::Width(_) => {
                                    let value:i32 = a_attr.value().parse().unwrap_or(0);
                                    vec_attr.push(AttrEnum::Width(value))
                                }
                                AttrEnum::Height(_) => {
                                    let value:i32 = a_attr.value().parse().unwrap_or(0);
                                    vec_attr.push(AttrEnum::Height(value))
                                }
                                AttrEnum::Border(_) => {
                                    let value:i32 = a_attr.value().parse().unwrap_or(0);
                                    vec_attr.push(AttrEnum::Border(value))
                                }
                                AttrEnum::Align(_) => {

                                }
                                AttrEnum::Text(_) => {
                                    vec_attr.push(AttrEnum::Text(a_attr.value().parse().unwrap_or("".to_string())))
                                }
                            }
                        },
                        Err(err) => {
                            eprintln!("{:?}", err)
                        }
                    }
                }
                match NodeEnum::from_str("table") {
                    Ok(ok) => {
                        match ok {
                            NodeEnum::Table(_) => {
                                node_element.node = NodeEnum::Table(vec_attr);
                                vec_node_element.push(node_element);
                            }
                            NodeEnum::Tr(_) => {
                                node_element.node = NodeEnum::Tr(vec_attr);
                                vec_node_element.push(node_element);
                            }
                            NodeEnum::Td(_) => {
                                node_element.node = NodeEnum::Td(vec_attr);
                                vec_node_element.push(node_element);
                            }
                            NodeEnum::Div(_) => {
                                node_element.node = NodeEnum::Div(vec_attr);
                                vec_node_element.push(node_element);
                            }
                            NodeEnum::Unknow => {
                                unreachable!()
                            }
                        }
                    },
                    Err(err) => {
                        eprintln!("{:?}", err)
                    }
                }
                /*
                let node_element = NodeElement {
                    node: vec_node.into_iter().map(|x| {
                        match x {
                            NodeEnum::Table(content) => {
                                NodeEnum::Table(content.into_iter().collect())
                            }
                            NodeEnum::Tr(content) => {
                                NodeEnum::Tr(content.into_iter().collect())
                            }
                            NodeEnum::Td(content) => {
                                NodeEnum::Td(content.into_iter().collect())
                            }
                            NodeEnum::Div(content) => {
                                NodeEnum::Div(content.into_iter().collect())
                            }
                        }
                    }).collect(),
                    child: vec![]
                };*/
            },
            _ => {

            }
        }
        //if a.has_children() {
        //    closure_children(a);
        //}
    }

    println!("{:?}", vec_node_element);

    Ok(())
}
