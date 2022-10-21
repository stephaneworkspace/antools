struct SvgData {
    char data;
    int point_idx;
    int point_size;
};

struct SvgPoint {
    int point_idx;
    float point;
};

struct SvgFill {
    const char* fill;
};

struct SvgStroke {
    const char* stroke;
    float stroke_width;
};

struct SvgProperties {
    SvgFill fill;
    SvgStroke stroke;
};
