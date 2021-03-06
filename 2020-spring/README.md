# PAT（甲级）2020年春季考试

## 难点分析

1. 第一题素数判断，有手就行。

2. 第二题哈希，我一开始用了两个 `unordered_set` ，超时了，去掉一个就 AC 了。

3. 第三题遍历图的所有边，很少有这么水的图论题目了吧。

4. 第四题我只过了前三个测试点，最后参考了别人的[分析和代码](https://segmentfault.com/a/1190000038377906)。

   

## 7-1 Prime Day (20 分)

![](../images/sexy-prime.jpg)

The above picture is from Sina Weibo, showing May 23rd, 2019 as a very cool "Prime Day". That is, not only that the corresponding number of the date `20190523` is a prime, but all its sub-strings ended at the last digit `3` are prime numbers.

Now your job is to tell if a given date is a Prime Day.

### Input Specification:

Each input file contains one test case. For each case, a date between January 1st, 0001 and December 31st, 9999 is given, in the format `yyyymmdd`.

### Output Specification:

For each given date, output in the decreasing order of the length of the substrings, each occupies a line. In each line, print the string first, followed by a space, then `Yes` if it is a prime number, or `No` if not. If this date is a Prime Day, print in the last line `All Prime!`.

### Sample Input 1:

```in
20190523
```

### Sample Output 1:

```out
20190523 Yes
0190523 Yes
190523 Yes
90523 Yes
0523 Yes
523 Yes
23 Yes
3 Yes
All Prime!
```

### Sample Input 2:

```in
20191231
```

### Sample Output 2:

```out
20191231 Yes
0191231 Yes
191231 Yes
91231 No
1231 Yes
231 No
31 Yes
1 No
```





## 7-2 The Judger (25 分)

A game of numbers has the following rules: at the beginning, two distinct positive integers are given by the judge. Then each player in turn must give a number to the judge. The number must be the difference of two numbers that are previously given, and must not be duplicated to any of the existed numbers. The game will run for several rounds. The one who gives a duplicate number or even a wrong number will be kicked out.

Your job is to write a judger program to judge the players' numbers and to determine the final winners.

### Input Specification:

Each input file contains one test case. For each case, the first line gives two distinct positive integers to begin with. Both numbers are in $[1,10^5]$.

In the second line, two numbers are given:$N (2\leq N\leq10)$, the number of players, and ,$M (2\leq M\leq10^3)$ the number of rounds.

Then $N$ lines follow, each contains $M$ positive integers. The $i$-th line corresponds to the $i$-th player $(i=1,⋯,N)$. The game is to start from the 1st player giving his/her 1st number, followed by everybody else giving their 1st numbers in the 1st round; then everyone give their 2nd numbers in the 2nd round, and so on so forth.

### Output Specification:

If the `i`-th player is kicked out in the `k`-th round, print in a line `Round #k: i is out.`. The rest of the numbers given by the one who is out of the game will be ignored. If more than one player is out in the same round, print them in increasing order of their indices. When the game is over, print in the last line `Winner(s): W1 W2 ... Wn`, where `W1 ... Wn` are the indices of the winners in increasing order. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the beginning or the end of the line. If there is no winner, print `No winner.` instead.

### Sample Input 1:

```in
101 42
4 5
59 34 67 9 7
17 9 8 50 7
25 92 43 26 37
76 51 1 41 40
```

### Sample Output 1:

```out
Round #4: 1 is out.
Round #5: 3 is out.
Winner(s): 2 4
```

### Sample Input 2:

```in
42 101
4 5
59 34 67 9 7
17 9 18 50 49
25 92 58 1 39
102 32 2 6 41
```

### Sample Output 2:

```out
Round #1: 4 is out.
Round #3: 2 is out.
Round #4: 1 is out.
Round #5: 3 is out.
No winner.
```





## 7-3 Safari Park (25 分)

A safari park（野生动物园）has $K$ species of animals, and is divided into $N$ regions. The managers hope to spread the animals to all the regions, but not the same animals in the two neighboring regions. Of course, they also realize that this is an NP complete problem, you are not expected to solve it. Instead, they have designed several distribution plans. Your job is to write a program to help them tell if a plan is feasible.

### Input Specification:

Each input file contains one test case. For each case, the first line gives 3 integers: $N (0\leq N\leq500)$, the number of regions; $R (\leq0)$, the number of neighboring relations, and $K (0<K\leq N)$, the number of species of animals. The regions and the species are both indexed from 1 to $N$.

Then *R* lines follow, each gives the indices of a pair of neighboring regions, separated by a space.

Finally there is a positive $M (\leq20)$ followed by $M$ lines of distribution plans. Each plan gives $N$ indices of species in a line (the $i$-th index is the animal in the $i$-th rigion), separated by spaces. It is guaranteed that any pair of neighboring regions must be different, and there is no duplicated neighboring relations.

### Output Specification:

For each plan, print in a line `Yes` if no animals in the two neighboring regions are the same, or `No` otherwise. However, if the number of species given in a plan is not $K$, you must print `Error: Too many species.` or `Error: Too few species.` according to the case.

### Sample Input:

```in
6 8 3
2 1
1 3
4 6
2 5
2 4
5 4
5 6
3 6
5
1 2 3 3 1 2
1 2 3 4 5 6
4 5 6 6 4 5
2 3 4 2 3 4
2 2 2 2 2 2
```

### Sample Output:

```out
Yes
Error: Too many species.
Yes
No
Error: Too few species.
```





## 7-4 Replacement Selection (30 分)

When the input is much too large to fit into memory, we have to do **external sorting** instead of internal sorting. One of the key steps in external sorting is to generate sets of sorted records (also called **runs**) with limited internal memory. The simplest method is to read as many records as possible into the memory, and sort them internally, then write the resulting run back to some tape. The size of each run is the same as the capacity of the internal memory.

**Replacement Selection** sorting algorithm was described in 1965 by Donald Knuth. Notice that as soon as the first record is written to an output tape, the memory it used becomes available for another record. Assume that we are sorting in ascending order, if the next record is not smaller than the record we have just output, then it can be included in the run.

For example, suppose that we have a set of input { 81, 94, 11, 96, 12, 99, 35 }, and our memory can sort 3 records only. By the simplest method we will obtain three runs: { 11, 81, 94 }, { 12, 96, 99 } and { 35 }. According to the replacement selection algorithm, we would read and sort the first 3 records { 81, 94, 11 } and output 11 as the smallest one. Then one space is available so 96 is read in and will join the first run since it is larger than 11. Now we have { 81, 94, 96 }. After 81 is out, 12 comes in but it must belong to the next run since it is smaller than 81. Hence we have { 94, 96, 12 } where 12 will stay since it belongs to the next run. When 94 is out and 99 is in, since 99 is larger than 94, it must belong to the **first run**. Eventually we will obtain two runs: the first one contains { 11, 81, 94, 96, 99 } and the second one contains { 12, 35 }.

Your job is to implement this replacement selection algorithm.

### Input Specification:

Each input file contains several test cases. The first line gives two positive integers $N (\leq10^5)$ and $M (<N/2)$, which are the total number of records to be sorted, and the capacity of the internal memory. Then $N$ numbers are given in the next line, all in the range of **int**. All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print in each line a run (in ascending order) generated by the replacement selection algorithm. All the numbers in a line must be separated by exactly 1 space, and there must be no extra space at the beginning or the end of the line.

### Sample Input:

```in
13 3
81 94 11 96 12 99 17 35 28 58 41 75 15
```

### Sample Output:

```out
11 81 94 96 99
12 17 28 35 41 58 75
15
```

