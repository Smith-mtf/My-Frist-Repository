#include <iostream>
using namespace std;

const int MAX = 10000;
int a[MAX];
int heapsize;

int parent(int i) {
	return i / 2;
}
int left_child(int i) {
	return 2 * i;
}
int right_child(int i) {
	return 2 * i + 1;
}

void exchange(int& a, int& b) {
	int t = a;
	a = b; b = t;
}

//维护堆的性质
void max_heapfy(int a[],int i) {
	int largest;
	int l = left_child(i);
	int r = right_child(i);
	if (l <= heapsize && a[l - 1] > a[i - 1])
		largest = l;
	else largest = i;
	if (r <= heapsize && a[r - 1] > a[largest - 1])
		largest = r;
	if (largest != i) {
		exchange(a[i - 1], a[largest - 1]);
		max_heapfy(a, largest);
	}
}

//建最大堆
void build_maxheap(int a[]) {
	int i = heapsize / 2;
	while (i >= 1) {
		max_heapfy(a, i);
		i--;
	}
}

    //以下部分为优先队列

int heap_maxnum(int a[]) {
	return a[0];
}

//提取最优先元素
int heap_extract_max(int a[]) {
	if (heapsize < 1)
		exit;
	int max = a[0];
	a[0] = a[heapsize - 1];
	heapsize--;
	max_heapfy(a, 1);
	return max;
}

//增加关键字的优先级
void heap_increase_key(int a[], int i, int key) {
	if (key < a[i - 1])
		exit;
	a[i - 1] = key;
	while (i > 1 && a[parent(i) - 1] < a[i - 1]) {
		exchange(a[parent(i) - 1], a[i - 1]);
		i = parent(i);
	}
}

//插入操作
void heap_insert(int a[], int i) {
	heapsize++;
	a[heapsize - 1] = -65535;
	heap_increase_key(a, heapsize, i);
}

int main() {
	int b[200] = { 1, 16, 10, 8, 9, 7, 3, 2, 4, 14 };
	heapsize = 10;
	build_maxheap(b);
	for (int i = 0; i < heapsize; i++)
		cout << b[i] << ' ';
	cout << endl;
	cout << heap_maxnum(b) << endl;
	heap_extract_max(b);
	for (int i = 0; i < heapsize; i++)
		cout << b[i] << ' ';
	cout << endl;
	heap_increase_key(b, 8, 30);
	for (int i = 0; i < heapsize; i++)
		cout << b[i] << ' ';
	cout << endl;
	heap_insert(b, 11);
	for (int i = 0; i < heapsize; i++)
		cout << b[i] << ' ';
	cout << endl;
	return 0;
}