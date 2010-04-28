# include "ruby.h"
# include "mgrs.h"
# define RAD_TO_DEG 57.29577951308232087 /* 180/PI */

static VALUE mgrs_init(VALUE klass, VALUE grid) {
  rb_iv_set(klass, "@grid", grid);
  return Qnil;
}

VALUE mgrs_to_lat_long(VALUE klass);
VALUE mgrs_to_lat_long(VALUE klass) {
  VALUE grid;
  grid = rb_iv_get(klass, "@grid");

  VALUE ary;
  double lat;
  double lng;
  char* grd = StringValuePtr(grid);

  Convert_MGRS_To_Geodetic (grd, &lat, &lng);

  ary = rb_ary_new();
  rb_ary_push(ary, rb_float_new(lat*RAD_TO_DEG));
  rb_ary_push(ary, rb_float_new(lng*RAD_TO_DEG));
  return ary;
}

static VALUE rb_mQuarry;
static VALUE rb_cMGRS;
void Init_quarry() {
  rb_mQuarry = rb_define_module("Quarry");
  rb_cMGRS = rb_define_class_under(rb_mQuarry, "MGRS", rb_cObject);

  rb_define_method(rb_cMGRS, "initialize", mgrs_init, 1);
  rb_define_method(rb_cMGRS, "to_lat_lng", mgrs_to_lat_long, 0);
}
