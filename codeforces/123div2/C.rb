#!/usr/bin/ruby -w

N = gets.strip.to_i
level = 0
ex = ''
ex_level = 0
dummy = 0

N.times do |i|
  line = gets
  next if not line
  line.strip!

  if line =~ /try$/
    level += 1
    dummy += 1 if ex != ''
    #puts "#{level}, #{dummy}, try, #{ex}"
  elsif line =~ /throw\s*\((.+?)\)/
    #puts "#{level}, throw #{$1.strip}"
    ex = $1.strip
    ex_level = level
  elsif line =~ /catch\s*\((.+?)\s*,\s*"(.+?)"\s*\)/
    #puts "#{level}, #{dummy}, #{$2}"
    if dummy == 0 && level <= ex_level && ex == $1.strip
      puts $2
      exit
    end
    level -= 1
    dummy -= 1 if dummy > 0
  end
end

puts "Unhandled Exception"
