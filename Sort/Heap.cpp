#include <iostream>

void heapify(int arr[], int n, int i) {
	while (true) {
		int largest = i, left = 2 * i + 1, right = 2 * i + 2;
		if (left < n && arr[left] > arr[largest])
			largest = left;
		if (right < n && arr[right] > arr[largest])
			largest = right;
		if (largest == i)
			break;
		std::swap(arr[i], arr[largest]);
		i = largest;
	}
}

void heap(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i > 0; i--) {
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 0, 2, 4, 6, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	heap(arr, n);
	for (int i : arr)
		std::cout << i << " ";
	return 0;
}
