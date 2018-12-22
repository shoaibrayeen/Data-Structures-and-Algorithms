## Given an integer ‘n’, print the first ‘n’ terms of the Moser-de Bruijn Sequence.

## The Moser-de Bruijn sequence is the sequence obtained by adding up the distinct powers of the number 4 (For example 1, 4, 16, 64, etc).

```
Input : 5
Output : 0 1 4 5 16

Input : 10
Output : 0 1 4 5 16 17 20 21 64 65
```


## Reccurence Relation
```
1) S(2 * n) = 4 * S(n)
2) S(2 * n + 1) = 4 * S(n) + 1
with S(0) = 0 and S(1) = 1
```
