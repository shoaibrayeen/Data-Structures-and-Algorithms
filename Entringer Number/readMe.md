## The Entringer Number E(n, k) are the number of permutations of {1, 2, …, n + 1}, starting with k + 1, which, after initally falling, alternatively fall then rise. The Entringer are given by:

```
      E(n,k)  =   0                             if k == 0
              =   1                             if k == 0 and n == 0
              =   E(n,k-1) + E(n-1 , n-k)       otherwise
```
