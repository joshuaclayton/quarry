# define RAD_TO_DEG 57.29577951308232087 /* 180/PI */
# define DEG_TO_RAD 0.0174532925199433 /* PI/180 */

VALUE mgrs_to_lat_long(VALUE klass) {
  VALUE mgrs_grid = rb_iv_get(klass, "@grid");
  char* grid = StringValuePtr(mgrs_grid);

  double lat, lng;

  Convert_MGRS_To_Geodetic(grid, &lat, &lng);

  VALUE lat_lng_array = rb_ary_new();
  rb_ary_push(lat_lng_array, rb_float_new(lat*RAD_TO_DEG));
  rb_ary_push(lat_lng_array, rb_float_new(lng*RAD_TO_DEG));
  return lat_lng_array;
}

VALUE lat_long_to_mgrs(VALUE klass) {
  VALUE iv_latitude  = rb_funcall(rb_iv_get(klass, "@latitude" ), rb_intern("to_s"), 0),
        iv_longitude = rb_funcall(rb_iv_get(klass, "@longitude"), rb_intern("to_s"), 0);

  double latitude  = rb_str_to_dbl(iv_latitude,  Qfalse),
         longitude = rb_str_to_dbl(iv_longitude, Qfalse);

  char grid[15];
  Convert_Geodetic_To_MGRS(latitude*DEG_TO_RAD, longitude*DEG_TO_RAD, 5, grid);

  return rb_str_new2(grid);
}
