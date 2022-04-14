#include <iostream>
using namespace std;

struct subarray {
	int l, r;
	int sum;
};

subarray max_crossing_subarray(int a[], int low, int mid, int high) {
	int left_sum = -65535;
	int sum = 0;
	int left = 0;
	for (int i = mid; i >= low; i--) {
		sum += a[i];
		if (sum > left_sum) {
			left_sum = sum;
			left = i;
		}
	}
	int right_sum = -65535;
	sum = 0;
	int right = 0;
	for (int j = mid + 1; j <= high; j++) {
		sum += a[j];
		if (sum > right_sum) {
			right_sum = sum;
			right = j;
		}
	}
	subarray l = { left, right, left_sum + right_sum };
	return l;
}

subarray max_subarray(int a[], int low, int high) {
	subarray deft = { low, high, a[low] };
	subarray l, r, m;
	if (low == high)
		return deft;
	int mid = low + high >> 1;
	l = max_subarray(a, low, mid);
	r = max_subarray(a, mid + 1, high);
	m = max_crossing_subarray(a, low, mid, high);
	if (l.sum > r.sum && l.sum > m.sum)
		return l;
	else if (r.sum > l.sum && r.sum > m.sum)
		return r;
	else return m;
}

int main() {
	int a[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	subarray s = max_subarray(a, 0, 15);
	cout << s.l + 1 <<' '<< s.r + 1 <<' '<< s.sum << endl;
	return 0;
}