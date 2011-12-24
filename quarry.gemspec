# -*- encoding: utf-8 -*-
$:.push File.expand_path("../lib", __FILE__)
require "quarry/version"

Gem::Specification.new do |s|
  s.rubygems_version = %q{1.7.2}

  s.name     = %q{quarry}
  s.summary  = %q{Dig in to location conversion}
  s.homepage = %q{http://github.com/joshuaclayton/quarry}
  s.version  = Quarry::VERSION
  s.authors  = ["Josh Clayton"]
  s.email    = %q{joshua.clayton@gmail.com}

  s.files         = `git ls-files`.split("\n")
  s.test_files    = `git ls-files -- {test,spec,features}/*`.split("\n")
  s.executables   = `git ls-files -- bin/*`.split("\n").map { |f| File.basename(f) }
  s.require_paths = ["lib"]

  s.extensions = ["ext/quarry/extconf.rb"]

  s.add_dependency "rake-compiler", "0.7.6"

  s.add_development_dependency "rspec",     "2.7.0"
  s.add_development_dependency "cucumber",  "1.1.4"
  s.add_development_dependency "rcov",      "0.9.9"
  s.add_development_dependency "graticule", ">= 2.2.0"
end
