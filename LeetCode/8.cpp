#include "head.h"
/***** Question *****
 * Implement atoi to convert a string to an integer.
 * Hint: Carefully consider all possible input cases. If you want a challenge, 
 * please do not see below and ask yourself what are the possible input cases.

 * Notes: It is intended for this problem to be specified vaguely 
 * (ie, no given input specs). You are responsible to gather all the input 
 * requirements up front.

 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your 
 * function signature accepts a const char * argument, please click the 
 * reload button  to reset your code definition.
 */
int Solution::myAtoi(string str) {
	int res = 0;
	int flag = 1;
	size_t i = 0;
	for (; str[i] <'0' || str[i] > '9'; i++) {
		if (str[i] == '-') flag = -flag;
	}

	for (; i < str.length(); i++) {
		if (str[i] == ' ') return 0;
		res = res * 10 + str[i] - '0';
	}

	return res * flag;
}