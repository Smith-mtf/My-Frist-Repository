#include <iostream>
using namespace std;

void exchange(int& a, int& b) {
	int t = a;
	a = b; b = t;
}
int partition(int a[], int p, int r) {
	int x = a[r - 1];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++) {
		if (a[j - 1] < x) {
			i++; exchange(a[i - 1], a[j - 1]);
		}
	}
	exchange(a[i], a[r - 1]);
	return i + 1;
}

void quicksort(int a[], int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);
	}
}

int main() {
	int a[10] = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
	quicksort(a, 1, 10);
	for (int i = 0; i < 12; i++)
		cout << a[i] << ' ';
	return 0;
}
// 如果元素都相等，将会比较n*（n-1）/2次
//当每次划分时都能把数组划分两边个数相近，那么此时比较次数最小  最小为a(n) = a(n-1/2) + a(n-1/2)+ n - 1;
//当数组为顺序或者逆序的时候比较次数最多， n*（n-1）/2次