# 容斥原理（The Principle of Inclusion and Exclusion）
## 1. 容斥原理内容
集合 $S$ 中不具有性质 $P_1$ ,..., $P_m$ 的对象个数:
- 形式1：$|\overline A_1\cap\overline A_2\cap...\cap\overline A_m|=|S|-\sum|A_i|+\sum|A_i\cap A_j|+...+(-1)^m|A_1\cap A_2\cap...\cap A_m|$
- 形式2：$|A_1\cup A_2\cup...\cup A_m|=\sum|A_i|-\sum|A_i\cap A_j|+...+(-1)^{m+1}|A_1\cap A_2\cap...\cap A_m|$

## 2. 经典例题
1. 1-500个整数，能被3或5整除的个数
2. 求不超过120的素数的个数
3. abcdef的全排列中不允许出现ace和df的情况
4. abcd构成n为符号串，abc都至少出现一次
5. $x_1+x_2+x_3=15$ 的非负整数解的数目，且其中 $0\leq x_1\leq 5, 0\leq x_2\leq 6, 0\leq x_3\leq 7$（加了上界限制）（容斥原理 + 生成函数）
6. 第二类 $stirling$ 数

## 3. 错位排序
### 3.1 错位排序的定义
&emsp;&emsp;给定 $n$ 元素的集合 $X$，它的每一个元素都有一个特定的位置，而现在要求求出集合 $X$ 的排列中没有一个元素在它指定位置上的排列数目
### 3.2 错位排序公式及其推导
- 先给出错位排序公式：$D_n=n!(1-\frac{1}{1!}+\frac{2}{2!}-\frac{3}{3!}+...+(-1)^n\frac{1}{n!})$
- 推导过程：错位排序相当于 $D_n=|\overline A_1\cap\overline A_2\cap...\cap\overline A_n|$，则通过容斥原理可以得到，$|Ai|=(n-1)!$，$|A_i\cap A_j|=(n-2)!$，同理得 $|A_{i1}\cap A_{i2}\cap ...\cap A_{ik}|=(n-k)!$，则有 $D_n=n!-C_n^1(n-1)!+C_n^2(n-2)!+...+(-1)^nC_n^n0!$，最后化简得到上式

