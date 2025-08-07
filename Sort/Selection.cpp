#include <iostream>

void selection(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[min])
				min = j;
		if (min != i)
			std::swap(arr[min], arr[i]);
	}
}

int main() {
	int arr[] = { 1, 3, 5, 7, 9, 0, 2, 4, 6, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	selection(arr, n);
	for (int i : arr)
		std::cout << i << " ";
	return 0;
}
