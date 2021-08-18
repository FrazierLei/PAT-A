# PAT（甲级）2019年春季考试

## 难点分析

0. 四道题里没有特别难或者特别坑的问题，属于比较友好的一份试卷。
1. 第一题判断素数对，有手就行。
2. 第二题考查模拟，场景比较简单，用哈希很快，我用的容器是 `unordered_set`。
3. 第三题考查图中的连通分量，我用的并查集。会做 [PAT A-1034](https://pintia.cn/problem-sets/994805342720868352/problems/994805456881434624) 的话这道题问题不大。
4. 第四题考查用树的后序+中序去重建树，算是模板题吧，题库里有—— [PAT A-1020](https://pintia.cn/problem-sets/994805342720868352/problems/994805485033603072)。



## 7-1 Sexy Primes (20 分)

Sexy primes are pairs of primes of the form $(p, p+6)$, so-named since "sex" is the Latin word for "six". (Quoted from http://mathworld.wolfram.com/SexyPrimes.html)

Now given an integer, you are supposed to tell if it is a sexy prime.

### Input Specification:

Each input file contains one test case. Each case gives a positive integer $N (\leq 10^8)$.

### Output Specification:

For each case, print in a line `Yes` if $N$ is a sexy prime, then print in the next line the other sexy prime paired with *N* (if the answer is not unique, output the smaller number). Or if $N$ is not a sexy prime, print `No` instead, then print in the next line the smallest sexy prime which is larger than $N$.

### Sample Input 1:

```in
47
```

### Sample Output 1:

```out
Yes
41
```

### Sample Input 2:

```in
21
```

### Sample Output 2:

```out
No
23
```





## 7-2 Anniversary (25 分)

Zhejiang University is about to celebrate her 122th anniversary in 2019. To prepare for the celebration, the alumni association （校友会） has gathered the ID's of all her alumni. Now your job is to write a program to count the number of alumni among all the people who come to the celebration.

### Input Specification:

Each input file contains one test case. For each case, the first part is about the information of all the alumni. Given in the first line is a positive integer $N (\leq10^5)$. Then $N$ lines follow, each contains an ID number of an alumnus. An ID number is a string of 18 digits or the letter `X`. It is guaranteed that all the ID's are distinct.

The next part gives the information of all the people who come to the celebration. Again given in the first line is a positive integer $M (\leq10^5)$. Then $M$ lines follow, each contains an ID number of a guest. It is guaranteed that all the ID's are distinct.

### Output Specification:

First print in a line the number of alumni among all the people who come to the celebration. Then in the second line, print the ID of the oldest alumnus -- notice that the 7th - 14th digits of the ID gives one's birth date. If no alumnus comes, output the ID of the oldest guest instead. It is guaranteed that such an alumnus or guest is unique.

### Sample Input:

```in
5
372928196906118710
610481197806202213
440684198612150417
13072819571002001X
150702193604190912
6
530125197901260019
150702193604190912
220221196701020034
610481197806202213
440684198612150417
370205198709275042
```

### Sample Output:

```out
3
150702193604190912
```





## 7-3 Telefraud Detection (25 分)

Telefraud（电信诈骗） remains a common and persistent problem in our society. In some cases, unsuspecting victims lose their entire life savings. To stop this crime, you are supposed to write a program to detect those suspects from a huge amount of phone call records.

A person must be detected as a suspect if he/she makes more than $K$ short phone calls to **different** people everyday, but no more than 20% of these people would call back. And more, if two suspects are calling each other, we say they might belong to the same gang. $A$ makes a **short** phone call to $B$ means that the total duration of the calls from $A$ to $B$ is no more than 5 minutes.

### Input Specification:

Each input file contains one test case. For each case, the first line gives 3 positive integers $K (\leq 500$, the threshold（阈值） of the amount of short phone calls), $N (\leq 10^3$, the number of different phone numbers), and $M (≤10^5$, the number of phone call records). Then *M* lines of one day's records are given, each in the format:

```
caller receiver duration
```

where `caller` and `receiver` are numbered from 1 to $N$, and `duration` is no more than 1440 minutes in a day.

### Output Specification:

Print in each line all the detected suspects in a gang, in ascending order of their numbers. The gangs are printed in ascending order of their first members. The numbers in a line must be separated by exactly 1 space, and there must be no extra space at the beginning or the end of the line.

If no one is detected, output `None` instead.

### Sample Input 1:

```in
5 15 31
1 4 2
1 5 2
1 5 4
1 7 5
1 8 3
1 9 1
1 6 5
1 15 2
1 15 5
3 2 2
3 5 15
3 13 1
3 12 1
3 14 1
3 10 2
3 11 5
5 2 1
5 3 10
5 1 1
5 7 2
5 6 1
5 13 4
5 15 1
11 10 5
12 14 1
6 1 1
6 9 2
6 10 5
6 11 2
6 12 1
6 13 1
```

### Sample Output 1:

```out
3 5
6
```

**Note:** In sample 1, although `1` had 9 records, but there were 7 distinct receivers, among which `5` and `15` both had conversations lasted more than 5 minutes in total. Hence `1` had made 5 short phone calls and didn't exceed the threshold 5, and therefore is not a suspect.

### Sample Input 2:

```in
5 7 8
1 2 1
1 3 1
1 4 1
1 5 1
1 6 1
1 7 1
2 1 1
3 1 1
```

### Sample Output 2:

```out
None
```





## 7-4 Structure of a Binary Tree (30 分)

Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, a binary tree can be uniquely determined.

Now given a sequence of statements about the structure of the resulting tree, you are supposed to tell if they are correct or not. A statment is one of the following:

- A is the root
- A and B are siblings
- A is the parent of B
- A is the left child of B
- A is the right child of B
- A and B are on the same level
- It is a full tree

Note:

- Two nodes are **on the same level**, means that they have the same depth.
- A **full binary tree** is a tree in which every node other than the leaves has two children.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer $N (\leq30)$, the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are no more than $10^3$ and are separated by a space.

Then another positive integer $M (\leq30)$ is given, followed by $M$ lines of statements. It is guaranteed that both `A` and `B` in the statements are in the tree.

### Output Specification:

For each statement, print in a line `Yes` if it is correct, or `No` if not.

### Sample Input:

```in
9
16 7 11 32 28 2 23 8 15
16 23 7 32 11 2 28 15 8
7
15 is the root
8 and 2 are siblings
32 is the parent of 11
23 is the left child of 16
28 is the right child of 2
7 and 11 are on the same level
It is a full tree
```

### Sample Output:

```out
Yes
No
Yes
No
Yes
Yes
Yes
```

