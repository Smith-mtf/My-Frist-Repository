#include<iostream>
#include<algorithm>
using namespace std;
//�ǵݹ� 
//���彲���  Let15-Back Tracking Algorithms III.ppt 
int n = 5;	//��Ʒ����
//��һ��Ϊ0����Ϊ��1��ʼ
double P[100] = { 0,20,30,65,40,60 }; // ��Ʒ�ļ�ֵ
double W[100] = { 0,10,20,30,40,50 }; // ��Ʒ������
int item[100] = { 0,1,2,3,4,5 };	 // ��Ʒ����� ����˵�ź���{0,5,3,2,1,4}��
					//��ô�ź����k=1����Ʒ��Ӧ����ž���item[1] = 5
					//��ʱ���ѡ����Ʒ����Ӧx[item[k]] = 1	
//��ʵ���Խ����ṹ�����Ʒ����ż�ֵ����һ����
double perp[100]; //��λ��Ʒ�ļ�ֵ
double M = 100;   //��������
double fw, fp;	//����װ������ֵ��������
int X[100];		//��Ʒ��ѡ�� 1Ϊѡ0Ϊ��ѡ��������ӡ��Ʒ��ѡ��

//����λ��ֵ��������
void knapsack() {
	for (int i = 1; i <= n; i++)
		perp[i] = P[i] / W[i];
	for(int i = 1; i< n; i++)
		for (int j = 1; j < n - i; j++)
			if (perp[j] < perp[j + 1]) {
				swap(perp[j], perp[j + 1]);
				swap(P[j], P[j + 1]);
				swap(W[j], W[j + 1]);
				swap(item[j], item[j + 1]);
			}
}
//���ص�ǰ�ڵ����ȡ��������ֵ 
double bound(double p, double w, int k) {
	double b = p;
	double c = w;
	for (int i = k + 1; i <= n; i++) {
		c += W[i];
		if (c < M)
			b += P[i];
		else return (b + (1-(c - M)/W[i]) * P[i]);  //װһ���֣��������װһ���֣� 
	}
	return b;
}

void bknap1() {
	double cw = 0;
	double cp = 0;
	int k = 1, Y[100];
	fp = -1;
	while (1) {
		while (k <= n && cw + W[k] <= M) {
			cw += W[k]; cp += P[k]; Y[item[k]] = 1; k++;	//�Ⱦ����ܵر������ӣ����洢ѡ��
		}
		if (k > n) {
			fp = cp; fw = cw; k = n;
			for (int i = 1; i <= n; i++)			//���k>n, ��ô�����Ѿ��ҵ������Ž�
				X[i] = Y[i];
		}
		else Y[item[k]] = 0;                              //���k<=n��ô��Ʒk���ܱ����뱳������ʱӦ�ñ��������Һ��ӣ���k����Ʒ��ѡ��Y[k] = 0��
		while (bound(cp, cw, k) <= fp) {			//��bound����Ƿ���ȡ������ֵ�Ŀ�����
			while (k != 0 && Y[item[k]] != 1)				//���ݵ����һ��û�������Һ��ӵĽڵ�
				k--;	
			if (k == 0)								//ѭ��������Ҫô�ҵ����õķ�����Ҫô�����˳�
				return;
			Y[item[k]] = 0; cw -= W[k]; cp -= P[k];
		}
		k++;
	}
}
int main() {
	knapsack();
	bknap1();
	cout << fp << ' ' << fw << endl;
	for (int i = 1; i <= n; i++)
		if(X[i] == 1)
			cout<<i<<' ';
}


