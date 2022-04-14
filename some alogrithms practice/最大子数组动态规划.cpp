#include <iostream>
using namespace std;

//用于存放左边界右边界和最大和
struct subarray {
	int l, r;
	int sum;
};

subarray max_subarray(int a[], int n) {
	int l = 0, r = 0, t = 1; //t用来计数，用来求右边界
	int sum = a[0];
	int temp = a[0];
	    //如果temp + a[i] > a[i]继续加t继续计数
	for (int i = 1; i < n; i++) {
		if (temp + a[i] > a[i]) {
			temp += a[i];
			t++;
		}
		//否则重新开始计数清零
		else {
			t = 0;
			temp = a[i];
		}
		//如果temp大于最大和sum则更新sum,同时更新左边界和右边界
		if (temp > sum) {
			sum = temp;
			r = i;
			l = r - t;
		}
	}
	subarray s{ l, r, sum };
	return s;
}

int main() {
	int a[16] = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	subarray s = max_subarray(a, 16);
	cout << s.l + 1 << ' ' << s.r + 1 << ' ' << s.sum << endl;
	return 0;
}