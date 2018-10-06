"""
  main.py
  Algorithm
  Created by Mohd Shoaib Rayeen on 31/07/18.
  Copyright © 2018 Shoaib Rayeen. All rights reserved.

"""

def CeilIndex(A, l, r, key): 
  
    while (r - l > 1): 
      
        m = l + (r - l)//2
        if (A[m] >= key): 
            r = m 
        else: 
            l = m 
    return r 
   
def LongestIncreasingSubsequenceLength(A, size): 
    tailTable = [0 for i in range(size+1)] 
    len=0
    tailTable[0] = A[0] 
    len = 1
    for i in range(1, size): 
      
        if (A[i] < tailTable[0]): 
            tailTable[0] = A[i] 
   
        elif (A[i] > tailTable[len-1]): 
            tailTable[len] = A[i] 
            len+=1
   
        else: 
            tailTable[CeilIndex(tailTable, -1, len-1, A[i])] = A[i] 
    return len
  
A = [ 2, 5, 3, 7, 11, 8, 10, 13, 6 ] 
n =len(A) 
print("Length of Longest Increasing Subsequence is ", LongestIncreasingSubsequenceLength(A, n))
