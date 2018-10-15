heapOdata = rnorm(100000, 10, 0.2)
cc = 0
for (i in c(1:100000)) {
  if ((heapOdata[i] >= 9.8) && (heapOdata[i] < 10)) {
    cc = cc + 1
  }
}
result = cc / 100000 / 0.2
result