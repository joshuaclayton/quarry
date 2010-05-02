require "rubygems"
require "rake"

require "rake/extensiontask"
Rake::ExtensionTask.new("quarry")

require "cucumber/rake/task"
Cucumber::Rake::Task.new(:cucumber => [:clean, :compile]) do |t|
  t.rcov = true
end

task :default => :cucumber
