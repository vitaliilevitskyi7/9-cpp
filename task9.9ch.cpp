#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// Функція для виведення динамічної матриці на екран
void print_matrix(double** mat, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(8) << std::fixed << std::setprecision(2) << mat[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

// Функція для безпечного очищення пам'яті двовимірного масиву
void free_matrix(double** mat, int rows) {
    if (mat == nullptr) return;
    for (int i = 0; i < rows; ++i) {
        delete[] mat[i];
    }
    delete[] mat;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int n, m;
    std::cout << "Введіть початкові розміри матриці N та M (через пробіл): ";
    std::cin >> n >> m;

    if (n <= 0 || m <= 0) {
        std::cout << "Помилка: розміри мають бути більшими за 0.\n";
        return 1;
    }

    // 1. Створення початкової динамічної матриці N x M
    double** matrix = new double*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new double[m];
        for (int j = 0; j < m; ++j) {
            // Заповнення випадковими дійсними числами від 0 до 50
            matrix[i][j] = (std::rand() % 5000) / 100.0;
        }
    }

    std::cout << "Початкова матриця:\n";
    print_matrix(matrix, n, m);

    // 2. Пошук стовпця, що має найбільшу суму елементів
    int max_sum_col_index = 0;
    double max_sum = -1e9; // Ініціалізація завідомо малим значенням

    for (int j = 0; j < m; ++j) {
        double current_col_sum = 0;
        for (int i = 0; i < n; ++i) {
            current_col_sum += matrix[i][j];
        }
        if (current_col_sum > max_sum) {
            max_sum = current_col_sum;
            max_sum_col_index = j;
        }
    }

    std::cout << "Стовпець з найбільшою сумою елементів має індекс: " << max_sum_col_index 
              << " (Сума: " << max_sum << ")\n\n";

    // 3. Створення нової матриці розміром N x (M + 1)
    int new_m = m + 1;
    double** new_matrix = new double*[n];
    for (int i = 0; i < n; ++i) {
        new_matrix[i] = new double[new_m];
    }

    // Копіювання елементів з додаванням нового стовпця після цільового
    for (int i = 0; i < n; ++i) {
        int new_col_ptr = 0;
        for (int j = 0; j < m; ++j) {
            new_matrix[i][new_col_ptr] = matrix[i][j];
            new_col_ptr++;

            // Якщо ми щойно скопіювали цільовий стовпець, вставляємо після нього новий елемент
            if (j == max_sum_col_index) {
                // Новий стовпець заповнюємо, наприклад, значенням 99.99 для наочності вставки
                new_matrix[i][new_col_ptr] = 99.99; 
                new_col_ptr++;
            }
        }
    }

    // 4. Очищення пам'яті старої матриці та перепризначення покажчика
    free_matrix(matrix, n);
    matrix = new_matrix;
    m = new_m;

    std::cout << "Матриця після вставки нового стовпця після стовпця " << max_sum_col_index << ":\n";
    print_matrix(matrix, n, m);

    // Кінцеве звільнення ресурсів
    free_matrix(matrix, n);

    return 0;
}
