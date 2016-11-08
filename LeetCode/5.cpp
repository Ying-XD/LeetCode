#include "head.h"
/***** Question ******
 * Given a string S, find the longest palindromic substring in S. You may 
 * assume that the maximum length of S is 1000, and there exists one unique 
 * longest palindromic substring.
 */

string Solution::longestPalindrome(string s) {
	int max_len = 1;
	int s_pos = 0;
	const size_t n = s.length();
	//bool f[1000][2];
	//memset(f, 0, sizeof(f));
	//int state = 0;
	//for (size_t j = 0; j < n; j++) {
	//	f[j][state] = true;
	//	for (size_t i = 0; i < j; i++){
	//		f[i][state] = (s[i] == s[j] && (j - i < 2 || f[i + 1][1 - state]));
	//		if (f[i][state] && max_len < j - i + 1) {
	//			max_len = j - i + 1;
	//			s_pos = i;
	//		}
	//	}
	//	state = 1 - state;
	//}
	bool ff[1000];
	memset(ff, 0, sizeof(ff));
	for (size_t j = 0; j < n; j++) {
		ff[j] = true;
		for (size_t i = 0; i < j; i++) {
			ff[i] = (s[i] == s[j] && (j - i < 2 || ff[i + 1]));
			if (ff[i] && max_len < j - i + 1) {
				max_len = j - i + 1;
				s_pos = i;
			}
		}
	}
	return s.substr(s_pos, max_len);
}

/*****
	可以很容易知道动态规划方程：
	f[i][j] = (s[i] == s[j]) ? f[i+1][j-1] : false;
	由此可以求出 f[i][j] 也就是 s[i]s[i+1]...s[j] 是否为 回文数。
	**注：求f[i][j] 时先要知道f[i+1][j-1] 的状态. 所以，这里我们先遍历j再遍历i
	
	我们也可以发现， 这里前一个状态只记录在 f[j-1]中， 并未更新， 所以只需要 n * 2 的数组就可以了。
	
	更进一步，在求ff[i] 时， ff[i+1] 可以用以记录上状态的信息。
	我们可以用一个一维数组实现。


	还有一个O(n) 的解题思路
	http://articles.leetcode.com/longest-palindromic-substring-part-ii/
*/