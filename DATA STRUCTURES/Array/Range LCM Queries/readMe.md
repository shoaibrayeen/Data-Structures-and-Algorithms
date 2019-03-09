## Given an array of integers, evaluate queries of the form LCM(l, r). There might be many queries, hence evaluate the queries efficiently.
```
LCM (l, r) denotes the LCM of array elements
           that lie between the index l and r
           (inclusive of both indices) 

Mathematically, 
LCM(l, r) = LCM(arr[l],  arr[l+1] , ......... , arr[r-1], arr[r])
```
```
Inputs : Array = {5, 7, 5, 2, 10, 12 ,11, 17, 14, 1, 44}
         Queries: LCM(2, 5), LCM(5, 10), LCM(0, 10)
Outputs: 60 15708 78540
Explanation : In the first query LCM(5, 2, 10, 12) = 60, 
              similarly in other queries.
```
