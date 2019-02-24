## Given n integers. The task is to minimize the sum of multiplication of all the numbers by taking two adjacent numbers at a time and putting back their sum % 100 till a number is left.

```
Input : 40 60 20 
Output : 2400  
Explanation: There are two possible cases:
1st possibility: Take 40 and 60, so multiplication=2400
and put back (60+40) % 100 = 0, making it 0, 20.
Multiplying 0 and 20 we get 0 so 
multiplication = 2400+0 = 2400. Put back (0+20)%100 = 20. 
2nd possibility: take 60 and 20, so 60*20 = 1200,
put back (60+20)%100 = 80, making it [40, 80] 
multiply 40*80 to get 3200, so multiplication
sum = 1200+3200 = 4400. Put back (40+80)%100 = 20 

Input : 5 6 
Output : 30 
Explanation: Only possibility is 5*6=30 
```
