//
// Created by Stéphane on 01.10.22.
//

#include "SweInterface.h"
#include "base64.h"
#include "draw.h"
#include "draw_aspect_line.h"
#include "draw_bodie_astre.h"
#include "draw_bodie_line.h"
#include "draw_house_angle.h"
#include "draw_house_line.h"
#include "draw_house_number.h"
#include "draw_zodiac_circle.h"
#include "draw_zodiac_line.h"
#include "draw_zodiac_sign.h"
#include "timezone.h"
#include "swe08.h"
#include "swe14.h"

const char* theme_astral_svg(int year, int month, int day, int hour, int min, double lat, double lng, int gmt, const char* ephem_path) {
    // Charger le path des ephem, depuis swift il est a préciser, sinon ça utilise de ce répertoire
    string ephem_path_string;
    if (strcmp(ephem_path, "") == 0) {
        //TODO ephem_path_string = filesystem::current_path().parent_path().parent_path();
        ephem_path_string += "/ephem";
    } else {
        ephem_path_string = ephem_path;
    }
    Swe02::set_ephe_path(ephem_path_string);

    // TimeZone
    TimeZone time_zone;
    time_zone.year = year;
    time_zone.month = month;
    time_zone.day = day;
    time_zone.hour = hour;
    time_zone.min = min;
    time_zone.sec = 0;
    TimeZone utc_time_zone = TZ::utc_time_zone(time_zone, gmt);
    UtcToJd utc_to_jd = Swe08::utc_to_jd(utc_time_zone, Calandar::gregorian);
    time_t t = time(0);
    tm* now = localtime(&t);
    TimeZone time_zone_t;
    time_zone_t.year = now->tm_year + 1900;
    time_zone_t.month = now->tm_mon + 1;
    time_zone_t.day = now->tm_mday;
    time_zone_t.hour = now->tm_hour;
    time_zone_t.min = now->tm_min;
    time_zone_t.sec = now->tm_sec;
    double gmt_t = gmt;
    TimeZone utc_time_zone_t = TZ::utc_time_zone(time_zone_t, gmt_t);
    UtcToJd utc_to_jd_t = Swe08::utc_to_jd(utc_time_zone_t, Calandar::gregorian);

    H* house = new H[12];
    for (int i = 0; i < 12; ++i) {
        house[i] = Swe14::house(utc_to_jd.julian_day_ut, lat, lng, 'P', i + 1);
    }

    Astres* astres = new Astres[11];
    astres[0] = Astres::soleil;
    astres[1] = Astres::lune;
    astres[2] = Astres::mercure;
    astres[3] = Astres::venus;
    astres[4] = Astres::mars;
    astres[5] = Astres::jupiter;
    astres[6] = Astres::saturn;
    astres[7] = Astres::uranus;
    astres[8] = Astres::neptune;
    astres[9] = Astres::pluto;
    astres[10] = Astres::noeud_lunaire;

    Dimensions dimensions(CHART_SIZE, CHART_SIZE);
    Document doc("mysvg.svg", Layout(dimensions, Layout::BottomLeft));

    // Draw circles natal
    DrawCircle dz;
    for (int i = 0; i <= 8; ++i) {
        CircleZod cz = dz.circle(static_cast<circle_position>(i));
        if (cz.sw) {
            doc << Circle(Point(CHART_SIZE / 2, CHART_SIZE / 2), cz.radius_multiplier, Fill(Color::Transparent), Stroke(1, Color::Black));
        }
    }

    // Draw house lines
    DrawHouseLines dhl;
    LineXY3* lxy3 = dhl.lines(house);
    for (int i = 0; i < 12; ++i) {
        if (!lxy3[i].sw_lxy3) {
            double stroke;
            if (i == 3 || i == 6 || i == 9) {
            } else {
                doc << Line(Point(lxy3[i].lx1, lxy3[i].ly1), Point(lxy3[i].lx2, lxy3[i].ly2), Stroke(1, Color::Black));
            }
        } else {
            Path triangle(Fill(Color::Black), Stroke(1, Color::Black));
            triangle << Point(lxy3[i].lx3, lxy3[i].ly3) << Point(lxy3[i].lx2, lxy3[i].ly2)
                     << Point(lxy3[i].lx2, lxy3[i].ly1); // ceci est du bricolage, ça fonctionne que a angle droit
            doc << triangle;
            /*
            triangle << Point(lxy3[i].lx3, lxy3[i].ly3) << Point(lxy3[i].lx2, lxy3[i].ly2)
                     << Point(lxy3[i].lx1, lxy3[i].ly1);
            doc << triangle;*/
        }
    }

    // Angle line
    LineXY lxy;
    lxy = dhl.angle_lines(house, Angles::asc);
    doc << Line(Point(lxy.lx1, lxy.ly1), Point(lxy.lx2, lxy.ly2), Stroke(STROKE_BOLD, Color::Black));
    lxy = dhl.angle_lines(house, Angles::fc);
    doc << Line(Point(lxy.lx1, lxy.ly1), Point(lxy.lx2, lxy.ly2), Stroke(STROKE_BOLD, Color::Black));
    lxy = dhl.angle_lines(house, Angles::desc);
    doc << Line(Point(lxy.lx1, lxy.ly1), Point(lxy.lx2, lxy.ly2), Stroke(STROKE_BOLD, Color::Black));
    lxy = dhl.angle_lines(house, Angles::mc);
    doc << Line(Point(lxy.lx1, lxy.ly1), Point(lxy.lx2, lxy.ly2), Stroke(STROKE_BOLD, Color::Black));

    // Draw house number image
    House house_number;
    double house_size;
    for (int i = 1; i < 13; ++i) {
        Offset offset;
        house_size = DrawHouseNumber::number_size();
        offset = DrawHouseNumber::number(i, house);
        doc << house_number.generer(i, offset.x, offset.y, house_size, house_size);
    }

    // Draw house angle image
    Angle house_angle;
    double angle_size = DrawHouseAngle::angle_size();
    Offset offset;
    // Asc
    offset = DrawHouseAngle::angle(house, Angles::asc);
    doc << house_angle.generer(Angles::asc, offset.x, offset.y, angle_size, angle_size);
    offset = DrawHouseAngle::angle(house, Angles::fc);
    doc << house_angle.generer(Angles::fc, offset.x, offset.y, angle_size, angle_size);
    offset = DrawHouseAngle::angle(house, Angles::desc);
    doc << house_angle.generer(Angles::desc, offset.x, offset.y, angle_size, angle_size);
    offset = DrawHouseAngle::angle(house, Angles::mc);
    doc << house_angle.generer(Angles::mc, offset.x, offset.y, angle_size, angle_size);

    // Draw zodiac lines
    DrawZodiacLines dzl;
    LineXY* lz = dzl.line(house[0]);
    for (int i = 0; i < (16 * 12); ++i) {
        doc << Line(Point(lz[i].lx1, lz[i].ly1), Point(lz[i].lx2, lz[i].ly2), Stroke(1, Color::Black));
    }

    // Draw zodiac image
    Sign sign;
    double zodiac_size;
    for (int i = 1; i < 13; ++i) {
        Offset offset;
        zodiac_size = DrawZodiacSign::zodiac_size();
        offset = DrawZodiacSign::zodiac_sign(static_cast<Signs>(i), house[0]);
        doc << sign.generer(static_cast<Signs>(i), offset.x, offset.y, zodiac_size, zodiac_size);
    }

    // Draw astre image
    Astre astre;
    double astre_size;
    astre_size = DrawBodieAstre::astre_size();
    DrawBodieLines dbl;
    // LineXY lxy;
    for (int i = 0; i < 11; ++i) {
        Offset offset;
        // Natal
        CalcUt calcul_ut = Swe03::calc_ut(utc_to_jd.julian_day_ut, astres[i], OptionFlag::speed);
        offset = DrawBodieAstre::bodie_astre(house[0], calcul_ut, false);
        lxy = dbl.line(house[0], calcul_ut, false);
        doc << astre.generer(astres[i], offset.x, offset.y, astre_size, astre_size);
        doc << Line(Point(lxy.lx1, lxy.ly1), Point(lxy.lx2, lxy.ly2), Stroke(1, Color::Black));
        // Transit
        CalcUt calcul_ut_t = Swe03::calc_ut(utc_to_jd_t.julian_day_ut, astres[i], OptionFlag::speed);
        offset = DrawBodieAstre::bodie_astre(house[0], calcul_ut_t, true);
        lxy = dbl.line(house[0], calcul_ut_t, true);
        doc << astre.generer(astres[i], offset.x, offset.y, astre_size, astre_size);
        doc << Line(Point(lxy.lx1, lxy.ly1), Point(lxy.lx2, lxy.ly2), Stroke(1, Color::Black));
    }

    // Aspect
    const int MAX_ITEM = (11 * 2) + 2;
    double* item_longitude = new double[MAX_ITEM];
    for (int i = 0; i < 11; ++i) {
        item_longitude[i] = Swe03::calc_ut(utc_to_jd.julian_day_ut, astres[i], OptionFlag::speed).longitude;
    }
    for (int i = 1; i < 11; ++i) {
        //item_longitude[11 + i] = Swe03::calc_ut(utc_to_jd_t.julian_day_ut, astres[i], OptionFlag::speed).longitude;
    }
    item_longitude[(11 * 2) + 1] = house[0].longitude;
    item_longitude[(11 * 2) + 2] = house[9].longitude;

    CalcUt* c_ut = new CalcUt[2];
    const int MAX_PAIR = MAX_ITEM * (11 * 2);
    PairAspect* pair = new PairAspect[MAX_PAIR];
    int k = 0;
    int i = 0;
    for (int i = 0; i < MAX_ITEM; ++i) {
        for (int j = 0; j < (11 * 2); ++j) {
            bool swl = false;
            for (int l = 0; l < MAX_PAIR; ++l) {
                if (pair[l].i == j && pair[l].j == i) {
                    swl = true;
                }
            }
            if (i != j && !swl) {
                double *c_ut_longitude = new double[2];
                c_ut_longitude[0] = item_longitude[i];
                c_ut_longitude[1] = item_longitude[j];
                LineXYAspect lxya = DrawAspectLines::line(house[0], c_ut_longitude);
                if (lxya.sw) {
                    switch (lxya.aspect) {
                        case aspect::conjunction:
                            doc << Line(Point(lxya.lx1, lxya.ly1), Point(lxya.lx2, lxya.ly2),
                                        Stroke(STROKE_FINE,
                                               Color::Red));
                            break;
                        case aspect::opposition:
                            doc << Line(Point(lxya.lx1, lxya.ly1), Point(lxya.lx2, lxya.ly2),
                                        Stroke(STROKE_FINE,
                                               Color::Red));
                            break;
                        case aspect::trine:
                            doc << Line(Point(lxya.lx1, lxya.ly1), Point(lxya.lx2, lxya.ly2),
                                        Stroke(STROKE_FINE,
                                               Color::Blue));
                            break;
                        case aspect::square:
                            doc << Line(Point(lxya.lx1, lxya.ly1), Point(lxya.lx2, lxya.ly2),
                                        Stroke(STROKE_FINE,
                                               Color::Red));
                            break;
                        case aspect::sextile:
                            doc << Line(Point(lxya.lx1, lxya.ly1), Point(lxya.lx2, lxya.ly2),
                                        Stroke(STROKE_FINE,
                                               Color::Blue));
                            break;
                        case aspect::inconjunction:
                            doc << Line(Point(lxya.lx1, lxya.ly1), Point(lxya.lx2, lxya.ly2),
                                        Stroke(STROKE_FINE,
                                               Color::Green));
                            break;
                        case aspect::sequisquare:
                            doc << Line(Point(lxya.lx1, lxya.ly1), Point(lxya.lx2, lxya.ly2),
                                        Stroke(STROKE_FINE,
                                               Color::Purple));
                            break;
                        case aspect::semisquare:
                            doc << Line(Point(lxya.lx1, lxya.ly1), Point(lxya.lx2, lxya.ly2),
                                        Stroke(STROKE_FINE,
                                               Color::Purple));
                            break;
                        case aspect::semisextile:
                            doc << Line(Point(lxya.lx1, lxya.ly1), Point(lxya.lx2, lxya.ly2),
                                        Stroke(STROKE_FINE,
                                               Color::Green));
                            break;
                    }
                    PairAspect p;
                    p.i = i;
                    p.j = j;
                    pair[k] = p;
                    k++;
                }
            }
        }
    }

    static std::string encoded;
    if(!Base64::Encode(doc.toString(), &encoded)) {
        std::cout << "Failed to encode input string" << std::endl;
        //return false;
    }
    const char* chr = strdup(encoded.c_str());
    return chr;
}
