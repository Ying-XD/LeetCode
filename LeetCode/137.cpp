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
		one &= ~three;		// ��� 3 ����
	}
	return one | two;
}
/* Soluation
 one   �е�iλ ��ʾ�����ѳ��ֵ������У���bitλ�� ���� 1 �Ĵ��� �Ƿ�Ϊ 1 ��
 two   �е�iλ ��ʾ�����ѳ��ֵ������У���bitλ�� ���� 1 �Ĵ��� �Ƿ�Ϊ 2 ��
 three �е�iλ ��ʾ�����ѳ��ֵ������У���bitλ�� ���� 1 �Ĵ��� �Ƿ�Ϊ 3 ��
*/