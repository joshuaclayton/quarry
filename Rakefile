require "rubygems"
require "rake"

require "rake/extensiontask"

Rake::ExtensionTask.new("quarry") do |ext|
  ext.lib_dir = File.join("lib", "quarry")
end

begin
  require "cucumber/rake/task"

  Cucumber::Rake::Task.new do |t|
    t.rcov = true
  end
  task :cucumber => :compile
rescue LoadError
  task :cucumber do
    abort "Cucumber is not available. In order to run features, you must: gem install cucumber"
  end
end

task :default => :cucumber
