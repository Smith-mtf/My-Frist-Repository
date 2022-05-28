#include<iostream>
#include<string>
using namespace std;

//���ͼ���·������
//�����ڽӾ������ݽṹ
int edges[16][16] = { {0,5,3},
						{0,0,0,1,3,6},
						{0,0,0,0,8,7,6},
						{0,0,0,0,0,0,0,6,8},
						{0,0,0,0,0,0,0,3,5},
						{0,0,0,0,0,0,0,0,3,3},
						{0,0,0,0,0,0,0,0,8,4},
						{0,0,0,0,0,0,0,0,0,0,2,2},
						{0,0,0,0,0,0,0,0,0,0,0,1,2},
						{0,0,0,0,0,0,0,0,0,0,0,3,3},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,3,5},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,5,2},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,6,6},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3}
					};
int n = 16;		//��������
int path[100];		//����ö������·����Ӧ��� 
int cost[100];	//����ÿ���������·����
const int MAX = 0x3f3f3f3f;
int mincost(){
	for(int i = 0; i < n; i++)
		cost[i] = MAX;
	cost[n-1] = 0;
	for(int i = n - 2; i >= 0; i--)
		for(int j = 0; j < n; j++)
			if(edges[i][j] != 0)
				if(edges[i][j] + cost[j] < cost[i]){
					cost[i] = edges[i][j] + cost[j];
					path[i] = j;
				}
	return cost[0];
}

void printpath(int path[], int n){
	int i = 0;
	cout<<i<<"->";
	while(path[i] != n-1){
		cout<<path[i]<<"->";
		i = path[i];
	}
	cout<<path[i];
}
int main(){
	cout<<mincost()<<endl;
	printpath(path, 16);
	return 0;
}
