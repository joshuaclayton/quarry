When %{I convert the MGRS "$grid"} do |grid|
  @result = Quarry::MGRS.new(grid).to_lat_lng
end

Then %{I should have the following result:} do |table|
  row = table.rows_hash
  row["latitude"].should == @result[0].to_s
  row["longitude"].should == @result[1].to_s
end
