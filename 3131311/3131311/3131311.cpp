#include <iostream>
#include <string>
#include "stdlib.h"
#include "time.h"
#include <iomanip>
using namespace std;
void shekerSort(int* x, int n);
void out_array(int x[], int n);
void inp_array_random(int x[], int n);
void Sort_Insert(int x[], int n);

// для третьего отчета
int main()
{
    setlocale(0, "");
    //Первый тест
    /*int x[] = { 12,11,10,9,8,7,6,5,4,3,2,1 };
    int n = 12;
    shekerSort(x, n);
    out_array(x, n);*/

    int* x = NULL, n = 100;
    double t1, t2;
    for (int i = 0; i <= 4; i++) // 4 пары
    {
        x = new int[n];
        inp_array_random(x, n);
        t1 = clock();
        Sort_Insert(x, n);
        t2 = clock();

        cout << "Пузырек--> ";
        cout << "Размер = " << n << " время: " << (t2 - t1) / 1000 << endl;
        cout.precision(10);
        inp_array_random(x, n);
        t1 = clock();
        shekerSort(x, n);
        t2 = clock();
        cout << "шейкер--> ";
        cout.precision(10);
        cout << "Размер = " << n << " время: " << (t2 - t1) / 1000 << endl;
        n *= 10;
        delete[] x;
    }
}

void Sort_Insert(int x[], int n)
{
    int tmp, j;
    for (int i = 1; i < n; i++)
    {
        tmp = x[i]; j = i;
        while (j > 0 && x[j - 1] > tmp)
        {
            x[j] = x[j - 1]; j--;
        }
        x[j] = tmp;
    }
}


/*cout << " Введите размер массива [1 <= n <= " << N << "]" << endl;
cin >> n;
if (n<1 or n>N)
{
    cout << "Неизвестный размер" << endl;
    return 1;
}*/




void out_array(int x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << setw(4) << x[i];

        /*if ((i + 1) % 10 == 0)
            cout << endl;*/
    }
    cout << endl;
}

void inp_array_random(int x[], int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
        x[i] = rand() % 101 - 1;
}

void shekerSort(int* x, int n)
{
    int l = 0, r = n - 1;
    int flag = 1;
    while ((l < r) && flag > 0)
    {
        flag = 0;
        for (int i = 1; i < r; i++) // двигаемся слева направо
        {
            if (x[i] > x[i + 1]) // если следующий элемент меньше текущего, меняем их местами
            {
                int t = x[i];
                x[i] = x[i + 1];
                x[i + 1] = t;
                flag = 1; // перемещение в этом цикле были
            }
        } r--; // сдвигаем правую границу на предыдущий элемент
        for (int i = r; i < l; i--) // двигаемся справа налево
        {
            if (x[i - 1] > x[i]) // если предыдущий элемент большего текущего, меняем местами
            {
                int t = x[i];
                x[i] = x[i - 1];
                x[i - 1] = t;
                flag = 1; // перемещения в этом цикле были
            }
        }
        l++; // сдвигаем левую границу на следующий элемент
    }
}









