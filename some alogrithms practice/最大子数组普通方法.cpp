#include <iostream>
#define NUM 6

using namespace std;

int a[NUM] = {-2, 11, -4, 13, -5, -2};

void original_max_subarray(int& maxsum, int& besti, int& bestj){
	int sum = 0;
	maxsum = -1;
	for(int i = 0; i < NUM; i++){
		sum = 0;
		for(int j = i; j < NUM; j++){
			sum += a[j];
			if(sum >maxsum){
				maxsum = sum;
				besti = i + 1; bestj = j + 1;
			}
		}
	}
}

int main(){
	int maxsum, besti, bestj;
	original_max_subarray(maxsum, besti, bestj);
	printf("%d %d %d", maxsum, besti, bestj);
	return 0;
}
