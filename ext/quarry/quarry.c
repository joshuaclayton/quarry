#include <ruby.h>
#include "quarry.h"
#include "mgrs.h"

void Init_quarry() {
  VALUE rb_mQuarry = rb_define_module("Quarry");

  VALUE rb_cMGRS = rb_define_class_under(rb_mQuarry, "MGRS", rb_cObject);
  rb_define_method(rb_cMGRS, "to_lat_lng", mgrs_to_lat_long, 0);

  VALUE rb_cLatLng = rb_define_class_under(rb_mQuarry, "LatLng", rb_cObject);
  rb_define_method(rb_cLatLng, "to_mgrs", lat_long_to_mgrs, 0);
}

static VALUE mgrs_to_lat_long(VALUE klass) {
  VALUE iv_grid = rb_iv_get(klass, "@grid");
  char* grid = StringValuePtr(iv_grid);
  double lat, lng;

  Convert_MGRS_To_Geodetic(grid, &lat, &lng);

  VALUE lat_lng_array = rb_ary_new();
  rb_ary_push(lat_lng_array, rb_float_new(lat*RAD_TO_DEG));
  rb_ary_push(lat_lng_array, rb_float_new(lng*RAD_TO_DEG));
  return lat_lng_array;
}

static VALUE lat_long_to_mgrs(VALUE klass) {
  VALUE iv_latitude  = rb_iv_get(klass, "@latitude"),
        iv_longitude = rb_iv_get(klass, "@longitude");
  double latitude  = rb_num2dbl(iv_latitude),
         longitude = rb_num2dbl(iv_longitude);

  char grid[16];
  Convert_Geodetic_To_MGRS(latitude*DEG_TO_RAD, longitude*DEG_TO_RAD, 5, grid);

  return rb_str_new2(grid);
}
