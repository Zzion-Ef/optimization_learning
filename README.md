OSQP 与 OSQP-Eigen 求解的问题标准形式

Problem statement

OSQP solves convex quadratic programs (QPs) of the form

 \text { minimize } \quad \frac{1}{2} x^{T} P x+q^{T} x 

 \text { subject to } \quad l \leq A x \leq u 

where   x \in \mathbf{R}^{n}   is the optimization variable. The objective function is defined by a positive semidefinite matrix  P \in \mathbf{S}_{+}^{n}  and vector  q \in \mathbf{R}^{n} . The linear constraints are defined by matrix  A \in \mathbf{R}^{m \times n}  and vectors l and u so that  l_{i} \in \mathbf{R} \cup\{-\infty\}  and  u_{i} \in \mathbf{R} \cup\{+\infty\}  for all  i \in \{1, \ldots, m\} .

问题描述

OSQP求解如下形式的凸二次规划(QPs)问题：

 \text { min } \quad \frac{1}{2} x^{T} P x+q^{T} x 

 \text { s.t. } \quad l \leq A x \leq u 

其中 x \in \mathbf{R}^{n} 是优化变量。

目标函数由半正定矩阵 P \in \mathbf{S}_{+}^{n} 和向量 q \in \mathbf{R}^{n} 定义。

线性约束由矩阵 A \in \mathbf{R}^{m \times n} 以及向量l和u定义。

使得对于所有 i \in\{1, \ldots, m\} ，有 l_{i} \in \mathbf{R} \cup\{-\infty\} 且 u_{i} \in \mathbf{R} \cup\{+\infty\} 。

环境配置

ubuntu 22.04 + eigen v3.4.0 + osqp v1.0.0 + osqp - eigen v0.10.0

注意：推荐使用上述 eigen 和 osqp 和 osqp - eigen 的版本，亲测这些版本相互兼容，若使用其他版本，可能存在版本不兼容导致编译报错的现象

关于三方库的安装及更新方法，推荐参考 b 站视频：

https://www.bilibili.com/video/BV1Fz421R7cN/

自动驾驶中的数学：二次规划求解库概述，视频播放量 597、弹幕量 0、点赞数 14、投硬币枚数 6、收藏人数 20、转发人数 0，视频作者 C 哥智驾说，作者简介 华南理工硕士，自动驾驶算法工程师，讲师，深耕智驾算法 www.bilibili.com

Project1：简单的二元二次规划（凸函数 + 凸约束）

1. 问题描述

 f(x_1, x_2) = (x_1 - 1)^2 + (x_2 - 1)^2 
 s.t. 0 \leq x_1 \leq 1.5; 0 \leq x_2 \leq 1.5 

求： f_{min} ，以及令  f = f_{min}  时的  x_1, x_2 

2. 问题分析

a. 将目标函数转化成标准形式

 f(x_1, x_2) = x_1^2 + x_2^2 - 2x_1 - 2x_2 + 2 

其中最后的 "2" 为常数项，不影响取到最小值时的坐标，因此可以省略，并转成标准形式：

 f(x_1, x_2) = x_1^2 + x_2^2 - 2x_1 - 2x_2 
 = \frac{1}{2} \begin{bmatrix}x_1 \\x_2 \end{bmatrix}^T \begin{bmatrix}2 & 0 \\0 & 2 \end{bmatrix} \begin{bmatrix}x_1 \\x_2 \end{bmatrix} + \begin{bmatrix}-2 \\-2 \end{bmatrix}^T \begin{bmatrix}x_1 \\x_2 \end{bmatrix} 

b. 将约束转化成向量形式

 \left[\begin{array}{l}
0 \\
0
\end{array}\right] \leq \left[\begin{array}{ll}
1 & 0 \\
0 & 1
\end{array}\right] \left[\begin{array}{l}
x_1 \\
x_2
\end{array}\right] \leq \left[\begin{array}{l}
1.5 \\
1.5
\end{array}\right] 

3. 标准形式矩阵表示

综上，可以得到标准形式里各矩阵对应的值：

\begin{array}{l}
P=\left[\begin{array}{ll}
2 & 0 \\
0 & 2
\end{array}\right] \\
q=\left[\begin{array}{c}
-2 \\
-2
\end{array}\right] \\
l=\left[\begin{array}{l}
0 \\
0
\end{array}\right] \\
A=\left[\begin{array}{ll}
1 & 0 \\
0 & 1
\end{array}\right] \\
u=\left[\begin{array}{l}
1.5 \\
1.5
\end{array}\right]
\end{array}
