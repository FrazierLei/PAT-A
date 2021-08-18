# PAT（甲级）2019年冬季考试

## 难点分析

1. 第一题我最后做的，因为一开始没读懂题😅，最后花了一个多小时才写完，什么阴间题目啊NMSL。

2. 第二题反转链表，有手就行。

3. 第三题哈希，一开始以为是并查集，瞎忙活了半天，浪费了半个小时，好在改了以后一次过了。

4. 第四题由中序+特性（最小堆）递归建树，题库里有挺多这类题的，都掌握了就问题不大。

   

## 7-1 Good in C (20 分)

When your interviewer asks you to write "Hello World" using C, can you do as the following figure shows?

![](../images/c.jpg)

### Input Specification:

Each input file contains one test case. For each case, the first part gives the 26 capital English letters A-Z, each in a 7×5 matrix of `C`'s and `.`'s. Then a sentence is given in a line, ended by a return. The sentence is formed by several words (no more than 10 continuous capital English letters each), and the words are separated by any characters other than capital English letters.

It is guaranteed that there is at least one word given.

### Output Specification:

For each word, print the matrix form of each of its letters in a line, and the letters must be separated by exactly one column of space. There must be no extra space at the beginning or the end of the word.

Between two adjacent words, there must be a single empty line to separate them. There must be no extra line at the beginning or the end of the output.

### Sample Input:

```in
..C..
.C.C.
C...C
CCCCC
C...C
C...C
C...C
CCCC.
C...C
C...C
CCCC.
C...C
C...C
CCCC.
.CCC.
C...C
C....
C....
C....
C...C
.CCC.
CCCC.
C...C
C...C
C...C
C...C
C...C
CCCC.
CCCCC
C....
C....
CCCC.
C....
C....
CCCCC
CCCCC
C....
C....
CCCC.
C....
C....
C....
CCCC.
C...C
C....
C.CCC
C...C
C...C
CCCC.
C...C
C...C
C...C
CCCCC
C...C
C...C
C...C
CCCCC
..C..
..C..
..C..
..C..
..C..
CCCCC
CCCCC
....C
....C
....C
....C
C...C
.CCC.
C...C
C..C.
C.C..
CC...
C.C..
C..C.
C...C
C....
C....
C....
C....
C....
C....
CCCCC
C...C
C...C
CC.CC
C.C.C
C...C
C...C
C...C
C...C
C...C
CC..C
C.C.C
C..CC
C...C
C...C
.CCC.
C...C
C...C
C...C
C...C
C...C
.CCC.
CCCC.
C...C
C...C
CCCC.
C....
C....
C....
.CCC.
C...C
C...C
C...C
C.C.C
C..CC
.CCC.
CCCC.
C...C
CCCC.
CC...
C.C..
C..C.
C...C
.CCC.
C...C
C....
.CCC.
....C
C...C
.CCC.
CCCCC
..C..
..C..
..C..
..C..
..C..
..C..
C...C
C...C
C...C
C...C
C...C
C...C
.CCC.
C...C
C...C
C...C
C...C
C...C
.C.C.
..C..
C...C
C...C
C...C
C.C.C
CC.CC
C...C
C...C
C...C
C...C
.C.C.
..C..
.C.C.
C...C
C...C
C...C
C...C
.C.C.
..C..
..C..
..C..
..C..
CCCCC
....C
...C.
..C..
.C...
C....
CCCCC
HELLO~WORLD!
```

### Sample Output:

```out
C...C CCCCC C.... C.... .CCC.
C...C C.... C.... C.... C...C
C...C C.... C.... C.... C...C
CCCCC CCCC. C.... C.... C...C
C...C C.... C.... C.... C...C
C...C C.... C.... C.... C...C
C...C CCCCC CCCCC CCCCC .CCC.

C...C .CCC. CCCC. C.... CCCC.
C...C C...C C...C C.... C...C
C...C C...C CCCC. C.... C...C
C.C.C C...C CC... C.... C...C
CC.CC C...C C.C.. C.... C...C
C...C C...C C..C. C.... C...C
C...C .CCC. C...C CCCCC CCCC.
```





## 7-2 Block Reversing (25 分)

