#include <iostream>

void bubble(int arr[], int n) {
	for (int i = n - 1; i > 0; i--) {
		bool swapped = false;
		for (int j = 0; j < i; j++)
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		if (!swapped) break;
	}
}

int main() {
	int arr[] = { 1, 3, 5, 7, 9, 0, 2, 4, 6, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bubble(arr, n);
	for (int i : arr)
		std::cout << i << " ";
	return 0;
}
