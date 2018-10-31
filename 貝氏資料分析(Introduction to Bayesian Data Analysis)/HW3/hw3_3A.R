source("C:/Users/Rama/AppData/Local/Temp/DBDA2Eprograms/DBDA2E-utilities.R")  # Load definitions of graphics functions etc.
source("C:/Users/Rama/AppData/Local/Temp/DBDA2Eprograms/BernBeta.R")          # Load the definition of the BernBeta function

heads = 63
tails = 97 - 63

a = 0.01
b = 0.01
shape = c(a,b)

theta = seq(from=0, to=1, by=0.01)

Data = c(rep(0,tails), rep(1, heads))

openGraph(width=5,height=7)
posterior = BernBeta( priorBetaAB=shape, Data=Data , plotType="Bars" , 
                      showCentTend="Mode" , showHDI=TRUE , showpD=FALSE )
saveGraph(file="BernBetaExample",type="png")