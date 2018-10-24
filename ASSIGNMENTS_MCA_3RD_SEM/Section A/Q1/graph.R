scatter <- function(data1,data2) {
  plot(x = data1,y = data2, xlab = "Size", ylab = "Comparisons", main = "Comparison Graph of MCP")
}
data1<-c(10 ,50 , 100 , 200 , 300 , 400 , 500 , 600 , 700 , 800 , 900 , 1000 )
data2<-c(165 , 20825 , 1666650 , 1333300 , 4499950 , 10666600 , 20833250 , 35999900, 57166550 , 85333200 , 121499850 ,166666500)
scatter(data1,data2)
