#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;
void inp_array_random(int x[], int n);


int increment(long inc[], int size) {
	int p1, p2, p3, s;

	p1 = p2 = p3 = 1;
	s = -1;
	do {
		if (++s % 2) {
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
		else {
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while (3 * inc[s] < size);

	return s > 0 ? --s : 0;
}

void Shell_Knut(int* a, int Size)
{
	int h = 0;
	int temp;
	int left, right;
	while (h <= Size / 3)
	{
		h = 3 * h + 1;
	}
	for (h = 1; h > 0; h = (h - 1) / 3)
	{
		for (right = h; right < Size; right++)
		{
			temp = a[right];
			for (left = right; left >= h; left -= h)
			{
				if (temp < a[left - h])
					a[left] = a[left - h];
				else break;
			}
			a[left] = temp;
		}
	}
}

void Shell_Sedjvek(int a[], int size) {
	long gap, i, j;
	long* seq = new long[size];
	int k;

	// вычисление последовательности приращений
	k = increment(seq, size);
	while (k >= 0) {
		// сортировка вставками с инкрементами gap[] 
		gap = seq[k--];

		for (i = gap; i < size; i++) {
			int temp = a[i];
			for (j = i - gap; (j >= 0) && (a[j] > temp); j -= gap)
				a[j + gap] = a[j];
			a[j + gap] = temp;
		}
	}
}

void Shell(int* a, int n)
{
	int b, i, j, k, h;
	b = n;
	k = b / 2;
	while (k > 0)
	{
		for (i = 0; i < b - k; i++)
		{
			j = i;
			while (j >= 0 && a[j] > a[j + k])
			{
				swap(a[j], a[j + k]);
				j--;
			}
		}
		k = k / 2;
	}

}




void inp_array_random(int x[], int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
		x[i] = rand() % 101 - 1;
}
void Output(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
}



int main()
{
	setlocale(0, "");
	int* a = NULL, size = 100;
	double t1, t2;
	for (int i = 0; i <= 4; i++)
	{
		a = new int[size];
		inp_array_random(a, size);
		t1 = clock();
		Shell_Sedjvek(a, size);
		t2 = clock();
		cout << "Шелла. Седжвик--> ";
		cout << "Размер = " << size << " время: " << (t2 - t1) / 1000 << endl;
		cout << "======================================================\n";

		/*inp_array_random(a, size);
		t1 = clock();
		Shell_Knut(a, size);
		t2 = clock();
		cout << "Шелла. Кнут--> ";
		cout << "Размер = " << size << " время: " << (t2 - t1) / 1000 << endl;
		cout << "======================================================\n";*/


		size *= 10;
		delete[] a;

	}


}