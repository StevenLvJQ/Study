# 生成函数（Generating_Functions）
## 1. 求解递推式
- 全部展开，进行运算
- 使用特征根的方式进行：令 $f_n=q^n$ 然后取带入解出 $q$ 的值（对于 $f_n-f_{n-1}-f_{n-2}=0$ 这样类型的式子的求解）
## 2. 生成函数（用于组合！！！）
可以把生成函数看成是代数对象，其形式上的处理使得人们可以通过代数手段计算一个问题的可能性的数目。***生成函数是无线可微分函数的泰勒级数（幂级数展开）***

### 2.1 生成函数的定义
- 设 $h_0, h_1,...,h_n,...$ 是一个无穷数列。它的生成函数定义为无穷级数 $g(x)=h_0+h_1x+h_2x^2+...+h_nx^n+...$，$x^n$ 充当 $h_n$ 的占位符。

- 有穷数列可以看作一个无穷数列，将后面所有项都当作0即可。

### 2.2 几个特殊必须记住的生成函数
1. $g(x)=\frac{1}{1-x}=1+x+x^2+...+x^k+...$
2. $g_m(x)=(1+x)^m=C_m^0+C_m^1x+C_m^2x^2+...+C_m^mx^m$
3. $g(x)=\frac{1}{(1-x)^k}=\sum_{n=0}^\infty C_{n+k-1}^{k-1}x^n$（非负整数解模型）
4. 最重要得公式（公式3的变体）：$g(x)=\frac{1}{(1-rx)^k}=\sum_{n=0}^\infty C_{n+k-1}^{k-1}x^n$

### 2.3 经典应用
一般思路：建模-->生成函数-->计算-->结果化为一般形式-->求对应系数
1. 有穷上界的非负整数解问题
2. 有要求的多重组合问题

## 3. 指数生成函数（用于排列！！！）
### 3.1 指数生成函数的定义
- 关于单项式集合的生成函数称为指数生成函数，对于数列 $h_0,h_1,h_2,...,h_n,...$ 的指数生成函数为：$g^{(e)}=\sum_{n=0}^\infty h_n\frac{x^n}{n!}$

- 对于单项式集合 ${1,x,\frac{x^2}{2}!,\frac{x^3}{3},...,\frac{x^n}{n},...}$，出现在泰勒级数 $e^x=\sum_{n=0}^\infty x^n/n!$

### 3.2 几个特殊必须记住的指数生成函数
1. $g^{(e)}=\sum_{n=0}^\infty \frac{x^n}{n!}=e^x$
2. $g^{(e)}=\sum_{n=0}^\infty \frac{a^nx^n}{n!}=e^{ax}$

## 4. 求解线性齐次递推关系
方法：特征根方法（其中 $b_n=0$ ,且 $a_1,a_2,...,a_k$ 为常数，即$h_n=a_1h_{n-1}+a_2h_{n-2}+...+a_kh_{n-k}$）
- ***无重根***的特征根法
- ***有重根***的特征根法
### 4.1 无重根的特征根法
- 将（递推公式） $h_n=c_{n-1}h_{n-1}+c_{n-2}h_{n-2}+...+c_{n-k}h_{n-k}$ 化为（对应的特征方程） $x^{n-k}=c_{n-1}x^{n-k-1}+...+c_{n-k+1}x+c_{n-k}$
- 将该方程求解，得出的结果为 $q_1,q_2,...,q_k$，则（通解） $h_n=t_1q_1^n+t_2q_2^n+...+t_kq_k^n$，其中 $t_k为常数$  
### 4.2 有重根的特征根法
- 将（递推公式） $h_n=c_{n-1}h_{n-1}+c_{n-2}h_{n-2}+...+c_{n-k}h_{n-k}$ 化为（对应的特征方程） $x^{n-k}=c_{n-1}x^{n-k-1}+...+c_{n-k+1}x+c_{n-k}$
- 将该方程求解，得出的结果为 $q_1,q_2,...,q_k$，其中 $q_k$ 有 $s_k$ 重根，则该根 $q_k$ 对应的解空间为：$H_k=c_1q_k^n+c_2nq_k^n+...+c_sn^{s-1}q_k^n$，且该递推式的通解为：$h_n=H_1+H_2+...+H_t$，其中 $k=s_1+...+s_t$，$t$ 为重根的种类
### 4.3 用生成函数来求解 $h_n$（不需要分是否有重根）
构造很重要！！！！

1. 令 $g(x)=h_0+h_1x+h_2x^2+...+h_nx^n+...$，将h_n形式转化为生成函数形式
2. 递推式为 $h_n=c_{n-1}h_{n-1}+c_{n-2}h_{n-2}+...+c_{n-k}h_{n-k}$
3. 去构造 $(h_n-c_{n-1}h_{n-1}-c_{n-2}h_{n-2}-...-c_{n-k}h_{n-k})x^n$ 这样的项
4. 然后利用 $h_n-c_{n-1}h_{n-1}-c_{n-2}h_{n-2}-...-c_{n-k}h_{n-k}=0$ 去得出简化后的 $g(x)$
5. 因式分解（在有重根和无重根的时候会有所区别） + 待定系数 + 生成函数转化为 $h_n$ 形式