Given a singly linked list $L$. Let us consider every $K$ nodes as a **block** (if there are less than $K$ nodes at the end of the list, the rest of the nodes are still considered as a block). Your job is to reverse all the blocks in $L$. For example, given *L* as 1→2→3→4→5→6→7→8 and $K$ as 3, your output must be 7→8→4→5→6→1→2→3.

### Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, a positive $N (\leq10^5)$ which is the total number of nodes, and a positive $K (\leq N)$ which is the size of a block. The address of a node is a 5-digit nonnegative integer, and NULL is represented by −1.

Then *N* lines follow, each describes a node in the format:

```
Address Data Next
```

where `Address` is the position of the node, `Data` is an integer, and `Next` is the position of the next node.

### Output Specification:

For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

### Sample Input:

```in
00100 8 3
71120 7 88666
00000 4 99999
00100 1 12309
68237 6 71120
33218 3 00000
99999 5 68237
88666 8 -1
12309 2 33218
```

### Sample Output:

```out
71120 7 88666
88666 8 00000
00000 4 99999
99999 5 68237
68237 6 00100
00100 1 12309
12309 2 33218
33218 3 -1
```



## 7-3 Summit (25 分)

A **summit** (峰会) is a meeting of heads of state or government. Arranging the rest areas for the summit is not a simple job. The ideal arrangement of one area is to invite those heads so that everyone is a direct friend of everyone.

Now given a set of tentative arrangements, your job is to tell the organizers whether or not each area is all set.

### Input Specification:

Each input file contains one test case. For each case, the first line gives two positive integers $N (\leq 200)$, the number of heads in the summit, and $M$, the number of friendship relations. Then $M$ lines follow, each gives a pair of indices of the heads who are friends to each other. The heads are indexed from 1 to $N$.

Then there is another positive integer $K (\leq 100)$, and K lines of tentative arrangement of rest areas follow, each first gives a positive number $L (\leq N)$, then followed by a sequence of L distinct indices of the heads. All the numbers in a line are separated by a space.

### Output Specification:

For each of the $K$ areas, print in a line your advice in the following format:

- if in this area everyone is a direct friend of everyone, and no friend is missing (that is, no one else is a direct friend of everyone in this area), print `Area X is OK.`.
- if in this area everyone is a direct friend of everyone, yet there are some other heads who may also be invited without breaking the ideal arrangement, print `Area X may invite more people, such as H.` where `H` is the smallest index of the head who may be invited.
- if in this area the arrangement is not an ideal one, then print `Area X needs help.` so the host can provide some special service to help the heads get to know each other.

Here `X` is the index of an area, starting from 1 to `K`.

### Sample Input:

```in
8 10
5 6
7 8
6 4
3 6
4 5
2 3
8 2
2 7
5 3
3 4
6
4 5 4 3 6
3 2 8 7
2 2 3
1 1
2 4 6
3 3 2 1
```

### Sample Output:

```out
Area 1 is OK.
Area 2 is OK.
Area 3 is OK.
Area 4 is OK.
Area 5 may invite more people, such as 3.
Area 6 needs help.
```





## 7-4 Cartesian Tree (30 分)

A **Cartesian tree** is a binary tree constructed from a sequence of distinct numbers. The tree is heap-ordered, and an inorder traversal returns the original sequence. For example, given the sequence { 8, 15, 3, 4, 1, 5, 12, 10, 18, 6 }, the min-heap Cartesian tree is shown by the figure.

![CTree.jpg](/Users/leizongfei/code/PAT-A/images/Cartesian.jpg)

Your job is to output the level-order traversal sequence of the min-heap Cartesian tree.

### Input Specification:

Each input file contains one test case. Each case starts from giving a positive integer $N (\leq30)$, and then $N$ distinct numbers in the next line, separated by a space. All the numbers are in the range of **int**.

### Output Specification:

For each test case, print in a line the level-order traversal sequence of the min-heap Cartesian tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the beginning or the end of the line.

### Sample Input:

```in
10
8 15 3 4 1 5 12 10 18 6
```

### Sample Output:

```out
1 3 5 8 4 6 15 10 12 18
```