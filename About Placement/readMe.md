# General Overview About Placement

## Number of different Posts
- Software Development Engineer/Developer [ Specific Posts Under SDE - Solution Engineer and UI Designer ]
- Business Analyst
- Data Analyst


## How to Prepare for Placement
- For Quantitative Aptitude and Logical Reasoning -> Practice at least 10 Problems of one topic
```
Quantitative Aptitude - R.S. Aggarwal
Quantitative Aptitude and Logical Reasoning  - JEE Mains or MCA Entrance Notes/Books
```
- For CS based MCQ Round , Some points should be kept in the mind.

```
 Like , 
 - You should know about C language in depth.
 - You should know Important topics from DBMS such as Normalization , Transations ,
   SQL , Contraints , Relational Mappings etc.
 - You should know basics about Computer Networks [ DNS , TCP , HTTPS etc. ] , 
   Operating System [ About OS , Process Management , Memory Management etc. ] etc.
```

- For Data Structure and Algorithms -> MIT Tutions will be one of the best sources. 
```
    For Algorithms -> NG Ma'am notes
    For DS -> Any book referred by DU Guidlines
```
- For Beginners , Go through each Concept in depth -> [Geeksforgeeks](https://www.geeksforgeeks.org) or [HackerRank](https://www.hackerrank.com)
```
  For Example , 
  If you are studying about Array , you should know some points about Array :-
   - Advantages of Array
   - Disvantages of Array
   - How Memory Allocated to Array
   - Array is the best to solve in which type of problems? If yes , then why?  
```
- After doing problems on Geeksforgeeks and HackerRank , Do Topic-wise problems either on [ InterviewBit ](https://www.interviewbit.com/practice/) or [HackerEarth](https://www.hackerearth.com/practice/)

- Now , For Paper-Pen Coding , Start from Scratch.
```
 As Most of companies prefer C++ for Paper-Pen Coding , So You should start writing your code(s)
 on Paper-Pen and then on any of following plateforms.
   For Unix Users , they should use g++.
   For Window Users , they should use CodeBlocks.
   For Mac Users , they should use xCode.
 Some point should be kept in the mind :
  - Your program should be clean and no cross/cut should be on the page.
  - You should use Modular Programming i.e. write your code in function(s).
  - You should use those methods which seems good for given situation.
  - Your program should be indented.
  - While using a variable , you should use var name wisely and related to its working
    because you won't have much time to document the program.
  - Either you should write assumptions that you make while coding or you should handle
    them in your programs.
    For Example :  As Fibonacci Number program works for positive numbers only , So You 
                   should either code to catch negative numbers or write your assumption(s)
                   that Your program will work only for positive numbers.
  - Your coding style should be uniform through out the coding round(s).              
```

```cpp
    /*
        Example to write code on Paper-Pen.
        LCS of Two String
    */
    
int Calculate_LCS_Length_Using_DP( string firstString, string secondString )  { 

   long sizeOfFirstString = firstString.length();
   long sizeOfSecondString = secondString.length();
   
   int Table[sizeOfFirstString + 1 ][sizeOfSecondString + 1 ]; 
   
   for (int i = 0; i <= sizeOfFirstString; i++ ) { 
   
     for (int j = 0; j <= sizeOfSecondString; j++ ) { 
     
       if (i == 0 || j == 0) {
         Table[i][j] = 0; 
       }
       
       else if ( firstString[i-1] == secondString[j-1] ) {
         Table[i][j] = Table[i-1][j-1] + 1;
       }
   
       else {
         Table[i][j] = max( Table[i-1][j] , Table[i][j-1] ); 
       }
       
     } 
     
   } 
   
   return Table[sizeOfFirstString][sizeOfSecondString]; 
}

```


```cpp
    /*
        to check any contraints or to decide anything : Always use bool
    */
bool check() {
    if (condions satisfies) {
        return true;
    }
    else {
        return false;
    }
}
```
- You should have done some projects.

```
Like , 
 - At least 2 Projects on C , C++ , Java.
 - One project based on Client-Server.
 - One Full Stack Project.
 - One Project -> Front-end in HTML , CSS and Back-end in Java/JSP/PHP
 - [ Optional ] - One Project on any framework.
```

- For Preparing for Interviews , Follow [Cracking The Coding Interview](https://drive.google.com/open?id=1PbXGSAj6X4yUIuQyouV5vgUQKtpCePJC) book.
```
Make a group of 5-6 students and practice for interviews after reading the book.
```

## Placement Round(s)
It may vary for some companies.
- 1st Round -> Quantitative Aptitude and Logical Reasoning based MCQ Round
- 2nd Round -> CS based MCQ Round and 1-2 Story Questions to Solve online
- 3rd Round -> Paper-Pen Coding Round
- 4th Round -> Technical Round - can ask anything Related to Project
- 5th Round -> HR Round - Personal Interview

## Important Points
- Your communication skill should be good.
- Don't mention about HTML , CSS in your resume.
- Mention Projects done by yourself only.
- Use only those programming languages which you know well and in depth.
- For Software Development Engineer/Developer , You should know about C++ or JAVA.
- For Business Analyst , You should know about either R or Python and how to solve Case-study.
- For Data Analyst , You should know about either R or Python.
