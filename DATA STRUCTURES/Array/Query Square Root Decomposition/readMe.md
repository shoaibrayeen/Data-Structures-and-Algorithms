## Let us consider the following problem to understand MO’s Algorithm.

## We are given an array and a set of query ranges, we are required to find the sum of every query range.
```
Input:  arr[]   = {1, 1, 2, 1, 3, 4, 5, 2, 8};
        query[] = [0, 4], [1, 3] [2, 4]
Output: Sum of arr[] elements in range [0, 4] is 8
        Sum of arr[] elements in range [1, 3] is 4  
        Sum of arr[] elements in range [2, 4] is 6
```


- All queries are known beforehead so that they can be preprocessed
- It cannot work for problems where we have update operations also mixed with sum queries.
- MO’s algorithm can only be used for query problems where a query can be computed from results of the previous query. One more such example is maximum or minimum.

Time Complexity Analysis:
The function mainly runs a for loop for all sorted queries. Inside the for loop, there are four while queries that move ‘currL’ and ‘currR’.

How much currR is moved? For each block, queries are sorted in increasing order of R. So, for a block, currR moves in increasing order. In worst case, before beginning of every block, currR at extreme right and current block moves it back the extreme left. This means that for every block, currR moves at most O(n). Since there are O(√n) blocks, total movement of currR is O(n * √n).

How much currL is moved? Since all queries are sorted in a way that L values are grouped by blocks, movement is O(√n) when we move from one query to another quert. For m queries, total movement of currL is O(m * √n)

Please note that a Simple and more Efficient solution to solve this problem is to compute prefix sum for all elements from 0 to n-1. Let the prefix sum be stored in an array preSum[] (The value of preSum[i] stores sum of arr[0..i]). Once we have built preSum[], we can traverse through all queries one by one. For every query [L, R], we return value of preSum[R] – preSum[L]. Here processing every query takes O(1) time.

The idea of this article is to introduce MO’s algorithm with a very simple example. We will soon be discussing more interesting problems using MO’s algorithm.
