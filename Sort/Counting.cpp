#include <iostream>

void counting(int arr[], int n) {
	if (n == 0) return;
	int min = arr[0], max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	int range = max - min + 1;
	int* count = new int[range]();
	for (int i = 0; i < n; i++)
		count[arr[i] - min]++;
	for (int i = 0, idx = 0; i < range; i++)
		while (count[i]-- > 0)
			arr[idx++] = i + min;
	delete[] count;
}

int main() {
	int arr[] = { 1, 3, 5, 7, 9, 0, 2, 4, 6, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	counting(arr, n);
	for (int i : arr)
		std::cout << i << " ";
	return 0;
}
