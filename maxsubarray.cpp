// maximum sub array using divide and conquer algorithm O(n log n)
// maximum sub array using kadane algorithm O(n)

#include <bits/stdc++.h>
using namespace std;

int maxSubArrayKadane(vector<int> &arr, int left, int right)
{
	int max_so_far = INT_MIN;
	int max_ending_here = 0;
	for (int i = left; i <= right; i++)
	{
		max_ending_here = max_ending_here + arr[i];
		if (max_ending_here < 0)
		{
			max_ending_here = 0;
		}
		if (max_so_far < max_ending_here)
		{
			max_so_far = max_ending_here;
		}
	}
	return max_so_far;
}

int crossMaxSubArray(vector<int> &arr, int left, int mid, int right)
{
	int leftSum = INT_MIN;
	int sum = 0;
	for (int i = mid; i >= left; i--)
	{
		sum += arr[i];
		if (sum > leftSum)
			leftSum = sum;
	}
	int rightSum = INT_MIN;
	sum = 0;
	for (int i = mid + 1; i <= right; i++)
	{
		sum += arr[i];
		if (sum > rightSum)
			rightSum = sum;
	}
	return leftSum + rightSum;
}

int maxSubArrayDivideAndConquer(vector<int> &arr, int left, int right)
{
	if (left == right)
		return arr[left];
	int mid = left + (right - left) / 2;
	int leftMax = maxSubArrayDivideAndConquer(arr, left, mid);
	int rightMax = maxSubArrayDivideAndConquer(arr, mid + 1, right);
	int midMax = crossMaxSubArray(arr, left, mid, right);
	return max(max(leftMax, rightMax), midMax);
}

void solve(int cases = 1)
{
	// solve the problem here
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i]; // read input negative or positive
	// cout << maxSubArrayKadane(arr, 0, n-1) << endl;
	cout << maxSubArrayDivideAndConquer(arr, 0, n - 1) << endl;
}

int main()
{
	int cases = 1; // 1 or more cases
	// cin >> cases;
	while (cases--)
	{
		solve();
	}
	return 0;
}