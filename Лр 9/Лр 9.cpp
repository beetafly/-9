// Лр 9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

const int ROWS = 5;
const int COLS = 10;

int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {21, 22, 23, 0, 25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
        {41, 42, 43, 44, 45, 46, 47, 48, 49, 50}
    };

    // Находим максимальный элемент и его позицию
    int maxElement = matrix[0][0];
    int maxRow = 0, maxCol = 0;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    // Меняем местами строку и столбец на пересечении максимального элемента
    for (int i = 0; i < ROWS; ++i) {
        int temp = matrix[i][maxCol];
        matrix[i][maxCol] = matrix[maxRow][i];
        matrix[maxRow][i] = temp;
    }

    // Определяем номера строк и столбцов с нулевыми элементами
    std::cout << "Rows with zero elements: ";
    for (int i = 0; i < ROWS; ++i) {
        bool hasZero = false;
        for (int j = 0; j < COLS; ++j) {
            if (matrix[i][j] == 0) {
                hasZero = true;
                break;
            }
        }
        if (hasZero)
            std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Columns with zero elements: ";
    for (int j = 0; j < COLS; ++j) {
        bool hasZero = false;
        for (int i = 0; i < ROWS; ++i) {
            if (matrix[i][j] == 0) {
                hasZero = true;
                break;
            }
        }
        if (hasZero)
            std::cout << j << " ";
    }
    std::cout << std::endl;

    // Вывод измененной матрицы
    std::cout << "Modified Matrix:" << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
