## Naive String Matching Algorithm - Brute Force approach.
- Checks for every index in the text
- if match occurs , then check for the whole pattern
- otherwise check for next index
```
Input:  text[]    = "THIS IS A TEST TEXT"
        pattern[] = "TEXT"
Output: Pattern found at index 15

Input:  text[]    =  "AABAACAADAABAABA"
        pattern[]     =  "AABA"
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12
```

### Best Case Analysis
```
    text[]    = "THIS IS A TEST TEXT"
    pattern[] = "KEXT"
    The best case occurs when the first character of the pattern is not present in text at all.
    The number of comparisons in best case is O(n-m) ~ O(n)
```

### Worst Case Analysis
```
  1) When all characters of the text and pattern are same.
    text[]    = "TTTTTTTTTTTTTTTTTTTTTT"
    pattern[] = "TTTTTTTT"
  2) when only the last character is different.
    text[]    = "TTTTTTTTTTTTTTTTTTTTTTP"
    pattern[] = "TTTTTTTTP"
    
  The number of comparisons in worst case is O((n-m+1)*m) ~ O(m*n).
```


## KMP Algorithm
- It uses prefix and suffix to minimize comparisons.
- With the help of prefix and suffix , whenever match does not occur , it compares with its prefix value rather than comparing at the beginning of the pattern.
```
The Time Complexity, T(n) = Θ(n+m) ; As n >> m; T(n) ≅ Θ(n)
```

## Rabin-Karp Algorithm
- It uses hashing to match the pattern.
- If Hash value is same for both , then compare text and pattern.
- If Hash value is different , then increase index and calculate hash value for text again.
- Repeat all steps till the difference of size of text and size of pattern

```
The Time Complexity, T(n) = Θ(n*m)
```
