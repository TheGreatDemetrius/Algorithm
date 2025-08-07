#include <iostream>

int linear(int arr[], int n, int x) {
	for (int i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

int main() {
	int arr[] = { 0, 2, 4, 6, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = linear(arr, n, 8);
	std::cout << result;
	return 0;
}
