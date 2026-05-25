#include <iostream>
#include <cmath>

void input_and_process(int* arr, int& size, int& squares, int& cubes) {
    size = 0;
    squares = 0;
    cubes = 0;
    int num;

    std::cout << "Введіть цілі числа (0 - кінець введення, максимум 100):\n";
    while (size < 100) {
        std::cin >> num;
        if (num == 0) break;
        arr[size] = num;
        size++;
    }

    for (int i = 0; i < size; ++i) {
        if (arr[i] >= 0) {
            int root_sq = static_cast<int>(std::round(std::sqrt(arr[i])));
            if (root_sq * root_sq == arr[i]) squares++;
        }
        int root_cb = static_cast<int>(std::round(std::cbrt(arr[i])));
        if (root_cb * root_cb * root_cb == arr[i]) cubes++;
    }
}

int main() {
    int* arr = new int[100];
    int size, squares, cubes;

    input_and_process(arr, size, squares, cubes);

    std::cout << "Оброблено елементів: " << size << "\n";
    std::cout << "Кількість повних квадратів: " << squares << "\n";
    std::cout << "Кількість повних кубів: " << cubes << "\n";

    delete[] arr;
    return 0;
}
