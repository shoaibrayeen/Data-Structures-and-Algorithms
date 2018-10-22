## There are N players which are playing a tournament. We need to find the maximum number of games the winner can play. In this tournament, two players are allowed to play against each other only if the difference between games played by them is not more than one.

**Examples:**
```
Input  : N = 3
Output : 2
Maximum games winner can play = 2
Assume that player are P1, P2 and P3
First, two players will play let (P1, P2)
Now winner will play against P3, 
making total games played by winner = 2

Input  : N = 4
Output : 2
Maximum games winner can play = 2
Assume that player are P1, P2, P3 and P4
First two pairs will play lets (P1, P2) and 
(P3, P4). Now winner of these two games will 
play against each other, making total games
played by winner = 2
```
