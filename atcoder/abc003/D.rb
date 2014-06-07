def fact(n)
  n == 0 ? 1 : n * fact(n-1)
end

def comb(n, m)
  fact(n) / (fact(m) * fact(n-m))
end

mod = 1000000007

r, c = gets.split(' ').map(&:to_i)
x, y = gets.split(' ').map(&:to_i)
d, l = gets.split(' ').map(&:to_i)

puts (r-x+1) * (c-y+1) * comb(d+l, d) % mod
