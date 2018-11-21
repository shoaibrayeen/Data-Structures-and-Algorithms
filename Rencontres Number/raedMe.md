## Given two numbers, n >= 0 and 0 <= k <= n, count the number of derangements with k fixed points.

```

Input : n = 3, k = 0
Output : 2
Since k = 0, no point needs to be on its
original position. So derangements
are {3, 1, 2} and {2, 3, 1}

Input : n = 3, k = 1
Output : 3
Since k = 1, one point needs to be on its
original position. So partial derangements
are {1, 3, 2}, {3, 2, 1} and {2, 1, 3}

Input : n = 7, k = 2
Output : 924
```

## The recurrence relation to find Rencontres Number D (n, m):
```
    D(0, 0)   =   1                               if n==0 & m==0
    D(1, 0)   =   0                               if n==1 & m==0
    D(n+2, 0) =   (n+1) * (D(n+1, 0) + D(n, 0))   if only m==0 
    D(n, m)   =   C(n , m) * D( n - m , 0))       otherwise
```
