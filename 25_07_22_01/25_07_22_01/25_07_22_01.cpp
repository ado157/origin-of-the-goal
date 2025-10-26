#include "iostream"
using namespace std;
void quickSort(int arr[], int left, int right) {
	if (left >= right)return;
	int pivot = arr[(left + right) / 2];
	int i = left, j = right;
	while (i <= j) {
		while (arr[i] < pivot)i++;
		while (arr[j] > pivot)j--;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	quickSort(arr, left, j);
	quickSort(arr, i, right);
}
int main() {
	//int num[] = { 10,11 };
	//int* p;
	//p =  num;
	//cout << p << endl;
	//cout << *p << endl;
	//p++;
	//cout << p << endl;
	//cout << *p << endl;
	int arr[] = { 5,2,9,1,5,6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}