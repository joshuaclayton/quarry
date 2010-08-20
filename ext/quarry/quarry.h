# include "mgrs.h"

#ifndef __quarry_h__
#define __quarry_h__

# define RAD_TO_DEG 57.29577951308232087 /* 180/PI */
# define DEG_TO_RAD 0.0174532925199433 /* PI/180 */

VALUE mgrs_to_lat_long(VALUE);
VALUE lat_long_to_mgrs(VALUE);

#endif
