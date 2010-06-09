# include "ruby.h"
# include "mgrs.h"
# include "quarry.h"

void Init_quarry() {
  VALUE rb_mQuarry = rb_define_module("Quarry");

  VALUE rb_cMGRS = rb_define_class_under(rb_mQuarry, "MGRS", rb_cObject);
  rb_define_method(rb_cMGRS, "initialize", mgrs_init, 1);
  rb_define_method(rb_cMGRS, "to_lat_lng", mgrs_to_lat_long, 0);

  VALUE rb_cLatLng = rb_define_class_under(rb_mQuarry, "LatLng", rb_cObject);
  rb_define_method(rb_cLatLng, "initialize", lat_long_init, 1);
  rb_define_method(rb_cLatLng, "to_mgrs", lat_long_to_mgrs, 0);
}
