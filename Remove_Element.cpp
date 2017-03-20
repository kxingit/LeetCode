/*
 * 	Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * 	Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * 	The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 11:18 - 11:19
        int l = 0, r = 0;
        for(int r = 0; r < nums.size(); r++) {
            if(nums[r] == val) continue;
            else {
                nums[l++] = nums[r];
            }
        }
        return l;
    }
};
