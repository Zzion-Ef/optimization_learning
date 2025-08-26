# 创建可执行文件
add_executable(project1 main.cpp)

# 链接Eigen和OSQP-Eigen库
target_link_libraries(project1
    OsqpEigen::OsqpEigen
    Eigen3::Eigen
)

# 设置可执行文件输出路径
set_target_properties(project1 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)