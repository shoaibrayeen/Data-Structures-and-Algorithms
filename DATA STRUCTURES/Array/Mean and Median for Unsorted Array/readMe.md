## Given n size unsorted array, find its mean and median.

Mean of an array = (sum of all elements) /
                   (number of elements)

Median of a sorted array of size n is defined 
as below : 
It is middle element when n is odd and average
of middle two elements when n is even.

Since the array is not sorted here, we sort 
the array first, then apply above formula.

```
Input  : a[] = {1, 3, 4, 2, 6, 5, 8, 7}
Output : Mean = 4.5
         Median = 4.5
Sum of the elements is 1 + 3 + 4 + 2 + 6 + 
5 + 8 + 7 = 36
Mean = 36/8 = 4.5
Since number of elements are even, median
is average of 4th and 5th largest elements.
which means (4 + 5)/2 = 4.5

Input  : a[] = {4, 4, 4, 4, 4}
Output : Mean = 4
         Median = 4 
```
