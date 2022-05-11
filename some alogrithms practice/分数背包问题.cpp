#include <iostream>
using namespace std;

double weight[5] = { 10,20,30,40,50 };
double price[5] = { 2,1.5,2.1,1,1.2 };
struct myCompare {
	bool operator()(const double& x, const double& y)const
	{
		return x > y;
	}
};
map<double, double, myCompare> goods; //用来存放物品重量和单位价钱，自定义key降序排列

//capacity用来表示背包剩余容量
double greedy_knapsack(map<double,double, myCompare> m,int capacity) {

	map<double, double>::iterator it = m.begin();  //迭代器用来遍历map
	double value = 0; //总价值
	//从单位价值最高的物品开始，直到背包装满
	while (it != m.end()) {
		if (capacity > it->second)
			value += it->first * it->second;
		else {
			value += it->first * capacity;
			break;
		}
		capacity -= it->second;
		it++;
	}
	return value;
}
int main() {
	for (int i = 0; i < 5; i++)
		goods.insert(make_pair(price[i], weight[i]));
	int capacity = 100;
	/*map<double, double>::iterator it = goods.begin();
	while (it != goods.end()) {
		cout << it->first << ' ' << it->second << endl;
		it++;
	}*/
	cout << "knapsack_capacity:" << capacity << ' ' << endl << "total_value:" << greedy_knapsack(goods, capacity) << endl;
	return 0;
}