// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem704.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size(); //左闭右开
        while(left < right)
        {
            int middle = left + ((right - left)>>1);
            if (nums[middle] < target)
            {
                left = middle + 1;
            }else if (nums[middle] > target)
            {
                right = middle;
            }else
            {
                return middle;
            }
        }
        return -1;
    }
};
// @lc code=end

