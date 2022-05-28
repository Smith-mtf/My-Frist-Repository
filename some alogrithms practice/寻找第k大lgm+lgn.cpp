#include<iostream>
#include<math.h>

using namespace std;
int a1[6] = { 0,38,17,2,1,0 };
int a2[6] = { 0,16,15,14,12,10 };
int find(int a[], int b[], int al, int ar, int bl, int br, int k) {
	int m = ar - al + 1;
	int n = br - bl + 1;
	if (al == ar) {
		if (b[bl + k - 1] > a[al])
			return  b[bl + k - 1];
		return a[al];
	}
	else if (bl == br) {
		if (a[al + k - 1] > b[bl])
			return  a[al + k - 1];
		return b[bl];
	}
	if (a[int(ceil(al + m * 1.0 / 2 - 1))] >= b[int(ceil(bl + n * 1.0 / 2 - 1))]) {
		if (k >= ceil(m * 1.0 / 2) + ceil(n * 1.0 / 2))
			find(a, b, ceil(al + m * 1.0 / 2 - 1) + 1, ar, bl, br, k - ceil(m * 1.0 / 2));
		else
			find(a, b, al, ar, bl, ceil(bl + n * 1.0 / 2 - 1), k);
	}
	else {
		if (k >= ceil(m * 1.0 / 2) + ceil(n * 1.0 / 2))
			find(a, b, al, ar, ceil(bl + n * 1.0 / 2 - 1) + 1, br, k - ceil(n * 1.0 / 2));
		else
			find(a, b, al, ceil(al + m * 1.0 / 2 - 1), bl, br, k);
	}
}

int main() {
	int k = 2;
	cout << "array1: ";
	for (int i = 1; i <= 5; i++)
		cout << a1[i] << ' ';
	cout << endl;
	cout << "array2: ";
	for (int i = 1; i <= 5; i++)
		cout << a2[i] << ' ';
	cout << endl;
	cout << "The " << k << "th " << "big number is: ";
	cout << find(a1, a2, 1, 5, 1, 5, k);
}