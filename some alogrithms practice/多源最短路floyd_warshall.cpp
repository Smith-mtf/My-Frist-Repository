#include <iostream>
using namespace std;
const int MAX = 0x3f3f3f3f;
int a[5][5] = {
	0  , -1,  3,MAX,MAX,
	MAX,  0,  3,  2,  2,
	MAX,MAX,  0,MAX,MAX,
	MAX,  1,  5,  0,MAX,
	MAX,MAX,MAX, -3,  0
};
int d[5][5]; //距离矩阵
int p[5][5]; //前驱矩阵
int n = 5;
void floyd_warshall() {

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			d[i][j] = a[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i != j && a[i][j] != MAX)
				p[i][j] = i;
			else
				p[i][j] = -1;
		}
	//每次增加一个中间节点K
	for (int k = 0; k < n; k++) {		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (d[i][k] != MAX && d[k][j] != MAX && d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];//距离的更新
					p[i][j] = p[k][j];//前驱节点的更新	
				}
	}
	//打印距离矩阵
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (d[i][j] == MAX)
				cout << "N ";
			else
				cout << d[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	//打印前驱节点矩阵
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (p[i][j] == -1)
				cout << "NIL ";
			else
				cout << p[i][j] << "   ";
		}
		cout << endl;
	}

}

int main() {
	floyd_warshall();
	return 0;
}