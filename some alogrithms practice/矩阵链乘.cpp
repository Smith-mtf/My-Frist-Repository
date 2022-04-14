#include <iostream>
using namespace std;
//自底向下
void matrix_chain_order(int n, int p[], int m[][100], int s[][100]) {
	//如果i为0或者j为0最大子序列为0
	for (int i = 1; i <= n; i++)
		m[i - 1][i - 1] = 0;
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n - l + 1; i++) {
			int j = i + l - 1;
			//先将开销赋为无穷大
			m[i - 1][j - 1] = 0x3f3f3f3f;
			//找出开销最小的划分
			for (int k = i; k <= j - 1; k++) {
				int q = m[i - 1][k - 1] + m[k][j - 1] + p[i - 1] * p[k] * p[j];
				if (q < m[i - 1][j - 1]) {
					m[i - 1][j - 1] = q; s[i - 1][j - 1] = k;
				}
			}
		}
	}
}
//采用递归打印除划分
void print(int s[][100], int i, int j) {
	if (i == j)
		cout << 'A' << i;
	else {
		cout << '(';
		print(s, i, s[i - 1][j - 1]);
		print(s, s[i - 1][j - 1] + 1, j);
		cout << ')';
	}
}

int main() {
	int p1[] = { 3,5,2,1,10 };
	int p2[] = { 2, 7, 3, 6, 10 };
	int p3[] = { 10, 3, 15, 12, 7, 2 };
	int p4[] = { 7, 2, 4, 15, 20, 5 };
	int m[100][100], s[100][100];
	matrix_chain_order(4, p1, m, s);
	print(s, 1, 4);
	cout << endl;
	matrix_chain_order(4, p2, m, s);
	print(s, 1, 4);
	cout << endl;
	matrix_chain_order(5, p3, m, s);
	print(s, 1, 5);
	cout << endl;
	matrix_chain_order(5, p4, m, s);
	print(s, 1, 5);
	cout << endl;
	return 0;
}