//#include <iostream>
////#include "Header.h"
//#include <time.h>
//
//using namespace std;
//
//void Kucha(int*& arr, int n)
//{
//	long long int C = 0;
//	long long int M = 0;
//	n = n - 1;
//	int temp2; // переменная для замены в конце (перестановка самого меньшего в конец массива)
//	int min; // минимальное число из троицы
//	int index; // индекс min числа
//	int kan = n; // кол-во , дублированное , тут не использую особо , пригодилось.
//	int temp; // внутрипирамидальная переменная для замены , числа по пирамиде
//	int mem; // количество переменных в большой пирамиде (всего)
//	bool flag = 0; // флаг окончания сортировки
//	int cicle = 0; // кол-во циклов , чтобы создавать n-1...-n пирамиду с каждым разом всё меньшую
//	while (!flag)
//	{
//		mem = n - cicle;
//		while (mem != 0)
//		{
//			if ((mem % 2) == 0) // если чётное количество элементов 
//			{
//				C = C + 2;
//				if (arr[mem] > arr[mem - 1]) // сравниваем последние ряды
//				{
//					min = arr[mem];
//					index = mem;
//				}
//				else if (arr[mem] <= arr[mem - 1]) // сравниваем последние ряды
//				{
//					min = arr[mem - 1];
//					index = mem - 1;
//				}
//				if (arr[mem / 2 - 1] < min) // сравниваем элемент по древу 
//				{
//					temp = arr[mem / 2 - 1];
//					arr[mem / 2 - 1] = min;
//					arr[index] = temp;
//					M++;
//				}
//				mem = mem - 2;
//			}
//			if ((mem % 2) == 1) // если чётное количество элементов
//			{
//				C++;
//				min = arr[mem];
//				index = mem;
//				if (arr[mem / 2] < min) // сравниваем элемент по древу 
//				{
//					temp = arr[mem / 2];
//					arr[mem / 2] = min;
//					arr[index] = temp;
//					M++;
//				}
//				mem = mem - 1;
//			}
//		}
//		if (cicle == n) // когда мы упорядочили все эл-ты
//			flag = 1;
//		else if (cicle <= n - 1) // если мы ещё не приблизились к верху
//		{
//			temp2 = arr[0];
//			arr[0] = arr[n - cicle];
//			arr[n - cicle] = temp2;
//			cicle++;
//			M++;
//		}
//	}
//	//for (int i = 0; i < (kan/2) + 1; i++) // swap для традиционной пирамидальной сортировки 
//	//{								// если мы не хотим делать через swap , то просто поменяем знаки неравенства в условии
//	//	swap(arr[i], arr[n - i]);   // но я делал к традиционной сортировке , так что , оставил swap на всякий
//	//}
//	cout << "Количество опер-ий сравнений = " << C << endl;
//	cout << "Количество опер-ий перемещений = " << M << endl;
//	for (int i = 0; i < n + 1; i++)
//	{
//		cout << "a[ " << i << " ] = " << arr[i] << endl;
//	}
//}
//
//void zapolnenie(int* mas, int n)
//{
//	srand(time(0));
//	for (int i = 0; i < n; i++)
//	{
//		mas[i] = rand() % 90;
//	}
//}
//
//void OutputArr(int* mas, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << mas[i] << " ";
//	}
//}
//
//void Sort_Vozr(int* arr, int first, int last)
//{
//	int i = first, j = last, x = arr[(first + last) / 2];
//
//	do {
//		while (arr[i] < x)
//			i++;
//		while (arr[j] > x)
//			j--;
//
//		if (i <= j) {
//			if (arr[i] > arr[j])
//				swap(arr[i], arr[j]);
//			i++;
//			j--;
//		}
//	} while (i <= j);
//
//	if (i < last)
//		Sort_Vozr(arr, i, last);
//	if (first < j)
//		Sort_Vozr(arr, first, j);
//}
//
//void Sort_Ubiv(int* arr, int first, int last)
//{
//	int i = first, j = last, x = arr[(first + last) / 2];
//	do {
//		while (arr[i] > x)
//			i++;
//		while (arr[j] < x)
//			j--;
//
//		if (i <= j) {
//			if (arr[i] < arr[j])
//				swap(arr[i], arr[j]);
//			i++;
//			j--;
//		}
//	} while (i <= j);
//
//	if (i < last)
//		Sort_Ubiv(arr, i, last);
//	if (first < j)
//		Sort_Ubiv(arr, first, j);
//}
//
//void Sort_Chast(int* mas, int n)
//{
//	int k = n / 2;
//	for (int i = 0; i < k; i++)
//	{
//		for (int j = 0; j < k - 1; j++)
//		{
//			if (mas[j] > mas[j + 1])
//				swap(mas[j], mas[j + 1]);
//		}
//	}
//}
//
//void selection_sort(int* mas, int n)
//{
//	int Cuya = 0; // C
//	int Muya = 0; // M
//	int temp;
//	for (int i = 0; i < n - 1; ++i)
//	{
//		int min = i;
//		for (int j = i + 1; j < n; ++j)
//		{
//			if (mas[j] < mas[min])
//			{
//				min = j;
//				Muya = Muya + 1;
//			}
//		}
//		temp = mas[min];
//		mas[min] = mas[i];
//		mas[i] = temp;
//		Cuya = Cuya + 1;
//	}
//	cout << "Количество оперсаций сравнения ( С ) : " << Cuya << endl;
//	cout << "Количество оперсаций перемещения ( M ) : " << Muya << endl;
//}
//
//void change_sort(int* mas, int n)
//{
//	int Cuya1 = 0;  // (С)
//	int Muya1 = 0;  // (М)
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = n - 1; j > i; j--)
//		{
//			if (mas[j - 1] > mas[j])
//			{
//				swap(mas[j - 1], mas[j]);
//				Cuya1++;
//			}
//			Muya1++;
//		}
//	}
//	cout << "Количество операций сравнения ( С ) : " << Cuya1 << endl;
//	cout << "Количество операций перемещения ( М ) : " << Muya1 << endl;
//}
//
//void insertion_sort(int* mas, int n)
//{
//	int Cuya2 = 0;//количество операций сравнения 
//	int Muya2 = 0;//количество операций перемещения
//	for (int i = 1; i < n; i++)
//	{
//		for (int j = i; j > 0 && mas[j - 1] > mas[j]; j--) // пока j>0 и элемент j-1 > j, x-массив int
//		{
//			swap(mas[j - 1], mas[j]);
//			Cuya2++;
//			Muya2++;
//		}
//	}
//	cout << "Количество операций сравнения ( С ) : " << Cuya2 << endl;
//	cout << "Количество операций перемещения ( М ) : " << Muya2 << endl;
//}
//
//void time_sort(float nach_time, float kon_time)
//{
//	nach_time = nach_time / CLOCKS_PER_SEC;
//	kon_time = kon_time / CLOCKS_PER_SEC;
//	cout << "\nВремя работы сортировки: " << kon_time - nach_time << endl;
//}
//
//void Merge(int* A, int nf, int first, int last, long long int& Cf_f2, long long int& Mf_f2)
//{
//	int middle, start, final, j;
//	int* mas = new int[nf];
//	middle = (first + last) / 2; //вычисление среднего элемента
//	start = first; //начало левой части
//	final = middle + 1; //начало правой части
//	for (j = first; j <= last; j++) //выполнять от начала до конца
//	{
//		Cf_f2++;
//		if ((start <= middle) && ((final > last) || (A[start] < A[final])))
//		{
//			Mf_f2++;
//			mas[j] = A[start];
//			start++;
//		}
//		else
//		{
//			Mf_f2++;
//			mas[j] = A[final];
//			final++;
//		}
//	}
//	//возвращение результата в список
//	for (j = first; j <= last; j++)
//	{
//		Mf_f2++;
//		A[j] = mas[j];
//	}
//	delete[nf]mas;
//}
////рекурсивная процедура сортировки
//void MergeSort(int* A, int nf, int first, int last, long long int& Cf_f2, long long int& Mf_f2)
//{
//	Cf_f2++;
//	if (first < last)
//	{
//		MergeSort(A, nf, first, (first + last) / 2, Cf_f2, Mf_f2); //сортировка левой части
//		MergeSort(A, nf, (first + last) / 2 + 1, last, Cf_f2, Mf_f2); //сортировка правой части
//		Merge(A, nf, first, last, Cf_f2, Mf_f2); //слияние двух частей
//	}
//}
