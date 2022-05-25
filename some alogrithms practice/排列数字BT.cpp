#include<iostream>
using namespace std;
int n;
int path[100];
bool st[100];
void dfs(int p){
	if(p == n){
		for(int i = 0; i < n; i++)
			cout<<path[i]<<' ';
		cout<<endl;
		return;
	}
	for(int i = 0; i < n; i++){
		if(!st[i]){
			path[p] = i + 1;  //n从1开始 
			st[i] = true;
			dfs(p + 1);
			st[i] = false;  //回溯 
		}
	}
}

int main(){
	cin>>n;
	dfs(0);
	return 0;
} 
