# define RAD_TO_DEG 57.29577951308232087 /* 180/PI */

VALUE mgrs_init(VALUE klass, VALUE grid) {
  rb_iv_set(klass, "@grid", grid);
  return Qnil;
}

VALUE mgrs_to_lat_long(VALUE klass) {
  VALUE grid = rb_iv_get(klass, "@grid");

  double lat;
  double lng;
  char* grd = StringValuePtr(grid);

  Convert_MGRS_To_Geodetic (grd, &lat, &lng);

  VALUE ary = rb_ary_new();
  rb_ary_push(ary, rb_float_new(lat*RAD_TO_DEG));
  rb_ary_push(ary, rb_float_new(lng*RAD_TO_DEG));
  return ary;
}
