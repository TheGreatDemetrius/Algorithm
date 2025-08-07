#include <iostream>

void merge(int arr[], int n) {
	if (n <= 1) return;
	int* aux = new int[n];
	int* src = arr;
	int* dst = aux;
	for (int size = 1; size < n; size *= 2) {
		for (int left = 0; left < n; left += 2 * size) {
			int mid = std::min(left + size, n),
				right = std::min(left + 2 * size, n),
				i = left,
				j = mid,
				count = right - left;
			for (int k = left; k < left + count; k++)
				if (i < mid && (j >= right || src[i] <= src[j]))
					dst[k] = src[i++];
				else
					dst[k] = src[j++];
		}
		std::swap(src, dst);
	}
	if (src != arr)
		for (int i = 0; i < n; ++i)
			arr[i] = src[i];
	delete[] aux;
}

int main() {
	int arr[] = { 1, 3, 5, 7, 9, 0, 2, 4, 6, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	merge(arr, n);
	for (int i : arr)
		std::cout << i << " ";
	return 0;
}
