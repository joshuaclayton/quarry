module Quarry
  class LatLng
    attr_accessor :latitude, :longitude
    def initialize(lat_lng)
      @latitude = lat_lng.shift.to_f
      @longitude = lat_lng.shift.to_f
    end
  end
end
