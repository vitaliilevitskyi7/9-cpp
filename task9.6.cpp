#include <iostream>

// Функція для динамічного створення однієї матриці M x N
double** create_matrix(int m, int n) {
    double** mat = new double*[m];
    for (int i = 0; i < m; ++i) {
        mat[i] = new double[n](); // Ініціалізація нулями
    }
    return mat;
}

// Функція для очищення пам'яті однієї матриці
void free_matrix(double** mat, int m) {
    if (mat == nullptr) return;
    for (int i = 0; i < m; ++i) {
        delete[] mat[i];
    }
    delete[] mat;
}

// Функція для очищення пам'яті всього масиву з count матриць
void free_all_matrices(double*** array_of_matrices, int count, int m) {
    if (array_of_matrices == nullptr) return;
    for (int k = 0; k < count; ++k) {
        free_matrix(array_of_matrices[k], m);
    }
    delete[] array_of_matrices;
}

int main() {
    int count, m, n;
    std::cout << "Введіть кількість матриць у масиві: ";
    std::cin >> count;
    std::cout << "Введіть розміри матриць M та N (через пробіл): ";
    std::cin >> m >> n;

    if (count <= 0 || m <= 0 || n <= 0) {
        std::cout << "Помилка: некоректні розміри.\n";
        return 1;
    }

    // Виділяємо пам'ять під масив покажчиків на матриці
    double*** matrices = new double**[count];
    
    // Введення всіх матриць
    for (int k = 0; k < count; ++k) {
        std::cout << "\nВведення матриці №" << k + 1 << ":\n";
        matrices[k] = create_matrix(m, n);
        for (int i = 0; i < m; ++i) {
            std::cout << "Рядок " << i << " (" << n << " чисел): ";
            for (int j = 0; j < n; ++j) {
                std::cin >> matrices[k][i][j];
            }
        }
    }

    // Створюємо матрицю для зберігання суми
    double** sum_matrix = create_matrix(m, n);

    // Підрахунок суми всього масиву матриць
    for (int k = 0; k < count; ++k) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sum_matrix[i][j] += matrices[k][i][j];
            }
        }
    }

    // Виведення результуючої матриці сум
    std::cout << "\nМатриця суми всього масиву matrix:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << sum_matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }

    // Коректне звільнення всієї виділеної пам'яті без витоків
    free_matrix(sum_matrix, m);
    free_all_matrices(matrices, count, m);

    return 0;
}
