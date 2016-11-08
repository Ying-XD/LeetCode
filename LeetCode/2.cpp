#include "head.h"
/***** Question *****
 * You are given two linked lists representing two non-negative numbers. The digits are stored 
 * in reverse order and each of their nodes contain a single digit. Add the two numbers and return it 
 * as a linked list.

 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2){
	ListNode	* head = new ListNode(-1);
	ListNode	* prev = head;
	int carry = 0;
	while (l1 || l2) {
		int val1 = (l1) ? l1->val : 0;
		int val2 = (l2) ? l2->val : 0;

		int val = (val1 + val2 + carry) % 10;
		carry = (val1 + val2 + carry) / 10;
		head->next = new ListNode(val);
		head = head->next;

		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;
	}
	if (carry) head->next = new ListNode(carry);
	head = prev->next;
	delete prev;
	return head;
}