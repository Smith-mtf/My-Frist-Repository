#include <iostream>
using namespace std;

int j[4] = { 15,8,3,10 };
//贪心算法，从耗时最短的任务开始
int scheduling(int a[], int n) {
	int wait = 0;

	for(int i = 0; i < n ; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1]) {
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
	//求等待时间
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--)
			wait += a[j];
	}
	return wait;
}
int main() {
	cout << "waiting time: "<<scheduling(j, 4)<<endl;
	for (int i = 0; i < 4; i++)
		cout << j[i] << ' ';
	return 0;
}