class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ranges::sort(nums);
        vector<vector<int>> ans;
        for(int i=0; i<nums.size()-2; i++)
        {
            if(i>0 && nums[i] == nums[i-1])
                continue;

            if (nums[i] > 0)
                break;

            int j = i+1;
            int k = nums.size()-1;
            int target = -nums[i];
            while(j<k)
            {
                if(nums[j] + nums[k] > target)
                    k--;
                else if(nums[j] + nums[k] < target)
                    j++;
                else
                {
                    ans.push_back(vector<int>({nums[i], nums[j], nums[k]}));
                    j++;
                    k--;

                    // Skip duplicate second elements
                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    // Skip duplicate third elements
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};
