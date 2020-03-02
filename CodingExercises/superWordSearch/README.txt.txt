Instructions to compile:
g++ -o superWordSearch.exe superWordSearch.cpp superWordSearchMain.cpp

PLEASE PUT YOUR CUSTOM TEST CASE INTO THE FILE "texts.txt"
**This program assumes all letters will be capitalized. Please only use capitalized letters for proper testing.

/********************************************************Description********************************************/

As with the standard word search, you get an NxM grid of letters, and P words that are to be found in the grid.
You also get a "mode" flag with one of the following values: WRAP, NO_WRAP. The flag value indicates
whether words can wrap-around after they hit a boundary of the grid.
Row numbers start at 0 (top row) and go to N-1 (bottom row). Column numbers start at 0 (leftmost column) and
go to M-1 (rightmost column). Grid coordinates are specified as (row_num, column_num).
Here is an example to illustrate the difference between WRAP and NO_WRAP:
  0 1 2
--------
0|A B C
1|D E F
2|G H I

"FED" is a word that starts at (1,2) and ends at (1,0). if we are in WRAP mode:
- "CAB" is a word that starts at (0,2) and ends at (0,1)
- "GAD" is a word that starts at (2,0) and ends at (1,0)
- "BID" is a word that starts at (0,1) and ends at (1,0)
if we are in NO_WRAP mode:
- "FED" is a word that starts at (1,2) and ends at (1,0)
- "CAB" is not a word since it requres wrapping in the horizontal direction
- "GAD" is not a word since it requres wrapping in the vertical direction
- "BID" is not a word since it requres wrapping in the horizontal and vertical directions

A letter in the grid is not allowed to be in a word more than once. So, while technically "HIGH" can be found in the above
grid in WRAP mode, we will not allow it because it uses the H at (2,1) twice



Input Format:

N M // N represents rows and M represents columns
N rows of M capitalized letters
WRAP or NO_WRAP
P // number of words we are searching for
P words with 1 word per line

Output Format:
For each of the P words, outpout the start and end coordinates of that word in the format "(row_start, column start) (row_end, column_end)".
If the word cannot be found in the grid, output "NOT FOUND".
It is guaranteed that each word will occur at most once in the grid, so a word's start and end coordinates will always be unique (if 
the word is in the grid), and will never be ambiguous.

Example1:

Input:
3 3
ABC
DEF
GHI
NO_WRAP
5
FED
CAB
GAD
BID
HIGH

output:
(1,2)(1,0)
NOT FOUND
NOT FOUND
NOT FOUND
NOT FOUND

Example2:

Input:
4 3
ABC
DEF
GHI
JKL
WRAP
5
FED
CAB
AEUBFG
LGEC
HIGH

output:
(1,2)(1,0)
(0,2)(0,1)
(0,0)(2,0)
(3,2)(0,2)
NOT FOUND
