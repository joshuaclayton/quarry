# define RAD_TO_DEG 57.29577951308232087 /* 180/PI */
# define DEG_TO_RAD 0.0174532925199433 /* PI/180 */

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

VALUE lat_long_to_mgrs(VALUE klass) {
  VALUE iv_latitude  = rb_funcall(rb_iv_get(klass, "@latitude" ), rb_intern("to_s"), 0);
  VALUE iv_longitude = rb_funcall(rb_iv_get(klass, "@longitude"), rb_intern("to_s"), 0);

  double latitude =  rb_str_to_dbl(iv_latitude,  Qfalse);
  double longitude = rb_str_to_dbl(iv_longitude, Qfalse);

  char grid[15];
  Convert_Geodetic_To_MGRS(latitude*DEG_TO_RAD, longitude*DEG_TO_RAD, 5, grid);

  return rb_str_new2(grid);
}
