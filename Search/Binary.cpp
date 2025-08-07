#include <iostream>

int binary(int arr[], int l, int r, int x) {
	if (l > r) return -1;
	int mid = l + (r - l) / 2;
	if (arr[mid] == x) return mid;
	if (arr[mid] > x) return binary(arr, l, mid - 1, x);
	return binary(arr, mid + 1, r, x);
}

int main() {
	int arr[] = { 0, 2, 4, 6, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	std::cout << binary(arr, 0, n - 1, 4);
	return 0;
}
