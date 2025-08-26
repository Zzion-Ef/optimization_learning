📏**osqp，osqp-eigen求解的问题的标准形式:**

  ![](https://secure2.wostatic.cn/static/b4fGT9bVXC458VAi1PftHk/image.png?auth_key=1756186845-i7aQKkUN3YGZgTAi4Yf3Hr-0-5cdf349f4d7a5ebf0e30cbb7ee67a8e1)

  **问题描述：**
![](https://secure2.wostatic.cn/static/fjWiUndYqLu5G49ZuP8BEc/c6a18c5ddbcd609ddd9172345a55a6a7.jpg?auth_key=1756187240-45x1QC45BBsozpY4PLxQ5T-0-ebf6b4d5f493160db71955972cdb0dc5)

🔧**环境配置**

  ubuntu 22.04 + eigen v3.4.0 + osqp v1.0.0 + osqp-eigen v0.10.0

  ❗注意：推荐使用上述eigen和osqp和osqp-eigen的版本，亲测这些版本相互兼容，若使用其他版本，可能存在版本不兼容导致编译报错的现象

  关于三方库的安转及更新方法，推荐参考b站视频：

  https://www.bilibili.com/video/BV1L2u7z7Egp/?spm_id_from=333.1387.upload.video_card.click

📌**project1：简单的二元二次规划（凸函数+凸约束）**
  1. 问题描述\
     $$f(x_1,x_2) = (x_1 - 1)^2 + (x_2-1)^2 $$\
     $$s.t. 0\leq x_1\leq1.5;0\leq x_2\leq1.5$$


     求： $f_{min}$，以及令 $f=f_{min}$ 时的 $x_1,x_2$

  2. 问题分析

a. 将目标函数转化成标准形式

$$ f\left(x_{1}, x_{2}\right)=x_{1}^{2}+x_{2}^{2}-2 x_{1}-2 x_{2}+2 $$

其中最后的"2"为常数项，不影响取到最小值时的坐标，因此可以省略，并转成标准形式：

$$ f\left(x_{1}, x_{2}\right)=x_{1}^{2}+x_{2}^{2}-2 x_{1}-2 x_{2} $$

$$ =\frac{1}{2} \left[\begin{array}{ll}
x_{1} \\
x_{2}
\end{array}\right]^{T} \left[\begin{array}{cc}
2 & 0 \\
0 & 2
\end{array}\right] \left[\begin{array}{l}
x_{1} \\
x_{2}
\end{array}\right]+\left[\begin{array}{cc}
-2 & -2
\end{array}\right]^{T} \left[\begin{array}{l}
x_{1} \\
x_{2}
\end{array}\right] $$

b. 将约束转化成向量形式

$$ \left[\begin{array}{l}
0 \\
0
\end{array}\right] \leq \left[\begin{array}{ll}
1 & 0 \\
0 & 1
\end{array}\right] \left[\begin{array}{l}
x_{1} \\
x_{2}
\end{array}\right] \leq \left[\begin{array}{l}
-2 \\
-2
\end{array}\right] $$

c. 标准形式矩阵表示

综上，可以得到标准形式里各矩阵对应的值：

$$
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
-2 \\
-2
\end{array}\right]
\end{array}
$$
         
  4. 对应代码
  5. 运行结果


