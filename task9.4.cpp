#include <iostream>

// Функція виділення пам'яті та ініціалізації нулями
double** create_matrix(int n) {
    double** mat = new double*[n];
    for (int i = 0; i < n; ++i) {
        mat[i] = new double[n](); // () ініціалізує нулями
    }
    return mat;
}

// Функція очищення пам'яті
void free_matrix(double** mat, int n) {
    if (mat == nullptr) return;
    for (int i = 0; i < n; ++i) {
        delete[] mat[i];
    }
    delete[] mat;
}

int main() {
    int n;
    std::cout << "Введіть розмір квадратної матриці n: ";
    std::cin >> n;

    if (n <= 0) return 1;

    double** matrix = create_matrix(n);

    std::cout << "Матриця ініціалізована нулями. Введіть елементи:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Введена матриця:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }

    free_matrix(matrix, n);
    return 0;
}
