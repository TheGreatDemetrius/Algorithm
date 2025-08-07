#include <iostream>

int jump(int arr[], int n, int x)
{
	int jump = 1;
	while (jump * jump < n)
		jump++;
	int step = jump, prev = 0;
	while (arr[(step < n ? step : n) - 1] < x)
	{
		prev = step;
		step += jump;
		if (prev >= n)
			return -1;
	}
	while (arr[prev] < x)
	{
		prev++;
		if (prev == (step < n ? step : n))
			return -1;
	}
	if (arr[prev] == x)
		return prev;
	return -1;
}

int main()
{
	int arr[] = { 0, 2, 4, 6, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	std::cout << jump(arr, n, 8);
	return 0;
}
