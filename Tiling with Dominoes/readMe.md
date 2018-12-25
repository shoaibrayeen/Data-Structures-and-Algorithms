## Given a 3 x n board, find the number of ways to fill it with 2 x 1 dominoes.
```
Input : 2
Output : 3

Input : 8
Output : 153

Input : 12
Output : 2131
```


```
An =  No. of ways to completely fill a 3 x n board. (We need to find this)
Bn =  No. of ways to fill a 3 x n board with top corner in last column not filled.
Cn =  No. of ways to fill a 3 x n board with bottom corner in last column not filled.
```



```
Final Recursive Relations are:

  A[n] = A[n-2] + 2*(B[n-1]) 
  B[n] = A[n-1] + B[n-2] 
Base Cases:

  A[0]= 1  A[1] = 0 
  B[0]= 0  B[1] = 1 
 ```
