#include <iostream>
#include <string>
#include "stdlib.h"
#include "time.h"
#include <iomanip>
using namespace std;

void print_menu();
int get_variant(int count);
void inp_array(int* x, int n);
void inp_array_random(int x[], int n);
void out_array(int x[], int n); // Вывод массива
void Insert_array(int x[], int& n, int p, int A); //Вставить значение в заданную позициЮ
int linSearch(int arr[], int requiredKey, int n); // Линейный  поисК
int find_index(int x[], int n, int value); // //Нахождение индекса первого вхождения заданного значения в массиве
int find_all_kolvo(int x[], int n, int value);  //Кол-во всех вхождений заданного значения в массиве
void Delete_array_sohranenie(int x[], int& n, int p); //Удаление  значения из заданной позиции, сохраняя порядок всех остальных элементов
void Delete_array_bez(int x[], int& n, int p); //Удаление значения из позиции, без сохранения порядка
void Delete_all_ravn_zadan(int x[], int& n, int value); //Удаление всех значений равных заданному
void Sort_Insert(int x[], int n); 
  
int main()  
{
    setlocale(0, "");
    int const N = 100;
    int n, a[N];
    cout << " Введите размер массива [1 <= n <= " << N << "]" << endl;
    cin >> n;
    if (n<1 or n>N)
    {
        cout << "Неизвестный размер" << endl;
        return 1;
    }
    int variant;
    do
    {
        print_menu();
        variant = get_variant(10);

        switch (variant)
        {
            case 1:
            {
                int var,x;
                cout << "Введите 1- если заполнить массив с клавиатуры ; 2 - если заполнить рандомными числами " << endl;
                cin >> var;
                switch (var)
                {
                case 1:
                        inp_array(a, n);
                        break;
                case 2:
                        inp_array_random(a, n); 
                        break;

                default: 
                {
                    cout << "Некорректно" << endl;
                    break;
                }

                }
                break;
            }
            case 2:
            {
                out_array(a, n);
                break;
            }
            case 3:
            {
                int p, A; // A- значение
                cout << "Введите позицию, в которую нужно вставить значение: ";
                cin >> p;
                if (p < 0 || p >= n)
                {
                    cout << "Индекс вне диапазона\n";
                    break;
                }

                cout << "Введите значение, которое нужно вставить: ";
                cin >> A;

                cout << "Изначальный массив: " << endl;
                out_array(a, n);
                cout << "Измененный массив: " << endl;
                Insert_array(a, n, p, A);
                out_array(a, n);
                break;
            }
            case 4:
            {
                int key, element;
                cout << "Какое число необходимо искать? ";
                cin >> key;
                element= linSearch(a,key,n);
                out_array(a, n);

                if (element != -1)
                    cout << "Значение " << key << " находится в ячейке с индексом: " << element << endl;
                else
                    cout << "В массиве  нет такого значения" << endl;

                break;
            }
            case 5:
            {
                int key, element;
                cout << "Введите значение, индекс первого вхождения которого нужно найти: ";
                cin >> key;
                element = find_index(a, n, key);
                out_array(a, n);

                if (element != -1)
                    cout << "Индекс первого вхождения данного значения = " << element << endl;
                else
                    cout << "В массиве  нет такого значения " << endl;
                break;
            }
            case 6:
            {
                int key, element;
                cout << "Введите значение, количество вхождений которого нужно найти: ";
                cin >> key;
                element = find_all_kolvo(a, n, key);
                out_array(a, n);
                if (element != 0)
                    cout << "Количество вхождений данного значения = " << element << endl;
                else
                    cout << "В массиве  нет такого значения " << endl;
                break;
            }
            case 7:
                int key,gg;
                cout << "Введите позицию, из которой надо удалить соотвествующее значение: ";
                cin >> key;
                if (key < 0 || key >= n)
                {
                    cout << "Индекс вне диапазона\n";
                    break;
                }
                cout << "Выберите 1 - если надо сохранять порядок остальных элементов ; 2 - если сохранять не трубуется" << endl;
                cin >> gg;
                if (gg == 1)
                {
                    cout << "Изначальный массив: " << endl;
                    out_array(a, n);
                    cout << "Измененный массив: " << endl;
                    Delete_array_sohranenie(a, n, key);
                    out_array(a, n);
                }
                else if (gg == 2)
                {
                    cout << "Изначальный массив: " << endl;
                    out_array(a, n);
                    cout << "Измененный массив: " << endl;
                    Delete_array_bez(a, n, key);
                    out_array(a, n);
                }
                else
                    cout << "Некорректный ввод-- Повторите " << endl;
                break;

            case 8:
            {
                int key;
                cout << "Введите значение, которое надо убрать из массива: "; 
                cin >> key;

                cout << "Изначальный массив: " << endl;
                out_array(a, n);
                cout << "Измененный массив: " << endl;
                Delete_all_ravn_zadan(a, n, key);
                out_array(a, n);
                break;
            }
            case 9:
            {
                cout << "Изначальный массив: " << endl;
                out_array(a, n);
                Sort_Insert(a, n);
                cout << "Измененный массив: " << endl;
                out_array(a, n);
                break;
            }
        }

        if (variant != 10)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    } while (variant != 10);
    return 0;
}

