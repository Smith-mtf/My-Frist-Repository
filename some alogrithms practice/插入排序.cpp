#include <iostream>
using namespace std;
int a[6] = { 1, 5, 4, 3, 6, 2 };
void insert_sort(int a[], int size) {
	int key;
	int i, j;
	for (j = 1; j < size; j++) {
		key = a[j];
		i = j - 1;
		while (i > 0 && a[i] > key) {
			a[i + 1] = a[i];
			i--;
		}
			a[i + 1] = key;
	}
}
int main() {
	insert_sort(a, 6);
	for (int i = 0; i < 6; i++)
		cout<<a[i]<<' ';
	return 0;
}
