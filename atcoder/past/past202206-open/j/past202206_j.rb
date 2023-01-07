require 'date'
require 'set'

s = Date.parse(gets)
t = Date.parse(gets)

ans = 0
loop do
  ans += 1 if s.saturday? || s.sunday?
  s += 1
  break if s > t
end

puts ans
