#include "head.h"
#include <algorithm>
/***** Question *****
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3. 
 *
 * Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

int Solution::lengthOfLongestSubstring(string s) {
	int preIndex[256] = { };
	memset(preIndex, 0, sizeof(preIndex));
	int res = 0;
	int curMaxLen = 0;
	
	for (int i = 0; i < s.length(); i++) {
		curMaxLen = min(curMaxLen , i - preIndex[s[i]]) + 1;
		preIndex[s[i]] = i + 1;
		res = max(res, curMaxLen);
	}
	return res;
}

/***** Solution *****
 * https://discuss.leetcode.com/topic/56869/c-9ms-and-java-5ms-solutions-o-n-time-o-1-space
 * Basic idea is that the length of the longest substring 	ending at position i is the lesser of
 *	1.	the length of the longest substring ending at position i - 1 plus one
 *	2.	i - prevIndexOf[s[i]] i.e. the number of characters since the previous
 *		occurrence of the character at position i
 * In the implementations below, i - prevIndexOf[c] is actually the number of
 * characters since the last occurrence of c minus 1. This makes it convenient
 * to compare it to the length of the longest substring ending at position i - 1
 * and add one to the lesser of the two in order to obtain the length of
 * the longest substring ending at position i.
 */