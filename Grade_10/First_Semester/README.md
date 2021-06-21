# First semester, 10th grade    
1\. [Print numbers from 1 to `N`.](1.c)  
2\. [Print numbers from 1 to `N`. You get `N` from user.](2.c)  
3\. [Print only even numbers from 1 to `N`.](3.c)  
4\. [Print all divisors of a number. You get `N` from user.](4.c)  
5\. [Print prime numbers from 1 to `N`.](5.c)  
6\. [Print only prime divisors of a number. You get `N` from user.](6.c)  
7\. [Get max from two numbers.](7.c)  
8\. [Get max from three numbers.](8.c)  
9\. [Get max from four numbers.](9.c)  
10-13. [There is a pawn on a chessboard and some piece (knight, bishop, rook, queen). You are given their coordinates. Is it possible to capture the pawn on this move?](10-13.c)  
14\. [Determine by the given three sides of the triangle if it can exist and its type (obtuse, right, acute; regular, isosceles).](14.c)  
15\. [Deterimine if the year is a leap one.](15.c)  
16\. [Count number of days between two dates.](16.c)  
17\. [[TODO] Count number of days between two dates taking into account Julian and Gregorian calendars.](17.c)  
18\. [Quadratic equations.](18.c)  
19\. [FIZZBUZZ. Print numbers from 1 to 100 replacing multiples of 3 with FIZZ, multiple of 5 with BUZZ, multiple of 3 and 5 at once with FIZZBUZZ.](19.c)  
20\. [Count the number of six-digit lucky tickets (the sum of the first three digits must be equal to the sum of the last three digits). Through 6 loops.](20.c)  
21\. [Count the number of six-digit lucky tickets. Through 1 loop.](21.c)  
22\. [Count the number of `N`-digit lucky tickets.](22.c)  
23\. [Print the following sequence. 1 2 4 7 11 16 ...](23.c)  
24\. [Print the following sequence. 1 4 9 16 25 ...](24.c)  
25\. [Print the following sequence. 1 2 4 5 10 11 22 ...](25.c)  
26.1\. [Print the Fibonacci sequence. `(a + b)`](26-1.c)  
26.2\. [Print the Fibonacci sequence. `(a + 2b)`](26-2.c)  
27\. [Draw a tree using `*`.](27.c)  
```
*
**
***
****
*****
******
...
```
28\. [Draw a tree using numbers.](28.c)  
```
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
...
```
29\. [Draw a `N`-side square using numbers.](29.c)
```
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
```  
30\. [Draw a `N`-side square using numbers.](30.c)  
```
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
```
31\. [Draw the following figure. Get `N` and `M` from user.](31.c)  
```
0 1 ... N
N ... 1 0
0 1 ... N
...
(M times)
```
32\. [Draw an upside tree using numbers.](32.c)  
```
0 1 2 ... N
0 1 2 ... N-1
...
0
```
33\. [Draw the following square. Get `N` from user.](33.c)  
```
0 1 2 ... N
1 2 3 ... N+1
...
N N+1 ... 2*N
```
34\. [Draw the following figure.](34.c)  
```
0 1 2 3 Calculate the exponent. Using 4
15-1 16 17 18 5
14 23 24 19 6
13 22 21 20 7
12 11 10 9 8
```
35\. [Creating your own function for arithmetic operations.](35.c)  
36\. [Creating your own function for bitwise conjunction and disjunction.](36.c)  
37\. [Creating your own function for getting the `N`th number of Fibonacci sequence.](37.c)  
38\. [Creating your own function for factorial.](38.c)  
39\. [Creating your own function for exponentiation.](39.c)  
40.1\. [Calculate the exponent. Using power series.](40-1.c)  
40.2\. [Calculate the exponent. Using another formula.](40-0.c)  
41\. [Calculate the sine.](41.c)  
42\. [Calculate the cosine.](42.c)  
43\. [Fill an array with numbers from 1 to 100](43.c)  
44\. [Fill an array with the following sequence. 2 4 6 ... 200](44.c)  
45\. [Fill an array with the following sequence. 1 3 5 ... 199](45.c)  
46\. [Fill an array with the following sequence. 1 2 4 8 ...](46.c)  
47\. [Find the min and max value in an array.](47.c)  
48\. [Arithmetic and geometric mean values.](48.c)  
49\. [Get the amount of pairs where the left value is larger than the right.](49.c)  
50\. [Merge two arrays.](50.c)  
51\. [Merge two arrays so the final array is ascending. Do not use sorting algorithms.](51.c)  
52\. [Shift the elements of an array by `N` positions.](52.c)  
53\. [Reverse the array.](53.c)  
54\. [Bubble sort.](54.c)  
55\. [Insertion sort.](55.c)  
56\. [Selection sort.](56.c)  
57\. [Get the median value.](57.c)  
58\. [Sieve of Eratosthenes.](58.c)  
59\. [Calculate the machine epsilon (`ε`). Compare 1, 1 + `ε`/2, 1 + `ε` and 1 + `ε` + `ε`/2.](59.c)  
60\. [Calculate the sum.](60.c)  
```
s = 0
for i in range(1, 10001):
    s += (-1)**n / n
```
in four ways:  
    * summing from larger to smaller `n`  
    * summing from smaller to larger `n`  
    * summing from larger to smaller `n` separately positive and negative values  
    * summing from smaller to larger `n` separately positive and negative values  
61\. [[TODO] Find out what happens at an overflow.](61.c)  
62\. [Swap](62.c)  
63\. [Change int* through char*](63.c)
```c
#include <stdio.h>
int main(void)
{
    int *a = (int *) malloc(sizeof(int));
    char *b = a;
    //*b = 123456789;
    *(b) = ;
    *(b+1) =;
    *(b+2) =;
    *(b+3) =;
    printf("%d", *a);
    return 0;
}
```  
64\. [C(n, k). Use text files.](64.c)  
65\. [Structs. Sorting an array of structs.](65.c)  
66\. [Singly linked list. Create the following functions.](66.c)  
```c
struct List *addElement(struct List *head, int value, int typeOfAdding); //or 3(2) functions
struct List *deleteElement(struct List *head, int value);
void printList(struct List *head);
void freeList(struct List *head);
struct List *sortList(struct List *head); //merge sort
int isCycled(struct List *head);
```
67\. [Doubly linked list.](67.c)  
68\. [Binary search.](68.c)  
69\. [Topological sorting of a graph.](69.c)  
70\. [Strings. Create the following functions in your own library.](70/main.c)  
```c
size_t strlen(const char *);
char *strcpy(char *toHere, const char *fromHere);
int strcmp(const char *, const char *);
char *strcat(char *dest, const char *src);
char *strstr(const char *haystack, const char *needle);
```