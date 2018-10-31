k = 50
u = 2/3
a = k * u
b = k * (1-u)
theta = seq(from=0, to=1, by=0.001)
p = dbeta(theta, a, b)
plot(theta, p, xlab='theta', ylab='p( theta | a, b)', type='l', col='blue')