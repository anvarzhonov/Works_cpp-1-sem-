#include <iostream>
#include <time.h>
#include <algorithm>
#include <cstdlib>
using namespace std;

int Input(const char* vvod, int min, int max)
{
    setlocale(LC_ALL, "RUS");
    int input = 0;
    while (true) {
       cout << vvod;
        cin >> input;

        if (cin.eof()) {
            cout << "Достиг конца.\n";
            exit(1);
        }
        if (input >= min && input <= max) {
            return input;
        }
        else {
            cout << "НЕ корректные данные, введите занова.\n";
            cin.clear();
            cin.ignore(1024, '\n');
        }
    }
}
//Подпрограмма для вывода массива
void print(int** mtrx, int size) 
{
    setlocale(LC_ALL,"RUS");
    cout << "Вывод массива:\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            cout << mtrx[i][j] << '\t';
        cout << '\n';
    }
}

void sortirovka(int** mtrx, int size) 
{
    bool flag; // if a swap was made
    for (int i = 0; i < size; i++) {
        flag = 0;
         
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                if (mtrx[i][j] < mtrx[i][k])
                {
                    swap(mtrx[i][j], mtrx[i][k]);
                    flag = 1;
                }
            }
            
        }
        if (flag == 0) // Если прошел весь массив без перестановок
            break;
    }
}

//void invertElements(int** mtrx, int size)
//{



int main()
{
    setlocale(LC_ALL, "RUS");
    int size = Input("Размер двумерного массива[2, 5], M = ", 2, 5);
    int choice = Input("Выберите способ заполнения массива? \'1/2\' [1-ручной ввод/2-случайные значения]: ", 1, 2);

    // Создания динамического двумернного массива
    int** matrix = new int* [size];
    for (int i = 0; i < size; ++i)
        matrix[i] = new int[size];

    // При выборе заполнения массива в ручную
    if (choice == 1) 
    { 
        cout << "Введите числа массива из заданного диапазона [0,100]:\n";
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                matrix[i][j] = Input("", 0, 100);
    }
    else
    // Генерирование случайных чисел
    { 
        srand(time(NULL));
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                matrix[i][j] = rand() % 100;
    }
    print(matrix, size);
    sortirovka(matrix, size);  // сортировка
    print(matrix, size);

    int n = Input("Какой минимум по счёту вывести , N = ", 1, size);
    int stroka = Input("Введите в какой строке найти минимум: ", 1, size);
    cout << n << " minimum = " << matrix[stroka-1][n-1] << '\n';

    return 0;
}