#ifndef QUARRY_H
#define QUARRY_H
#define RAD_TO_DEG 57.29577951308232087 /* 180/PI */
#define DEG_TO_RAD 0.0174532925199433 /* PI/180 */

static VALUE mgrs_to_lat_long(VALUE);
static VALUE lat_long_to_mgrs(VALUE);

#endif
