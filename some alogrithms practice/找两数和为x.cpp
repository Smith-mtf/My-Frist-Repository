#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], temp[N];

void merge_sort(int a[], int l, int r) {
	if (l >= r) return;
	int mid = l + r >> 1;
	merge_sort(a, l, mid); merge_sort(a, mid + 1, r);
	int i = l, j = mid + 1, k = 0;
	while (i <= mid && j <= r)
		if (a[i] <= a[j])	temp[k++] = a[i++];
		else temp[k++] = a[j++];
	while (i <= mid)
		temp[k++] = a[i++];
	while (j <= r)
		temp[k++] = a[j++];
	for (int i = l, j = 0; i <= r; i++, j++)
		a[i] = temp[j];
}

int binary_search(int a[], int x, int l, int r) {
	while (l <= r) {
		int mid = l + r >> 1;
		if (a[mid] == x) return 1;
		if (a[mid] > x)	r = mid;
		else l = mid + 1;
	}
	return 0;
}

int check(int a[], int x, int n) {
	int i = 0;
	while (i < n - 1) {
		int num = x - a[i];
		if (binary_search(a, num, i + 1, n - 1))
			return 1;
		i++;
	}
	return 0;
}

int main() {
	int a[6] = {1,5, 4, 3, 6, 2 };
	merge_sort(a, 0, 5);
	if (check(a, 12, 6))
		cout << "find it" << endl;
	else
		cout << "not found" << endl;
	return 0;
}
