#include <iostream>

int partition(int arr[], int low, int high) {
	int mid = low + (high - low) / 2;
	std::swap(arr[mid], arr[high]);
	int pivot = arr[high], i = low;
	for (int j = low; j < high; j++)
		if (arr[j] <= pivot) {
			std::swap(arr[i], arr[j]);
			i++;
		}
	std::swap(arr[i], arr[high]);
	return i;
}

void quick(int arr[], int low, int high) {
	if (low < high) {
		int p = partition(arr, low, high);
		quick(arr, low, p - 1);
		quick(arr, p + 1, high);
	}
}

int main() {
	int arr[] = { 1, 3, 5, 7, 9, 0, 2, 4, 6, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quick(arr, 0, n - 1);
	for (int i : arr)
		std::cout << i << " ";
	return 0;
}
