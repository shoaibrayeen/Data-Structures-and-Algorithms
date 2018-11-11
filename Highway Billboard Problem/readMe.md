## Consider a highway of M miles. The task is to place billboards on the highway such that revenue is maximized. The possible sites for billboards are given by number x1 < x2 < ….. < xn-1 < xn, specifying positions in miles measured from one end of the road. If we place a billboard at position xi, we receive a revenue of ri > 0. There is a restriction that no two billboards can be placed within t miles or less than it.

## Note : All possible sites from x1 to xn are in range from 0 to M as need to place billboards on a highway of M miles.

     Input  :     M   =   20
                  x[] =   { 6, 7, 12, 13, 14 }
                  r[] =   { 5, 6, 5,  3,  1}
                  t   =   5
     Output :     10
     By placing two billboards at 6 miles and 12 miles will produce the maximum revenue of 10.

     Input  :     M   = 15
                  x[] = { 6, 9, 12, 14 }
                  r[] = { 5, 6, 3, 7 }
                  t   = 2
     Output :     18  
