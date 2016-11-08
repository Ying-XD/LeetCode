#include "head.h"
/****** Question ******
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number 
 * of rows like this: (you may want to display this pattern in a fixed font for better legibility)

 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:

 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */
string Solution::convert(string s, int numRos) {
	string res = "";
	if (numRos == 1) return s;
	int k = 2 * numRos - 2;
	for (size_t r = 0; r < numRos; r++) {
		for (size_t i = r; i < s.length(); i += k) {
			res += s[i];
			int pos = i + k - 2 * r;
			if (r != 0 && r!= numRos - 1 && pos < s.length()) {
				res += s[pos];
			}
		}
	}
	return res;
}