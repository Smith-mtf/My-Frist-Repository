#include <iostream>
using namespace std;

//对于b[][] 1代表向左，2代表向右，3代表左上
void lcs_length(const char* x, const char* y, int m, int n, int c[][100], int b[][100]) {
	for (int i = 0; i <= m; i++)
		c[i][0] = 0;
	for (int i = 1; i <= n; i++)
		c[0][i] = 0;
	for(int i =1;i<=m;i++)
		for (int j = 1; j <= n; j++) {
			if (x[i - 1] == y[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 3;
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;
			}
			else {
				c[i][j] = c[i][j - 1];
				b[i][j] = 1;
			}
		}
}

//构造lcs
void print_lcs(int b[][100], const char* x, int m, int n) {
	if (m == 0 || n == 0)
		return;
	if (b[m][n] == 3) {
		print_lcs(b, x, m - 1, n - 1);
		cout << x[m - 1];
	}
	else if (b[m][n] == 2)
		print_lcs(b, x, m - 1, n);
	else
		print_lcs(b, x, m, n - 1);
}

int main() {
	char x1[] = "xzyzzyx";
	char y1[] = "zxyyzxz";
	int c[100][100], b[100][100];
	lcs_length(x1, y1, 7, 6, c, b);
	print_lcs(b, x1, 7, 6);
	cout << endl;
	char x2[] = "MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCALLAAQANKESSSESFISRLLAIVAD";
	char y2[] = "MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCTLLAAQANKENSNESFISRLLAIVAG";
	lcs_length(x2, y2, 61, 61, c, b);
	print_lcs(b, x2, 61, 61);
	return 0;
}