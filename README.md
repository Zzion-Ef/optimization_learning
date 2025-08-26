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
  1. 问题描述


     $$
     f(x_1,x_2) = (x_1 - 1)^2 + (x_2-1)^2 \\ s.t. 0\leq x_1\leq1.5;0\leq x_2\leq1.5
     $$


     求： $f_{min}$，以及令 $f=f_{min}$ 时的 $x_1,x_2$


  3. 问题分析
      1. 将目标函数转化成标准形式：

          
      2. 将约束转化成向量形式
         
  4. 对应代码
  5. 运行结果


