#include "head.h"
/***** Question *****
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time 
 * complexity should be O(log (m+n)).
 *
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 */

int find_kth(const int a[], int n, const int b[], int m, int k) {
	if (n < m) return find_kth(b, m, a, n, k);

	if (m == 0) return a[k - 1];
	if (k == 1) return min(a[0], b[0]);

	int j = min(m, k / 2);
	int i = k - j;
	if (a[i - 1] > b[j - 1]) return find_kth(a, i, b + j, m - j, k - j);
	if (a[i - 1] < b[j - 1]) return find_kth(a + i, n - i, b, j, k - i);
	return a[i - 1];
}
double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>&nums2) {
	double res;
	int n = nums1.size();
	int m = nums2.size();
	int k = (nums1.size() + nums2.size()) / 2;

	int m1 = find_kth(nums1.data(), n, nums2.data(), m, k + 1);
	res = static_cast<double>(m1);

	if ((n + m) % 2 == 0) {
		int m2 = find_kth(nums1.data(), n, nums2.data(), m, k);
		res = static_cast<double>(m1 + m2) / 2.0;
	}
	
	return res;
}

/*
 利用找第k大数的方法，在两边折半查找。
 要找到 i和j之间的联系： i+j = k；
 
 另一个思路：
 https://discuss.leetcode.com/topic/54889/solution-in-c-well-explained/2
 时间复杂度为O(log(min{n, m}));
 代码写的也很漂亮。
*/