#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	// 1. Two Sum
	vector<int> twoSum(vector<int>& nums, int target);
	// 2. Add Two Numbers
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	// 3. Longest Substring Without Repeating Characters
	int lengthOfLongestSubstring(string s);
	// 4. Median of Two Sorted Arrays
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
	// 5. Longest Palindromic Substring
	string longestPalindrome(string s);
	// 6. ZigZag Conversion
	string convert(string s, int numRows);
	// 7. Reverse Integer
	int reverse(int x);
	// 8. String to Integer (atoi)
	int myAtoi(string str);

	// 137. Single Number II
	int singleNumber(vector<int>& nums);
};