//Меню
void print_menu() 
{
    setlocale(0, "");
    system("cls"); // очищаем экран
    cout << "Выберите операцию --> " << endl;
    cout << "1. Заполнение массива " << endl;
    cout << "2. Вывод массива" << endl;
    cout << "3. Вставить значение в заданную позицию " << endl;
    cout << "4. Линейный поиск "  << endl;
    cout << "5. Найти индекс первого вхождения заданного значения в массиве " << endl;
    cout << "6. Найти количество вхождений заданного значения в массиве " << endl;
    cout << "7. Удалить значение из заданной позиции: сохраняя порядок всех остальных элементов; не сохраняя порядок следования остальных элементов." << endl;
    cout << "8. Удалить все значения равные заданному. " << endl;
    cout << "9. Все элементы меньше первого элемента, расположить перед ним, сохраняя порядок следования элементов" << endl;
    cout << "10. ----Выход" << endl;
    cout << ">";
}

//Выбор меню
int get_variant(int count) {
    int variant;
    //string s; // строка для считывания введённых данных
    //getline(cin, s); // считываем строку

    //// пока ввод некорректен, сообщаем об этом и просим повторить его
    //while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count) {
    //    cout << "Incorrect input. Try again: "; // выводим сообщение об ошибке
    //    getline(cin, s); // считываем строку повторно
    //}
    cout << "Выберите пункт меню: ";
    cin>>variant;
    return variant;
}

// Заполнение массива с клавиатуры. где 1<n<N
void inp_array(int* x, int n)
{
    setlocale(0, "");
    cout << "Введите " << n << "чисел\n";
    for (int i = 0; i < n; i++)
        cin >> x[i];
}

// Заполнение массива рандом
void inp_array_random(int x[], int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
        x[i] = rand() %101-1;
}

//Вывод массива
void out_array(int x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << setw(4) << x[i];
    }
    cout << endl;
}

//Вставить значение в заданную позицию
void Insert_array(int x[], int& n, int p, int A)
{
    for (int i = n; i >= p + 1; i--)
    {
        x[i] = x[i - 1];
    }
    x[p] = A;
    n++;
}

// Линейный поиск
int linSearch(int arr[], int requiredKey, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == requiredKey)
            return i;
    }
    return -1;
}

//Нахождение индекса первого вхождения заданного значения в массиве
int find_index(int x[], int size, int value)
{
    int i = 0;
    while (i < size && x[i] != value)
    {
        i++;
    }
    return (i < size) ? i : -1;

}

//Кол-во всех вхождений заданного значения в массиве
int find_all_kolvo(int x[], int n, int value)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == value)
        {
            k++;
        }
    }
    return k;
}

//Удаление  значения из заданной позиции, сохраняя порядок всех остальных элементов
void Delete_array_sohranenie(int x[], int& n, int p) // &n- передать саму переменную
{
    for (int i = p; i < n - 1; i++)
    {
        x[i] = x[i + 1];
    }
    n--;
}

//Удаление значения из позиции, без сохранения порядка

void Delete_array_bez(int x[], int& n, int p)
{   
    x[p] = x[n - 1];
    n--;
}

//Удаление всех значений равных заданному

void Delete_all_ravn_zadan(int x[], int& n, int value)
{
    int j=0;
    for (int i = 0; i < n; i++)
    {
        x[j] = x[i];
        if (x[i] != value)
            j++;
    }
    n = j;
}

//Все элементы меньше первого расположить перед ним 
void Sort_Insert(int x[], int n)
{
    int first = x[0], insert = 0, buff;

    for (int i = 1; i < n; i++)
    {
        if (x[i] < first)
        {

            buff = x[i];

            for (int j = i; j > insert; j--)
                x[j] = x[j - 1];

            x[insert] = buff;

            insert++;

        }
    }
}



