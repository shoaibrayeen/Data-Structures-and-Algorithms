## The Jacobsthal sequence is an additive sequence similar to the Fibonacci sequence, defined by the recurrence relation Jn = Jn-1 + Jn-2, with initial terms J0 = 0 and J1 = 1. A number in the sequence is called a Jacobsthal number. They are a specific type of Lucas sequence Un(P, Q) for which P = -1 and Q = -2.
## The first Jacobsthal numbers are:
    0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, ……
    
Jacobsthal numbers are defined by the recurrence relation:
```
    J(n)  =   0                     if n == 0
    J(n)  =   1                     if n == 1
    J(n)  =   J(n-1) + 2*J(n-2)     otherwise
```

Jacobsthal-Lucas numbers
Jacobsthal-Lucas numbers represent the complementary Lucas sequence Vn(1, -2). They satisfy the same recurrence relation as Jacobsthal numbers but have different initial values:
```
    L(n)  =   0                     if n == 0
    L(n)  =   1                     if n == 1
    L(n)  =   L(n-1) + 2*L(n-2)     otherwise
```



```
Input : n = 5
Output :
Jacobsthal number: 11
Jacobsthal-Lucas number: 31

Input : n = 4
Output :
Jacobsthal number: 5
Jacobsthal-Lucas number: 17
```
