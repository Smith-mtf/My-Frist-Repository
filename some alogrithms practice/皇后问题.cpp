#include<iostream>
#include<cmath>
using namespace std;
//�ǵݹ� 
//���彲���  Let15-Back Tracking Algorithms I.ppt
int m = 0; 					//��ĸ��� 
int x[100]; 				//�洢���ǵ�ǰ�ʺ����ڵ��� ������x[3] = 5 ����˵�����еĻʺ���ڵ�5�� 
bool place(int k) {  		//�жϵ�ǰλ���Ƿ������ʺ��ܹ����� 
	for (int i = 1; i < k; i++) {
		if (x[i] == x[k] || abs(x[i] - x[k]) == abs(i - k))  //����������ֻ�����ֵ��ȼ����Թ����� 
			return false;		//��ǰλ�ò��ܷ� 
	}
	return true;
}
//��ӡ���� 
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
	int k = 1; 				//�ӵ�һ�п�ʼ�� 
	while (k > 0) {
		x[k]++;
		while (x[k] <= n && !place(k))
			x[k]++; 		//�����ǰλ�ò��ܷţ���Ѱ����һ��λ�� 
		if (x[k] <= n) {
			if (k == n) {	//����Ľ� 
				print(x, n); k--; m++;
			}
			else {
				k++; x[k] = 0; //����һ�еĻʺ� 
			}
		}
		else k--;  			//k > n �Ҳ�������� 
	}
}

int main() {
	nqueens(8);
	cout<<m;
	return 0;
}

