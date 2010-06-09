module Quarry
  class MGRS
    attr_accessor :grid
    def initialize(grid)
      @grid = grid.to_s
    end
  end
end
