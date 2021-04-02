
#include <iostream>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
using namespace std;

void make_heap(int *data, int n,int &C_Make_heap,int &M_make_heap);
void heapSort(int* data, int n, int& C_Make_heap, int& M_make_heap,
	int& C_Reheap, int& M_Reheap, int& C, int& M);
void reheapify_down(int* data, int n , int& C_Reheap, int& M_Reheap);
inline int parent(int k);
inline int left_child(int k);
inline int right_child(int k);
void out_array(int* data, int n);






void out_array(int* data, int n)
{
	for (int  i = 0; i < n; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

void heapSort(int* data, int n, int& C_Make_heap, int& M_make_heap,
	int& C_Reheap, int& M_Reheap, int& C, int& M)
{
	//создание кучи - фукнция make_heap()
	// обновление кучи вниз - функция reheapify_down()

	int unsorted = n;
	make_heap(data, n, C_Make_heap, M_make_heap);

	
	while (unsorted > 1)
	{
		C++;

		--unsorted;
		swap(data[0], data[unsorted]);
		M++;
		reheapify_down(data,unsorted, C_Reheap, M_Reheap);
	}
}


void make_heap(int* data, int n, int& C_Make_heap, int& M_make_heap)
{
	for (int i = 0; i < n; i++)
	{
		int k = i;
		while (k > 0 && data[k] > data[parent(k)])
		{
			C_Make_heap++;
			C_Make_heap++;

			swap(data[k], data[parent(k)]);
			M_make_heap++;

			k = parent(k);
		}
	}
}

void reheapify_down(int* data, int n, int& C_Reheap, int& M_Reheap)
{
	// обновление кучи, если в корне элемент не удовлетворяет условию кучи
	int current=0; // индекс узла перемещаемого вниз - текущий
	int big_child_index; // индекс большого потомка
	bool heap_ok; // флаг = true - если куча восстановлена
	heap_ok = false;

	while ( (!heap_ok) && (left_child(current) < n || right_child(current) < n))
	{
		C_Reheap += 3; C_Reheap += 2;
		// если первый потомок существует, а второй нет
		if (left_child(current) < n && right_child(current) >= n)
			big_child_index = left_child(current);

		// если существует и первый потомок и второй потомок
		else if (left_child(current) < n && right_child(current) < n)
		{
			if (data[left_child(current)] > data[right_child(current)])
			{
				big_child_index = left_child(current);
				C_Reheap++;
			}
			else
			{
				big_child_index = right_child(current);
				C_Reheap++;
			}
			
			C_Reheap += 2;
		}


		if (data[current] < data[big_child_index])
		{
			swap(data[current], data[big_child_index]);
			M_Reheap++;
			current = big_child_index;
		}
		else
			heap_ok = true;
	}
	
}


inline int parent(int k)
{
	return ( (k - 1) / 2 );
}
inline int left_child(int k)
{
	return ( 2 * k + 1 );
}
inline int right_child(int k)
{
	return (2 * k + 2) ;
}

void QSort(int* a, int l, int r)
{
	int i, j, w;
	i = l; j = r;
	int x = a[(l + r) / 2];
	do {
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			w = a[i]; a[i] = a[j]; a[j] = w;
			i++; j--;
		}
	} while (i <= j);
	if (l < j) QSort(a, l, j);
	if (i < r) QSort(a, i, r);
}

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	int size = 0;
	int* a = new int[size];

	for (int i = 0; i < size; i++)
		a[i] = rand() % 100;

	cout << endl;
	int C_Make_heap = 0;
	int M_Make_heap = 0;

	int C_Reheap = 0;
	int M_Reheap = 0;

	float time_start_1 = 0, time_end_1 = 0;
	float time_start_2 = 0, time_end_2 = 0;

	int C = 0;int M = 0;

	for (size = 100; size < 10000000; size *= 10)
	{
		int *a = new int[size];

		for (int i = 0; i < size; i++)
		{
			a[i] = rand() % 2000 - 1000;
		}

		

		time_start_1 = clock();
		heapSort(a, size, C_Make_heap, M_Make_heap,
			C_Reheap, M_Reheap, C, M);
		time_end_1 = clock();

		time_start_2 = clock();
		QSort(a, 0, size - 1);
		time_end_2 = clock();

		cout <<"Пирамидальная сортировка: "<< "Размер : " << size << " Время: " << (time_end_1 - time_start_1) / CLOCKS_PER_SEC << endl;
		cout<< "Быстрая сортировка:       "<< "Размер : " <<size <<" Время: " << (time_end_2 - time_start_2) / CLOCKS_PER_SEC << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
			<< "Make_Heap: " << endl
			<< "[ C ] : " << C_Make_heap << endl
			<< "[ M ] : " << M_Make_heap << endl
			<< "Cумма: " << C_Make_heap + M_Make_heap << endl
			<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
			<< "Reheapify_down: " << endl
			<< "[ C ] : " << C_Reheap << endl
			<< "[ m ] : " << M_Reheap << endl
			<< "Сумма: " << C_Reheap + M_Reheap << endl
			<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
			<< "Make_heap + reheapify sum [ C ]: " << C_Make_heap + C_Reheap << endl
			<< "Make_heap + reheapify sum [ M ]: " << M_Make_heap + M_Reheap << endl
			<< "Общая сумма: " << C_Make_heap + C_Reheap + M_Make_heap + M_Reheap + C + M << endl
			<< "=======================================================================" << endl << endl << endl;

		delete[size] a;
	}
}
		


