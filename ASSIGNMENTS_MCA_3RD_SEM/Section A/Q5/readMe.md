## About check Function
- Sequence is called as text
- Subsequence is called as pattern
- if size of text is less than size of pattern , it's not possible to search pattern in the text.

      text does not contain pattern
- Using Two Pointers

      one is for text -> itr1 in the program
      another is for pattern -> itr2 in the program
    
- It checks in the loop until either text or pattern ends.

      If match occurs , then increment both the pointers.
      otherwise increment itr1 only
- After ending loop , it checks **itr2** 

      if itr2 is equal to size of pattern -> text contains pattern.
      otherwise -> text does not contain pattern.

## Instructions for q5_(i).cpp
- text_file.txt , pattern_file.txt and q5_(i).cpp must be in same directory.
- Both files should be in text format and texts are separated by delimiter.
- the delimiter should be " , " -> space comma then space.
- text_file.txt must contains sequences.
- pattern_file.txt must contains sub-sequences.

## Instructions for q5_(ii).cpp
- It takes input [ Line by Line for each Entry ] from user.
- If you have to stop taking input , you have to enter -1 and then press enter.

```
Note: At any case , if q5_(i).cpp won't open the file , then it takes input from user.
```
