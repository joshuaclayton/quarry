When %{I convert the MGRS "$grid"} do |grid|
  @latitude, @longitude = Quarry::MGRS.new(grid).to_lat_lng
end

Then %{I should be near "$city"} do |city|
  target              = @geocoder.locate(city)
  converted_from_mgrs = @geocoder.locate(%{#{@latitude}, #{@longitude}})

  (0..0.5).should include(target.distance_to(converted_from_mgrs))
end

Then %{I should have the following result:} do |table|
  table.hashes.first["latitude"].should == @latitude.to_s
  table.hashes.first["longitude"].should == @longitude.to_s
end
