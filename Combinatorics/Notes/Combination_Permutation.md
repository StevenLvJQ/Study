# 排列组合（Combination and Permutation）
## 1. 计数问题分类
1. 计数对象的***有序***排列的个数或对象的***有序***选择的个数：
- 任何对象都不重复
- 允许对象重复（看可能是有限制的）
2. 计数对象的***无序***排列的个数或对象的***无序***选择的个数：
- 任何对象都不重复
- 允许对象重复（看可能是有限制的）

## 2. 排列（Permutation）
1. 考虑顺序的放置或选择，用 $P(n,r)$ 来表示 
2. $P(n,r) = n! / (n-r)!$
### 2.1 线性排列（线）
- 就是最基本的排列方式，将其看作一条线，首尾之间不连通
- $P(n,r) = n! / (n-r)!$
### 2.2 循环排列（圆）
- $n$ 个元素的循环 $r$ 排列为：$P(n,r)/r = n!/(r * (n-r)!)$
### 2.3 多重排列
- $S$ 集合中有 $k$ 种元素，其中元素每种元素的个数为 $n_1, n_2,...,n_k$ ，则 $S$ 的排列数为：$n!/(n_1!n_2!...n_k!)$
- $n$ 为正整数，且 $n_1+n_2+n_3+...+n_k=n$，将其划分成 $k$ 盒子：
    - 盒子有标签：$n!/(n_1!n_2!...n_k!)$ 例：蓝{a,b},红{c,d} 和 红{a,b},蓝{c,d} 是2种
    - 盒子没标签：$n!/(n_1!n_2!...n_k!k!)$ 例：上例中的两个变为一种（除以k!）


## 3. 组合（Conbination）
1. 与顺序无关的放置或选择，用 $C_n^r$ 来表示 
2. $C_n^r = \frac{P(n,r)}{r!}$

    - 性质1：$C_n^r = C_n^{n-r}$

    - 性质2：$C_n^k = C_{n-1}^k + C_{n-1}^{k-1}$（帕斯卡公式）

    - 性质3：$C_n^0 + C_n^1 + ... + C_n^{n-1} + C_n^n = 2^n$


### 3.1 多重组合
1. 正常形式
- $S$ 集合中有 $k$ 种元素，且每种元素有***无限个***时，则 $r$ 组合数为：$C_{r+k-1}^r=C_{r+k-1}^{k-1}$

- 将该模型看作时 $x_1+x_2+...+x_k=r$ 的非负整数的解的个数，r为总次数，$x_k$ 为元素 $a_k$ 出现的次数

- 相当于是***插隔板***，比如一共出现8次（$r$ =8），并且有分成四类（插3个板，即 $k$ = 4），则有11个位置可以插入，则从11个位置中选出3个位置。

2. 两个变体（上下界规定）
- 下界规定： 如果是至少出现一次呢？---> 则k不变，r减1
- 上界规定：不能直接使用，要使用 ***容斥原理***
