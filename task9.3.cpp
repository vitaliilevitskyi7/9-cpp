#include <iostream>

double* create_vector(int n) {
    return new double[n];
}

void free_vector(double* vec) {
    delete[] vec;
}

int main() {
    int n;
    std::cout << "Введіть розмірність векторів n: ";
    std::cin >> n;

    if (n <= 0) return 1;

    double* v1 = create_vector(n);
    double* v2 = create_vector(n);
    double* diff = create_vector(n);

    std::cout << "Введіть компоненти першого вектора:\n";
    for (int i = 0; i < n; ++i) std::cin >> v1[i];

    std::cout << "Введіть компоненти другого вектора:\n";
    for (int i = 0; i < n; ++i) std::cin >> v2[i];

    // Обчислення різниці
    for (int i = 0; i < n; ++i) {
        diff[i] = v1[i] - v2[i];
    }

    std::cout << "Різниця векторів: (";
    for (int i = 0; i < n; ++i) {
        std::cout << diff[i] << (i < n - 1 ? ", " : "");
    }
    std::cout << ")\n";

    // Безпечне звільнення пам'яті
    free_vector(v1);
    free_vector(v2);
    free_vector(diff);

    return 0;
}
