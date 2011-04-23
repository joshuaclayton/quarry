$LOAD_PATH.unshift(File.dirname(__FILE__) + '/../../lib')
require "quarry"
require "rspec/expectations"
require "graticule"

Before do
  @geocoder = Graticule.service(:google).new("")
end
