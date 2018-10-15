x = seq(from=-8, to=8, by=0.01)
d1 = dnorm(x, 1, 2)
d2 = dnorm(x, 2, 2)
result = (d1 + d2) * 0.5
plot(x, result, xlab = "y", ylab = "p(y)", type = "l")