struct B64 {
    const char* b_64;
    bool sw;
    const char* err;
};

extern "C" B64 create_png_b64(const char* p_svg_b64);
extern "C" B64 create_png_from_file(const char* svg_file);
extern "C" B64 create_pdf_b64(const char* p_svg_b64);
extern "C" B64 create_pdf_b64_from_png_b64(const char* p_png_b64);
/*extern "C" const char* svg_path_data(const SvgData* data,
                                     const SvgPoint* point,
                                     int data_size,
                                     int point_size,
                                     SvgProperties properties);
extern "C" const char* svg_circle(float x, float y, float r, SvgProperties properties);
extern "C" const char* svg_line(float x1, float x2, float y1, float y2, SvgStroke stroke);
extern "C" const char* svg_image(float width, float height, float x, float y, const char* href);
extern "C" const char* svg_document(float width, float height, const char* content);
 */