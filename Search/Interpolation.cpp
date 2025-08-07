#include <iostream>

int interpolation(int arr[], int lo, int hi, int x) {
	if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
		if (arr[lo] == arr[hi])
			return (x == arr[lo]) ? lo : -1;
		int pos = lo + ((x - arr[lo]) * (hi - lo)) / (arr[hi] - arr[lo]);
		if (arr[pos] == x)
			return pos;
		if (arr[pos] < x)
			return interpolation(arr, pos + 1, hi, x);
		return interpolation(arr, lo, pos - 1, x);
	}
	return -1;
}

int main() {
	int arr[] = { 0, 2, 4, 6, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	std::cout << interpolation(arr, 0, n - 1, 8);
	return 0;
}
