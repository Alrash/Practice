#116 Unidirectional TSP

##翻译来源
[116 翻译](http://luckycat.kshs.kh.edu.tw/homework/q116.htm)

##题目大意
给出一个n * m的矩阵，每个格子上都有一个数，每个格子可以水平向右走或者斜向右走，问和值最小为多少，并输出路径。补充条件：像rect\[x\]\[0\]可以走rect\[x + 1\]\[0],rect\[x\]\[0\],rect\[line\]\[0\]三个点。

##输入
輸入裡包含多組測試資料，每組代表一個方陣。每組測試資料的第一列為2個正整數 m 與 n （1 <= m <=10，1 <= n <= 100），依序表示這方陣有幾橫列和幾直行。而後就是 m*n 個整數，這些整數是按照「列順序」（ row major order ）來排列，也就是輸入裡的前 n 個數表示方陣的第一橫列，再下來的 n 個數表示第二橫列，依此類推。在輸入裡，同一列的數彼此間將會被一個以上的空白隔開。值得注意的是，這裡說的整數並不一定是正的。輸入以及計算的過程所出現的數均不會超過長整數（long）的範圍。

##输出
對於每個方陣，你必須輸出兩列東西。第一列是「最小重量路徑」（ minimal-weight path ），第二列則是其「重量」。對於第一列，你必須輸出 n 個正整數，依序表示在每一行，此路徑經過了第幾列。如果存在兩個以上的路徑其「重量」皆為最小，則輸出按照字典順序（ lexicographically ）最小的那一個路徑。請參考Sample Output。

##输入样例
```
5 6
3 4 1 2 8 6
6 1 8 2 7 4
5 9 3 9 9 5
8 4 1 3 2 6
3 7 2 8 6 4
5 6
3 4 1 2 8 6
6 1 8 2 7 4
5 9 3 9 9 5
8 4 1 3 2 6
3 7 2 1 2 3
2 2
9 10 9 10
```

##输出样例
```
1 2 3 4 4 5
16
1 2 1 5 4 5
11
1 1
19
```

##思路
竖过来看<br>
因为需要字典顺序，所以从右到左是最好的顺序

##文件说明
Unidirectional\ TSP.cpp可以输出路径，但未检测

116.cpp只有最短路径长度