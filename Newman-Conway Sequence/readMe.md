## Newman-Conway Sequence is the one which generates the following integer sequence.
    1 1 2 2 3 4 4 4 5 6 7 7…

## In mathematical terms, the sequence P(n) of Newman-Conway numbers is defined by recurrence relation

    P(n) = P(P(n - 1)) + P(n - P(n - 1)) 
    with seed values P(1) = 1 and P(2) = 1

 
```
Input : n = 2
Output : 1  1

Input : n = 10
Output : 1  1  2  2  3  4  4  4  5  6 
```
