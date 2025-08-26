
#include <OsqpEigen/OsqpEigen.h>
#include <Eigen/Dense>

#include <iostream>

int main() {
    std::cout << "OSQP-Eigen project template initialized successfully111111!" << std::endl;
    
    Eigen::SparseMatrix<double> P(2, 2);
    Eigen::VectorXd Q(2);
    Eigen::SparseMatrix<double> A(2, 2);
    Eigen::VectorXd lowerBound(2);
    Eigen::VectorXd upperBound(2);

    P.insert(0, 0) = 2.0;
    P.insert(1, 1) = 2.0;
    std::cout << "P matrix:\n" << Eigen::MatrixXd(P) << std::endl;

    Q << -2.0, -2.0;
    std::cout << "Q vector:\n" << Q << std::endl;

    A.insert(0, 0) = 1.0;
    A.insert(1, 1) = 1.0;
    std::cout << "A matrix:\n" << Eigen::MatrixXd(A) << std::endl;

    lowerBound << 0.0, 0.0;
    upperBound << 1.5, 1.5;
    std::cout << "Lower bound:\n" << lowerBound << std::endl;
    std::cout << "Upper bound:\n" << upperBound << std::endl;

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


    if (!solver.initSolver()) return 1;

    // 求解
    Eigen::VectorXd solution;
    if (solver.solveProblem() != OsqpEigen::ErrorExitFlag::NoError) return 1;
    solution = solver.getSolution();
    std::cout<<"\033[32mOptimal solution found:\n" << solution << "\033[0m\n";
    return 0;
}