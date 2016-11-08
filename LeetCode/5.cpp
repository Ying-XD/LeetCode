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
	���Ժ�����֪����̬�滮���̣�
	f[i][j] = (s[i] == s[j]) ? f[i+1][j-1] : false;
	�ɴ˿������ f[i][j] Ҳ���� s[i]s[i+1]...s[j] �Ƿ�Ϊ ��������
	**ע����f[i][j] ʱ��Ҫ֪��f[i+1][j-1] ��״̬. ���ԣ����������ȱ���j�ٱ���i
	
	����Ҳ���Է��֣� ����ǰһ��״ֻ̬��¼�� f[j-1]�У� ��δ���£� ����ֻ��Ҫ n * 2 ������Ϳ����ˡ�
	
	����һ��������ff[i] ʱ�� ff[i+1] �������Լ�¼��״̬����Ϣ��
	���ǿ�����һ��һά����ʵ�֡�


	����һ��O(n) �Ľ���˼·
	http://articles.leetcode.com/longest-palindromic-substring-part-ii/
*/