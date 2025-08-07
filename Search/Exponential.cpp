#include <iostream>

int binary(int arr[], int l, int r, int x) {
	if (l > r) return -1;
	int mid = l + (r - l) / 2;
	if (arr[mid] == x) return mid;
	if (arr[mid] > x) return binary(arr, l, mid - 1, x);
	return binary(arr, mid + 1, r, x);
}

int exponential(int arr[], int n, int x) {
	if (arr[0] == x) return 0;
	int i = 1;
	while (i < n && arr[i] <= x) i = i * 2;
	return binary(arr, i / 2, (i < n ? i : n - 1), x);
}

int main() {
	int arr[] = { 0, 2, 4, 6, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	std::cout << exponential(arr, n, 8);
	return 0;
}
