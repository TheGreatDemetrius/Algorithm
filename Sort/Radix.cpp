#include <iostream>

void radix(int arr[], int n) {
	if (n <= 0) return;
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	int* output = new int[n];
	for (int exp = 1; max / exp > 0; exp *= 10) {
		int count[10] = { 0 };
		for (int i = 0; i < n; i++) {
			int digit = (arr[i] / exp) % 10;
			count[digit]++;
		}
		for (int i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (int i = n - 1; i >= 0; i--) {
			int digit = (arr[i] / exp) % 10;
			output[count[digit] - 1] = arr[i];
			count[digit]--;
		}
		for (int i = 0; i < n; i++)
			arr[i] = output[i];
	}
	delete[] output;
}

int main() {
	int arr[] = { 1, 3, 5, 7, 9, 0, 2, 4, 6, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	radix(arr, n);
	for (int i : arr)
		std::cout << i << " ";
	return 0;
}
