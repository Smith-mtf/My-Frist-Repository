#include<iostream>
#include<cmath>
using namespace std;
//非递归 
//具体讲解见  Let15-Back Tracking Algorithms I.ppt
int m = 0; 					//解的个数 
int x[100]; 				//存储的是当前皇后所在的列 比如下x[3] = 5 就是说第三行的皇后放在第5列 
bool place(int k) {  		//判断当前位置是否其他皇后能攻击到 
	for (int i = 1; i < k; i++) {
		if (x[i] == x[k] || abs(x[i] - x[k]) == abs(i - k))  //行数和列数只差绝对值相等即可以攻击到 
			return false;		//当前位置不能放 
	}
	return true;
}
//打印棋盘 
void print(int a[], int n) { 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] == j)
				cout << 'Q' << ' ';
			else cout << '.' << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
void nqueens(int n) {
	x[1] = 0;
	int k = 1; 				//从第一行开始放 
	while (k > 0) {
		x[k]++;
		while (x[k] <= n && !place(k))
			x[k]++; 		//如果当前位置不能放，就寻找下一个位置 
		if (x[k] <= n) {
			if (k == n) {	//问题的解 
				print(x, n); k--; m++;
			}
			else {
				k++; x[k] = 0; //放下一行的皇后 
			}
		}
		else k--;  			//k > n 找不到解回溯 
	}
}

int main() {
	nqueens(8);
	cout<<m;
	return 0;
}

