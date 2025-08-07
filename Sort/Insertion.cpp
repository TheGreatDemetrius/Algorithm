#include <iostream>

void insertion(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int key = arr[i], j = i - 1;
		for (; j >= 0 && arr[j] > key; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = key;
	}
}

int main() {
	int arr[] = { 1, 3, 5, 7, 9, 0, 2, 4, 6, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	insertion(arr, n);
	for (int i : arr)
		std::cout << i << " ";
	return 0;
}
