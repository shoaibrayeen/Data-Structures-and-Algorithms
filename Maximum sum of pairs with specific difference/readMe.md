## Given an array of integers and a number k. We can pair two number of array if difference between them is strictly less than k. The task is to find maximum possible sum of disjoint pairs. Sum of P pairs is sum of all 2P numbers of pairs.

> Examples:
> Input  : arr[] = {3, 5, 10, 15, 17, 12, 9}, K = 4
  Output : 62
  Then disjoint pairs with difference less than K are,
  (3, 5), (10, 12), (15, 17)    
  So maximum sum which we can get is 3 + 5 + 12 + 10 + 15 + 17 = 62
  Note that an alternate way to form disjoint pairs is,
  (3, 5), (9, 12), (15, 17), but this pairing produces lesser sum.

> Input  : arr[] = {5, 15, 10, 300}, k = 12
  Output : 25
