#include <iostream>
#include<map>
using namespace std;

int weight[5] = { 10,20,30,40,50 };
int value[5] = { 20,30,65,40,60 };

double f[1000][1000];
double knapsack_dp(int n, int capacity, int w[], int v[]) {
	for (int i = 0; i <= capacity; i++)
		f[0][i] = 0;
	for (int i = 0; i <= n; i++)
		f[i][0] = 0;
	//若第i个物品重量大于背包容量，最大价值一定在前i-1个里选
	//否则分为两类，包含第i个物品和不包含第i个物品分别求出来然后找出最大的
	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= capacity; j++) {
			if (w[i - 1] > j)
				f[i][j] = f[i - 1][j];
			else
				f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i - 1]] + v[i - 1]);
		}
	return f[n][capacity];
}
int main() {
	cout << "knapsack_capacity:" << 100 << ' ' << endl << "total_value:" << knapsack_dp(5, 100, weight, value) << endl;
	return 0;
}