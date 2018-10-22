## Q.1: Given order of n matrices, find the minimum multiplication operations required for multiplying n matrices.
## Q.2: From a given vertex in a weighted connected graph, find shortest paths to other vertices using Dijkstra's algorithm and bellman’s ford algorithm.
## Q.3: Implement N Queen's problem using Back Tracking.
## Q.4: Suppose you are managing the construction of billboards on the university road, a heavily travelled stretch of road that runs west-east for M miles. The possible sites for billboards are given by numbers x1 , x2 , . . . , xn􏰀􏰃 each in the interval [0,􏰄M] (specifying their position along the roads, measured in miles from its western end). If you place billboard at location xi 􏰀􏰅, you receive revenue of 􏰆􏰅ri > 0.
## Regulations imposed by the Delhi road authority require that no two billboards be within less than or equal to 5 miles􏰇􏰈􏰉􏰊􏰋 of each other. You had like to place billboards at a subset of the sites so as to maximize your total revenue, subject to this restriction.
```
Example: Suppose M = 20 , n = 4
{ x1 , x2 , x3 , x4 } = { 6 , 7 , 12 , 14 }
AND { r1 , r2 , r3 , r4 } = { 5 , 6 , 5 , 1 }
Then the optimal solution would be to place billboards at x1 and x3 for total revenue of 10. 
```
**Give an algorithm that takes an instance of this problem as input and returns the maximum total revenue that can be obtained from any valid subsets of sites.**
## Q.5: Some of your friends have gotten into the burgeoning field of time-series data mining, in which one looks for patterns in sequences of events that occur over time. Purchases at stock exchanges --- what's being bought --- are one source of data with a natural ordering in time. Given a long sequence S of such events, your friends want an efficient way to detect certain "patterns" in them --- e.g. they may want to know if the four events
      buy Yahoo, buy eBay, buy Yahoo, buy Oracle
## occur in this sequence S, in order but not necessarily consecutively. They begin with a finite collection of possible events (e.g. the possible transactions) and a sequence S of n of these events. A given event may occur multiple times in S (e.g. Yahoo stock may be bought many times in a single sequence S). We will say that a sequence S' is a subsequence of S if there is a way to delete certain of the events from S so that the remaining events, in order, are equal to the sequence S'. So for example, the sequence of four events above is a sub-sequence of the sequence
      buy Amazon, buy Yahoo, buy eBay, buy Yahoo, buy Yahoo, buy Oracle
## Their goal is to be able to dream up short sequences and quickly detect whether they are subsequences of S. So this is the problem they pose to you: Give an algorithm that takes two sequences of events --- S' of length m and S of length n, each possibly containing an event more than once --- and decides in time O (m + n) whether S' is a subsequence of S.
