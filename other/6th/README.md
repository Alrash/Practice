<h1 align="center">2015蓝桥杯省赛B组</h1>

##部分说明
3_耗时.cpp采用暴力解法，第三题的本质是对于0-9全排列，取连续9个数(即0-8号或1-9号)，得到满足的值，暴力解法是从00000000-99999999全部寻找一遍;想要非耗时的，两种方案：

> * 一.分制，全排列
> * 二.c++下使用algorithm头文件下的next_permutation(a, a + n)

7_耗时.cpp没有想出动态规划怎么写

10.cpp树形dp，借鉴了一下别人的

##题目链接
http://blog.csdn.net/code4101/article/details/44997049

第十题题目：<br>
http://blog.csdn.net/u013008291/article/details/45014015
