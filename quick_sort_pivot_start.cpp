#include <iostream>
using namespace std;

void quick(int* arr, int l, int r) {
	if (l < r){
		int pivot = arr[l];
		int i = r + 1;

		for (int j = r; j > l; j--) // 시작을 피봇으로 잡았으므로 역방향 루프
			if (arr[j] >= pivot) 	swap(arr[--i], arr[j]); // 피봇보다 큰 값을 오른쪽으로 몰아 넣는다.

		swap(arr[i - 1], arr[l]);

		quick(arr, l, i - 2);
		quick(arr, i, r);
	}

}
int main() {
	int arr[10] = { 3,4,1,7,4,5,10,7,9,1 };
	quick(arr, 0, 9);
	for (int i = 0; i < 10; i++) cout << arr[i] << ' '; // 1,1,3,4,4,5,6,7,7,9,10
}