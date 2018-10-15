source("DBDA2E-utilities.R")

three = 10**3
four = 10**4
five = 10**5
six = 10**6
set.seed(proc.time()[[3]])

calculate = function(size){
  point_count = 0
  for (i in 1:size) {
    x = runif(1, -0.5, 0.5)
    y = runif(1, -0.5, 0.5)
    distance = sqrt((x**2) + (y**2))
    if (distance <= 0.5) {
      point_count = point_count + 1
    }
  }
  return((point_count*4)/size)
}

three = calculate(three)
four = calculate(four)
five = calculate(five)
six = calculate(six)

openGraph()
plot(xlab = "10ªºn¦¸¤è", ylab = "PI ­È", x = 3:6, y = c(three, four, five, six), type = "o")
