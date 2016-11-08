#include "head.h"
/***** Question *****
 * Given an array of integers, every element appears three times except 
 * for one. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. 
 * Could you implement it without using extra memory?
*/

int Solution::singleNumber(vector<int>& nums) {
	int one = 0, two = 0, three = 0;
	for (const int & num : nums) {
		three = two & num;
		two = (one & num) | (two & (~num));
		one ^= num;
		one &= ~three;		// 清除 3 倍的
	}
	return one | two;
}
/* Soluation
 one   中第i位 表示，在已出现的数字中，该bit位上 出现 1 的次数 是否为 1 次
 two   中第i位 表示，在已出现的数字中，该bit位上 出现 1 的次数 是否为 2 次
 three 中第i位 表示，在已出现的数字中，该bit位上 出现 1 的次数 是否为 3 次
*/