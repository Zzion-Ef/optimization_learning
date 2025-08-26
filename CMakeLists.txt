cmake_minimum_required(VERSION 3.12)
project(optimization_learning)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 指定Eigen和OSQP-Eigen的头文件路径
find_package(Eigen3 REQUIRED)
find_package(OsqpEigen REQUIRED)

# 添加子项目
add_subdirectory(src/project1)