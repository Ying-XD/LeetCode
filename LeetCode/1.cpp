#include "head.h"
#include <unordered_map>
using std::unordered_map;
/***** Question *****
 *	Given an array of integers, return indices of the two numbers such that 
 *	they add up to a specific target.
 *	You may assume that each input would have exactly one solution.
 *
 *	Example:
 *	Given nums = [2, 7, 11, 15], target = 9,
 *
 *	Because nums[0] + nums[1] = 2 + 7 = 9,
 *	return [0, 1].
 */
vector<int> Solution::twoSum(vector<int>& nums, int target) {
	vector<int> res;
	unordered_map<int, int> map;
	size_t i, j;
	for (i = 0; i < nums.size(); ++i) {
		auto itr = map.find(target - nums[i]);
		if (itr != map.end()) {
			res.push_back(static_cast<int>(itr->second));
			res.push_back(static_cast<int>(i));
			break;
		}
		map[nums[i]] = i;
	}
	map.clear();
	return res;
}
