#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//朴素版的dijkstra算法 基于贪心
const int INF = 0x3f3f3f3f;//无穷大

int a[16][16] = { INF,  5,  3,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,
				  5  ,INF,INF,  1,  3,  6,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,
				  3  ,INF,INF,INF,  8,  7,  6,INF,INF,INF,INF,INF,INF,INF,INF,INF,
				  INF,  1,INF,INF,INF,INF,INF,  6,  8,INF,INF,INF,INF,INF,INF,INF,
				  INF,  3,  8,INF,INF,INF,INF,  3,  5,INF,INF,INF,INF,INF,INF,INF,
				  INF,  6,  7,INF,INF,INF,INF,INF,  3,  3,INF,INF,INF,INF,INF,INF,
				  INF,INF,  6,INF,INF,INF,INF,INF,  8,  4,INF,INF,INF,INF,INF,INF,
				  INF,INF,INF,  6,  3,INF,INF,INF,INF,INF,  2,  2,INF,INF,INF,INF,
				  INF,INF,INF,  8,  5,  3,  8,INF,INF,INF,INF,  1,  2,INF,INF,INF,
				  INF,INF,INF,INF,INF,  3,  4,INF,INF,INF,INF,  3,  3,INF,INF,INF,
				  INF,INF,INF,INF,INF,INF,INF,  2,INF,INF,INF,INF,INF,  3,  5,INF,
				  INF,INF,INF,INF,INF,INF,INF,  2,  1,  3,INF,INF,INF,  5,  2,INF,
				  INF,INF,INF,INF,INF,INF,INF,INF,  2,  3,INF,INF,INF,  6,  6,INF,
				  INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,  3,  5,  6,INF,INF,  4,
				  INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,  5,  2,  6,INF,INF,  3,
				  INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,  4,  3,INF
};

int dist[16]; //源点到每个点的距离
bool st[16]; //当前已经确定最短路径的点
int dijkstra(int a[16][16], int dist[], int n) {
	dist[0] = 0; 
	for (int i = 0; i < 16; i++)
		cout << dist[i] << ' ';
	cout << endl;
	for (int i = 0; i < n; i++) {
		int t = -1; //找到不在st中距离最近的点
		for (int j = 0; j < n; j++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		st[t] = true;
		//更新源节点到各个节点的距离
		//每次更新时打印出来，最后结果为18
		for (int j = 0; j < n; j++) {
			dist[j] = min(dist[j], dist[t] + a[t][j]);
			cout << dist[j] << ' ';
		}
		cout << endl;
	}
	if (dist[n] == 0x3f3f3f3f)
		return -1;
	return dist[n-1];
}
int main() {
	memset(dist, 0x3f, sizeof dist);
	dijkstra(a, dist, 16);
	//for (int i = 0; i < 16; i++)
		//cout << dist[i] << ' ';
}