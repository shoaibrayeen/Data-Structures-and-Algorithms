## In mathematics, the Golomb sequence is a non-decreasing integer sequence where n-th term is equal to number of times n appears in the sequence.
```
The first few values are
1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, ……

Explanation of few terms:
Third term is 2, note that three appears 2 times.
Second term is 2, note that two appears 2 times.
Fourth term is 3, note that four appears 3 times.
```

```
Input : n = 4
Output : 1 2 2 3

Input : n = 6
Output : 1 2 2 3 3 4
```


```
The recurrence relation to find the nth term of Golomb sequence:
a(1) = 1
a(n + 1) = 1 + a(n + 1 – a(a(n)))
```
