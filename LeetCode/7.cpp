#include "head.h"
/***** Question *****
 * Reverse digits of an integer.

 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 */
int Solution::reverse(int x) {
	int flag = 1;
	if (x == INT_MIN) return 0;
	if (x < 0) {
		x = -x;
		flag = -1;
	}
	long long y = 0;
	while (x) {
		y = y * 10 + x % 10;
		cout << x % 10 << " :\t" << y <<endl;
		x /= 10;
	}
	if (y > INT_MAX) return 0;
	return flag * y;
}
/*
	注意边界条件。 特别是 INT_MIN 的值，没有与之对应的正数
*/