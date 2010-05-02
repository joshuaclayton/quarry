# Quarry
## Dig in to location conversion

## Install

Install with Rubygems:

    gem install quarry

If you're using quarry in a Rails app, be sure *not* to vendor it, since it'll need to be built on each system.

## Usage

Currently, Quarry only supports converting from MGRS to latitude and longitude.

    Quarry::MGRS.new("10SEG5112981002").to_lat_lng # [37.7749282053078, -122.41941986071]

## Geotrans

This software wouldn't be possible without [Geotrans](http://earth-info.nga.mil/GandG/geotrans/).
The product was developed using GEOTRANS, a product of the National Geospatial-Intelligence Agency (NGA) and U.S. Army Engineering Research and Development Center.

## Author

Written by Josh Clayton, although most of the actual work is part of Geotrans.
