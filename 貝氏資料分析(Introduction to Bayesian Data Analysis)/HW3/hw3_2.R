k = 50
w = 1 / 6
a = 9
b = 41
theta = seq(from=0, to=1, by=0.001)
p = dbeta(theta, a, b)
plot(theta, p, xlab='theta', ylab=' p( theta | a, b)', type='l', col='blue')