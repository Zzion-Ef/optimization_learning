# osqp,osqp-eigen环境配置

📏**osqp，osqp-eigen求解的问题的标准形式:**

<img width="1486" height="574" alt="image" src="https://github.com/user-attachments/assets/26fa458c-b9b4-4e70-aac1-ab025f3e09b6" />


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

[ 自动驾驶中的数学：二次规划求解库概述\_哔哩哔哩\_bilibili 自动驾驶中的数学：二次规划求解库概述, 视频播放量 597、弹幕量 0、点赞数 14、投硬币枚数 6、收藏人数 20、转发人数 0, 视频作者 C哥智驾说, 作者简介 华南理工硕士，自动驾驶算法工程师，讲师，深耕智驾算法多年，致力于为想入行自动驾驶的朋友提供价值。主页有好课。，相关视频：自动驾驶中的数学：优化问题，【开源】一个超简易强化学习自动驾驶Carla环境发布了，【南开大学25C++】C++ https://www.bilibili.com/video/BV1L2u7z7Egp/?spm\_id\_from=333.1387.upload.video\_card.click](https://www.bilibili.com/video/BV1L2u7z7Egp/?spm_id_from=333.1387.upload.video_card.click " 自动驾驶中的数学：二次规划求解库概述_哔哩哔哩_bilibili 自动驾驶中的数学：二次规划求解库概述, 视频播放量 597、弹幕量 0、点赞数 14、投硬币枚数 6、收藏人数 20、转发人数 0, 视频作者 C哥智驾说, 作者简介 华南理工硕士，自动驾驶算法工程师，讲师，深耕智驾算法多年，致力于为想入行自动驾驶的朋友提供价值。主页有好课。，相关视频：自动驾驶中的数学：优化问题，【开源】一个超简易强化学习自动驾驶Carla环境发布了，【南开大学25C++】C++ https://www.bilibili.com/video/BV1L2u7z7Egp/?spm_id_from=333.1387.upload.video_card.click")

📌**project1：简单的二元二次规划（凸函数+凸约束）**

1. 问题描述
   $$
   f(x_1,x_2) = (x_1 - 1)^2 + (x_2-1)^2 \\s.t. 0\leq x_1\leq1.5;0\leq x_2\leq1.5
   $$
   求：$f_{min}
    $，以及令$f=f_{min}$ 时的$x_1,x_2$
2. 问题分析
   1. 将目标函数转化成标准形式：
      $$
      f(x_1,x_2)=x_1^2 + x_2^2 -2x_1 -2x_2+2
      $$
      其中最后的“2”为常数项，不影响取到最小值时的坐标，因此可以省略，并转成标准形式：
      $$
      f(x_1,x_2)=x_1^2 + x_2^2 -2x_1 -2x_2\\\\
      = \frac{1}{2}
      \begin{bmatrix} x_1\\
      x_2\\
      \end{bmatrix}^T

      \begin{bmatrix} 2&0\\
      0&2\\
      \end{bmatrix}

      \begin{bmatrix} x_1\\
      x_2\\
      \end{bmatrix} + 

      \begin{bmatrix} -2\\
      -2\\
      \end{bmatrix}^T


      \begin{bmatrix} x_1\\
      x_2\\
      \end{bmatrix}  
      $$
   2. 将约束转化成向量形式
      $$

      \begin{bmatrix} 0\\
      0\\
      \end{bmatrix}

      \leq
      \begin{bmatrix} 1&0\\
      0&1\\
      \end{bmatrix}

      \begin{bmatrix} x_1\\
      x_2\\
      \end{bmatrix} 

      \leq

      \begin{bmatrix} -2\\
      -2\\
      \end{bmatrix}
         
      $$
   综上，可以得到标准形式里各矩阵对应的值：
   $$
   P=\begin{bmatrix} 2&0\\
   0&2\\
   \end{bmatrix}\\
   \\
   q=\begin{bmatrix} -2\\
   -2\\
   \end{bmatrix}\\

   l=\begin{bmatrix} 0\\
   0\\
   \end{bmatrix}\\

   A=\begin{bmatrix} 1&0\\
   0&1\\
   \end{bmatrix}\\

   u=\begin{bmatrix} -2\\
   -2\\
   \end{bmatrix}\\ 
   $$
3. 对应代码
   ```c++ 
       Eigen::SparseMatrix<double> P(2, 2);
       Eigen::VectorXd Q(2);
       Eigen::SparseMatrix<double> A(2, 2);
       Eigen::VectorXd lowerBound(2);
       Eigen::VectorXd upperBound(2);
       
       /* 填充P矩阵 */
       P.insert(0, 0) = 2.0;
       P.insert(1, 1) = 2.0;

       /* 填充Q向量 */
       Q << -2.0, -2.0;

       /* 填充A矩阵 */
       A.insert(0, 0) = 1.0;
       A.insert(1, 1) = 1.0;

       /* 填充上下界向量 */
       lowerBound << 0.0, 0.0;
       upperBound << 1.5, 1.5;


       // 创建求解器
       OsqpEigen::Solver solver;

       // 求解器设置，提升求解速度
       solver.settings()->setVerbosity(false);
       solver.settings()->setWarmStart(true);

       // 初始化求解器，填充各矩阵数据
       solver.data()->setNumberOfVariables(2);
       solver.data()->setNumberOfConstraints(2);
       if (!solver.data()->setHessianMatrix(P)) return 1;
       if (!solver.data()->setGradient(Q)) return 1;
       if (!solver.data()->setLinearConstraintsMatrix(A)) return 1;
       if (!solver.data()->setLowerBound(lowerBound)) return 1;
       if (!solver.data()->setUpperBound(upperBound)) return 1;
   ```

4. 运行结果
   ```c++ title="求解器的调用"
       // 求解
       Eigen::VectorXd solution;
       if (solver.solveProblem() != OsqpEigen::ErrorExitFlag::NoError) return 1;
       solution = solver.getSolution();
       std::cout<<"\033[32mOptimal solution found:\n" << solution << "\033[0m\n";
       return 0;
   ```

   <img width="406" height="108" alt="image" src="https://github.com/user-attachments/assets/b77f53be-82b9-4dbd-9b1c-0c10e5adcd40" />
