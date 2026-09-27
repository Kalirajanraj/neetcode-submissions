class Solution {
public:

    int helper(int st, int end, vector<int>& nums, int target)
    {
        if(st > end)
            return -1;

        int mid = st + (end-st)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            return helper(st, mid-1, nums, target);
        else
            return helper(mid+1, end, nums, target);
    }
    int search(vector<int>& nums, int target) {
        return helper(0, nums.size()-1, nums, target);
    }
};
