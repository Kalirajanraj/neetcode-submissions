class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
            
        std::ranges::sort(nums);
        int ans = 1;
        int ansMax = ans;
        for(int i=0; i<nums.size(); i++)
        {
            if(ans > ansMax)
                ansMax = ans;

            if(i == nums.size() - 1)
                break;

            if(nums[i] == nums[i+1])
                continue;

            if(nums[i+1] - nums[i] != 1)
            {
                ans = 1;
                continue;
            }

            ans++;
        }

        return ansMax;
    }
};
