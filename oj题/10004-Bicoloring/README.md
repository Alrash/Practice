#10004 Bicoloring

##题目大意
使用2种颜色，使得图上相邻的两个节点颜色不同，可以输出“BICOLORABLE.”，不可以输出“NOT BICOLORABLE.”

##输入
n 节点数<br>
m 边数<br>
边的具体连接情况<br>
...<br>
0

##输出
BICOLORABLE.or NOT BICOLORABLE.

##输入样例
```
3
3
0 1
1 2
2 0
9
8
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8
0
```

##输出样例
```
NOT BICOLORABLE.
BICOLORABLE.
```

##思路
使用广度优先，将下一节点设为不同值，在访问过的结点若获得visit[now] == visit[parent]（实际上是指now节点的下一个结点，但是这个结点比较特殊，它与now和now的父节点(父节点)形成环路），则输出NOT BICOLORABLE.
