📏**osqp，osqp-eigen求解的问题的标准形式:**

  ![](https://secure2.wostatic.cn/static/b4fGT9bVXC458VAi1PftHk/image.png?auth_key=1756186845-i7aQKkUN3YGZgTAi4Yf3Hr-0-5cdf349f4d7a5ebf0e30cbb7ee67a8e1)

  **问题描述：**

  OSQP 求解如下形式的凸二次规划（QPs）问题：

$$
\begin{aligned}\\& min \quad \frac{1}{2} x^{T} P x + q^{T} x \\& s.t. \quad l \leq A x \leq u\\\end{aligned}
$$

  其中$x\in\mathbf{R}^{n}$ 是优化变量。

  目标函数由半正定矩阵$P \in \mathbf{S}^{n}_{+}$ 和向量$q\in\mathbf{R}^{n}$ 定义。

  线性约束由矩阵$A \in \mathbf{R}^{m \times n}$ 以及向量$l$ 和$u
 $ 定义。

  使得对于所有$i \in \{1, \ldots, m\}$，有$l_{i} \in \mathbf{R} \cup\{-\infty\}$ 且$u_{i} \in \mathbf{R} \cup\{-\infty\}$

🔧**环境配置**

  ubuntu 22.04 + eigen v3.4.0 + osqp v1.0.0 + osqp-eigen v0.10.0

  ❗注意：推荐使用上述eigen和osqp和osqp-eigen的版本，亲测这些版本相互兼容，若使用其他版本，可能存在版本不兼容导致编译报错的现象

  关于三方库的安转及更新方法，推荐参考b站视频：

  https://www.bilibili.com/video/BV1L2u7z7Egp/?spm_id_from=333.1387.upload.video_card.click

📌**project1：简单的二元二次规划（凸函数+凸约束）**
  1. 问题描述

$$
f(x_1,x_2) = (x_1 - 1)^2 + (x_2-1)^2 \\s.t. 0\leq x_1\leq1.5;0\leq x_2\leq1.5
$$

      求：$f_{min}
 $，以及令$f=f_{min}$ 时的$x_1,x_2$
  2. 问题分析
      1. 将目标函数转化成标准形式：

          
      2. 将约束转化成向量形式
  3. 对应代码
  4. 运行结果


