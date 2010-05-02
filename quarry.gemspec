Gem::Specification.new do |s|
  s.require_paths = ["lib"]
  s.rubygems_version = %q{1.3.6}

  s.name = %q{quarry}
  s.summary = %q{Dig in to location conversion}
  s.homepage = %q{http://github.com/joshuaclayton/quarry}
  s.version = "0.0.1"
  s.authors = ["Josh Clayton"]
  s.date = %q{2010-05-02}
  s.email = %q{joshua.clayton@gmail.com}
  s.extensions = ["ext/quarry/extconf.rb"]
  s.files = [
    ".gitignore",
    "GEOTRANS-LICENSE",
    "MIT-LICENSE",
    "README.markdown",
    "Rakefile",
    "ext/quarry/extconf.rb",
    "ext/quarry/mgrs.c",
    "ext/quarry/mgrs.h",
    "ext/quarry/polarst.c",
    "ext/quarry/polarst.h",
    "ext/quarry/quarry.c",
    "ext/quarry/quarry.h",
    "ext/quarry/tranmerc.c",
    "ext/quarry/tranmerc.h",
    "ext/quarry/ups.c",
    "ext/quarry/ups.h",
    "ext/quarry/utm.c",
    "ext/quarry/utm.h"
  ]
  s.test_files = [
    ".autotest",
    "cucumber.yml",
    "features/conversion.feature",
    "features/step_definitions/conversion_steps.rb",
    "features/support/env.rb",
  ]

  s.add_development_dependency "graticule", ">= 0.2.12"
end
