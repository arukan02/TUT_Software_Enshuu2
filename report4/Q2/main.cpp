#include <iostream>
#include <Eigen/Dense>

int main() {
    // Define vectors a and b
    Eigen::VectorXd a(3);
    Eigen::VectorXd b(3);

    a << 1, 2, 3;
    b << 4, 5, 6;

    // Define matrices A and B
    Eigen::MatrixXd A(3, 3);
    Eigen::MatrixXd B(3, 3);

    A << 1, 2, 3,
         4, 5, 6,
         7, 8, 9;

    B << 9, 8, 7,
         6, 5, 4,
         3, 2, 1;

    // Output the vectors and matrices
    std::cout << "Vector a:\n" << a << "\n\n";
    std::cout << "Vector b:\n" << b << "\n\n";
    std::cout << "Matrix A:\n" << A << "\n\n";
    std::cout << "Matrix B:\n" << B << "\n\n";

    // Vector addition: a + b
    Eigen::VectorXd vector_sum = a + b;
    std::cout << "a + b =\n" << vector_sum << "\n\n";

    // Outer product of vectors: a * b^T
    Eigen::MatrixXd outer_product = a * b.transpose();
    std::cout << "a * b^T =\n" << outer_product << "\n\n";

    // Dot product of vectors: a^T * b
    double dot_product = a.transpose() * b;
    std::cout << "a^T * b = " << dot_product << "\n\n";

    // Matrix-vector multiplication: A * b
    Eigen::VectorXd matrix_vector_product = A * b;
    std::cout << "A * b =\n" << matrix_vector_product << "\n\n";

    // Matrix-matrix multiplication: A * B
    Eigen::MatrixXd matrix_matrix_product = A * B;
    std::cout << "A * B =\n" << matrix_matrix_product << "\n\n";

    return 0;
}
