// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem27.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int leftIndex = 0;
        int rightIndex = nums.size() - 1; //因为用双指针所以不指空
        while (leftIndex <= rightIndex)
        {
            while (leftIndex <= rightIndex && nums[leftIndex] != val)
            {
                ++leftIndex;
            }
            while (leftIndex <= rightIndex && nums[rightIndex] == val)
            {
                --rightIndex;
            }
            if (leftIndex <= rightIndex) //不会出现=的情况
            {
                nums[leftIndex] = nums[rightIndex];
                leftIndex++;
                rightIndex--;
            }
        }
        return leftIndex;
    }
};
// @lc code=end

