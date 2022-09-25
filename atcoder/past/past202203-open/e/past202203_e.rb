require 'date'
require 'set'

d = Date.parse(gets)

loop do
  s = Set.new
  y = d.year
  4.times do
    s << y % 10
    y /= 10
  end
  m = d.month
  2.times do
    s << m % 10
    m /= 10
  end
  da = d.day
  2.times do
    s << da % 10
    da /= 10
  end

  if (s.count <= 2)
    s = d.to_s.gsub(/-/, '/')
    puts s
    break
  end

  d += 1
end
