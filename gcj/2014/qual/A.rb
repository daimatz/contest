def get_ary(m)
  ret = []
  4.times do |n|
    line = gets
    ret = line.split(' ').map(&:to_i) if n + 1 == m
  end
  ret
end

def solve()
  first = get_ary(gets.to_i)
  second = get_ary(gets.to_i)
  final = first & second

  if final.size == 0
    "Volunteer cheated!"
  elsif final.size == 1
    final[0]
  else
    "Bad magician!"
  end
end

T = gets.to_i
T.times do |t|
  puts "Case \##{t+1}: #{solve()}"
end
