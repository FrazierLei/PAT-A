# PAT（甲级）2019年秋季考试

## 难点分析

1. 第一题蛮力法只能得10分，网上大部分方法都是 DFS + 剪枝，我不太用的来，在 [CSDN](https://blog.csdn.net/qq_40433389/article/details/100653242) 上找到这么一篇博客，思路挺巧妙的，值得学习。
2. 第二题有手就行。
3. 第三题后缀表达式，题库里有一道考察前缀表达式的：[1130 Infix Expression (25 分)](https://pintia.cn/problem-sets/994805342720868352/problems/994805347921805312)，这道题稍微复杂一点点，如果一个节点有两个子节点，那么就后序遍历，如果只有一个子节点则前序遍历。
4. 第四题是近几年图论题里最水的一道了，可以用 dijkstra，也可以用 floyd。

## 7-1 Forever (20 分)

"Forever number" is a positive integer $A$ with $K$ digits, satisfying the following constrains:

- the sum of all the digits of $A$ is $m$;
- the sum of all the digits of $A+1$ is $n$; and
- the greatest common divisor of $m$ and $n$ is a prime number which is greater than 2.

Now you are supposed to find these forever numbers.

### Input Specification:

Each input file contains one test case. For each test case, the first line contains a positive integer $N (\leq5)$. Then $N$ lines follow, each gives a pair of $K (3<K<10)$ and $m (1<m<90)$, of which the meanings are given in the problem description.

### Output Specification:

For each pair of $K$ and $m$, first print in a line `Case X`, where `X` is the case index (starts from 1). Then print $n$ and *A* in the following line. The numbers must be separated by a space. If the solution is not unique, output in the ascending order of $n$. If still not unique, output in the ascending order of $A$. If there is no solution, output `No Solution`.

### Sample Input:

```in
2
6 45
7 80
```

### Sample Output:

```out
Case 1
10 189999
10 279999
10 369999
10 459999
10 549999
10 639999
10 729999
10 819999
10 909999
Case 2
No Solution
```





## 7-2 Merging Linked Lists (25 分)

Given two singly linked lists $L1=a_1→a_2→⋯→a_{n−1}→a_n$ and. $L2=b_1→b_2→⋯→b_{n−1}→b_n$ If $n\geq2m$, you are supposed to reverse and merge the shorter one into the longer one to obtain a list like $a_1→a_2→b_m→a_3→a_4→b_{m−1}⋯$. For example, given one list being 6→7 and the other one 1→2→3→4→5, you must output 1→2→7→3→4→6→5.

### Input Specification:

Each input file contains one test case. For each case, the first line contains the two addresses of the first nodes of $L_1$ and $L_2$, plus a positive $N (\leq10^5)$ which is the total number of nodes given. The address of a node is a 5-digit nonnegative integer, and NULL is represented by `-1`.

Then $N$ lines follow, each describes a node in the format:

```
Address Data Next
```

where `Address` is the position of the node, `Data` is a positive integer no more than $10^5$, and `Next` is the position of the next node. It is guaranteed that no list is empty, and the longer list is at least twice as long as the shorter one.

### Output Specification:

For each case, output in order the resulting linked list. Each node occupies a line, and is printed in the same format as in the input.

### Sample Input:

```in
00100 01000 7
02233 2 34891
00100 6 00001
34891 3 10086
01000 1 02233
00033 5 -1
10086 4 00033
00001 7 -1
```

### Sample Output:

```out
01000 1 02233
02233 2 00001
00001 7 34891
34891 3 10086
10086 4 00100
00100 6 00033
00033 5 -1
```





## 7-3 Postfix Expression (25 分)

Given a syntax tree (binary), you are supposed to output the corresponding postfix expression, with parentheses reflecting the precedences of the operators.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer $N (\leq 20)$ which is the total number of nodes in the syntax tree. Then N lines follow, each gives the information of a node (the *i*-th line corresponds to the *i*-th node) in the format:

```
data left_child right_child
```

where `data` is a string of no more than 10 characters, `left_child` and `right_child` are the indices of this node's left and right children, respectively. The nodes are indexed from 1 to N. The NULL link is represented by −1. The figures 1 and 2 correspond to the samples 1 and 2, respectively.

| ![](../images/postfix1.jpg) | ![](../images/postfix2.jpg) |
| --------------------------- | --------------------------- |
| Figure 1                    | Figure 2                    |

### Output Specification:

For each case, print in a line the postfix expression, with parentheses reflecting the precedences of the operators.There must be no space between any symbols.

### Sample Input 1:

```in
8
* 8 7
a -1 -1
* 4 1
+ 2 5
b -1 -1
d -1 -1
- -1 6
c -1 -1
```

### Sample Output 1:

```out
(((a)(b)+)((c)(-(d))*)*)
```

### Sample Input 2:

```in
8
2.35 -1 -1
* 6 1
- -1 4
% 7 8
+ 2 3
a -1 -1
str -1 -1
871 -1 -1
```

### Sample Output 2:

```out
(((a)(2.35)*)(-((str)(871)%))+)
```



## 7-4 Dijkstra Sequence (30 分)

Dijkstra's algorithm is one of the very famous greedy algorithms. It is used for solving the single source shortest path problem which gives the shortest paths from one particular source vertex to all the other vertices of the given graph. It was conceived by computer scientist Edsger W. Dijkstra in 1956 and published three years later.

In this algorithm, a set contains vertices included in shortest path tree is maintained. During each step, we find one vertex which is not yet included and has a minimum distance from the source, and collect it into the set. Hence step by step an ordered sequence of vertices, let's call it **Dijkstra sequence**, is generated by Dijkstra's algorithm.

On the other hand, for a given graph, there could be more than one Dijkstra sequence. For example, both { 5, 1, 3, 4, 2 } and { 5, 3, 1, 2, 4 } are Dijkstra sequences for the graph, where 5 is the source. Your job is to check whether a given sequence is Dijkstra sequence or not.

### Input Specification:

Each input file contains one test case. For each case, the first line contains two positive integers $N_v (\leq10^3)$ and $N_e(\leq10^5)$, which are the total numbers of vertices and edges, respectively. Hence the vertices are numbered from 1 to $N_v$.

Then $N_e$ lines follow, each describes an edge by giving the indices of the vertices at the two ends, followed by a positive integer weight ($\leq100$) of the edge. It is guaranteed that the given graph is connected.

Finally the number of queries, $K$, is given as a positive integer no larger than 100, followed by $K$ lines of sequences, each contains a permutationof the $N_v$ vertices. It is assumed that the first vertex is the source for each sequence.

All the inputs in a line are separated by a space.

### Output Specification:

For each of the $K$ sequences, print in a line `Yes` if it is a Dijkstra sequence, or `No` if not.

### Sample Input:

```in
5 7
1 2 2
1 5 1
2 3 1
2 4 1
2 5 2
3 5 1
3 4 1
4
5 1 3 4 2
5 3 1 2 4
2 3 4 5 1
3 2 1 5 4
```

### Sample Output:

```out
Yes
Yes
Yes
No
```

