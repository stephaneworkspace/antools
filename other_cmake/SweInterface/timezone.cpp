//
// Created by Stéphane on 22.09.22.
//
#include "timezone.h"

TimeZone TZ::utc_time_zone(TimeZone time_zone, double timezone) {
    int* year_ptr = new int[2];
    int* month_ptr = new int[2];
    int* day_ptr = new int[2];
    int* hour_ptr = new int[2];
    int* min_ptr = new int[2];
    double* sec_ptr = new double[2];
    int year;
    int month;
    int day;
    int hour;
    int min;
    double sec;
    swe_utc_time_zone(time_zone.year,
                      time_zone.month,
                      time_zone.day,
                      time_zone.hour,
                      time_zone.min,
                      time_zone.sec,
                      timezone,
                      year_ptr,
                      month_ptr,
                      day_ptr,
                      hour_ptr,
                      min_ptr,
                      sec_ptr);
    TimeZone tz;
    tz.year = year_ptr[0];
    tz.month = month_ptr[0];
    tz.day = day_ptr[0];
    tz.hour = hour_ptr[0];
    tz.min = min_ptr[0];
    tz.sec = sec_ptr[0];
    free(year_ptr);
    free(month_ptr);
    free(day_ptr);
    free(hour_ptr);
    free(min_ptr);
    free(sec_ptr);
    return tz;
}

