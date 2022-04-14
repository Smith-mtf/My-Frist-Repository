#include <iostream>
using namespace std;
//类似寻找最长公共序列，列举每一种情况找出最大
void lcstr_length(const char* x, const char* y, int m, int n, int a[][100]) {
	if (m == 0 || n == 0)
		return;
	for(int i =0; i<m;i++)
		for (int j = 0; j < n; j++) {
			int l = 0, i1 = i, j1 = j;
			while (x[i1] == y[j1]) {
				i1++; j1++; l++;
			}
			a[i][j] = l;
		}
}

void print(int a[][100], int m, int n, const char* x) {
	int maxl, maxr;
	int max = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
				maxl = i; maxr = i + max - 1;
			}
		}
	}
	if(max != 0)
		for (int i = maxl; i <= maxr; i++)
			cout << x[i];
}
int main() {
	char x1[] = "xzyzzyx";
	char y1[] = "zxyyzxz";
	int a[100][100];
	lcstr_length(x1, y1, 7, 7, a);
	print(a, 7, 7, x1);
	cout << endl;
	char x2[] = "MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCALLAAQANKESSSESFISRLLAIVAD";
	char y2[] = "MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCTLLAAQANKENSNESFISRLLAIVAG";
	lcstr_length(x2, y2, 60, 60, a);
	print(a, 60, 60, x2);
	return 0;
}