#include<iostream>
#include<algorithm>
using namespace std;
//非递归 
//具体讲解见  Let15-Back Tracking Algorithms III.ppt 
int n = 5;	//物品数量
//第一个为0是因为从1开始
double P[100] = { 0,20,30,65,40,60 }; // 物品的价值
double W[100] = { 0,10,20,30,40,50 }; // 物品的重量
int item[100] = { 0,1,2,3,4,5 };	 // 物品的序号 比如说排好序{0,5,3,2,1,4}，
					//那么排好序第k=1的物品对应的序号就是item[1] = 5
					//此时如果选该物品，对应x[item[k]] = 1	
//其实可以建个结构体把物品的序号价值重量一起存放
double perp[100]; //单位物品的价值
double M = 100;   //背包容量
double fw, fp;	//背包装的最大价值和总重量
int X[100];		//物品的选择 1为选0为不选，用来打印物品的选择

//按单位价值降序排序
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
//返回当前节点可能取到的最大价值 
double bound(double p, double w, int k) {
	double b = p;
	double c = w;
	for (int i = k + 1; i <= n; i++) {
		c += W[i];
		if (c < M)
			b += P[i];
		else return (b + (1-(c - M)/W[i]) * P[i]);  //装一部分（假设可以装一部分） 
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
			cw += W[k]; cp += P[k]; Y[item[k]] = 1; k++;	//先尽可能地遍历左孩子，并存储选择
		}
		if (k > n) {
			fp = cp; fw = cw; k = n;
			for (int i = 1; i <= n; i++)			//如果k>n, 那么我们已经找到了最优解
				X[i] = Y[i];
		}
		else Y[item[k]] = 0;                              //如果k<=n那么物品k不能被放入背包，此时应该遍历他的右孩子（第k个物品不选择即Y[k] = 0）
		while (bound(cp, cw, k) <= fp) {			//用bound检查是否有取到最大价值的可能性
			while (k != 0 && Y[item[k]] != 1)				//回溯到最近一个没有生成右孩子的节点
				k--;	
			if (k == 0)								//循环结束后要么找到更好的方案，要么程序退出
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


