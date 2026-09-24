class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            auto iter = m.find(target - nums[i]);
            if(iter == m.end())
            {
                m.emplace(nums[i], i);
            }
            else
            {
                if(i > iter->second)
                {
                    ans.push_back(iter->second);
                    ans.push_back(i);
                }
                else
                {
                    ans.push_back(i);
                    ans.push_back(iter->second);
                }

                break;
            }
        }

        return ans;
    }
};
