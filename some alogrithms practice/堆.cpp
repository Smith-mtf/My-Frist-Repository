#include <iostream>
using namespace std;
const int MAX = 1000;
int heap_size;
int heap_length;
//求左孩子右孩子父亲节点
int parent(int i) {
	return i / 2;
}

int left(int i) {
	return 2 * i;
}

int right(int i) {
	return 2 * i + 1;
}
void exchange(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}
//维护堆的性质 
void max_heapify(int a[], int i) {
	int largest;
	int l = left(i);
	int r = right(i);
	if (l <= heap_size && a[l - 1] > a[i - 1])
		largest = l;
	else largest = i;
	if (r <= heap_size && a[r - 1] > a[largest - 1])
		largest = r;
	if (largest != i) {
		exchange(a[i - 1], a[largest - 1]);
		max_heapify(a, largest);
	}
}

void build_max_heap(int a[]) {
	heap_size = heap_length;
	for (int i = heap_size / 2; i >= 1; i--)
		max_heapify(a, i);
}

void heapsort(int a[]) {
	build_max_heap(a);
	for (int i = heap_length; i >= 2; i--) {
		exchange(a[0], a[i - 1]);
		heap_size--;
		max_heapify(a, 1);
	}
}

int main() {
	int b[] = {16,4,10,14,7,9,3,2,8,1 };
	heap_length = 10;
	heapsort(b);

	for (int i = 0; i < 10; i++)
		cout << b[i] << " ";
	return 0;
}