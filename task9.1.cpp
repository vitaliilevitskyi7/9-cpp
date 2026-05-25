#include <iostream>

int main() {
    int n;
    std::cout << "Введіть натуральне число n: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Помилка: некоректний розмір.\n";
        return 1;
    }

    // Динамічне виділення пам'яті
    double* arr = new double[n];

    std::cout << "Введіть " << n << " дійсних чисел:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    double sum_squares = 0.0;
    for (int i = 0; i < n; ++i) {
        sum_squares += arr[i] * arr[i];
    }

    std::cout << "Сума квадратів елементів: " << sum_squares << std::endl;

    // Звільнення пам'яті
    delete[] arr;

    return 0;
}
