#include <iostream>
using namespace std;
int MAX = 0x3f3f3f3f;
int a[5][5] = {
	MAX, -1,  3,MAX,MAX,
	MAX,MAX,  3,  2,  2,
	MAX,MAX,MAX,MAX,MAX,
	MAX,  1,  5,MAX,MAX,
	MAX,MAX,MAX, -3,MAX
};
int d[100];
bool bellman_ford(int n, int s) {
	//初始化
	d[s] = 0;
	for (int i = 0; i < n; i++)
		if (i != s)
			d[i] = MAX;
	//进行n-1次松弛操作
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n; j++)  //对每一条边进行松弛操作
			for (int k = 0; k < n; k++) {
				if (a[j][k] != MAX)
					if (d[k] > d[j] + a[j][k])
						d[k] = d[j] + a[j][k];
			}
	//再进行一次松弛操作，若有更新，则存在负权回路，不存在最短路径
	for (int j = 0; j < n; j++)
		for (int k = 0; k < n; k++) {
			if (a[j][k] != MAX)
				if (d[k] > d[j] + a[j][k])
					return false;
		}
	return true;
}
int main() {
	if (bellman_ford(5, 0))
		for (int i = 1; i < 5; i++)
			cout << "from 0 to " << i << ": "<< d[i] << endl;
	else
		cout << "The path does not exit!" << endl;
	return 0;
}