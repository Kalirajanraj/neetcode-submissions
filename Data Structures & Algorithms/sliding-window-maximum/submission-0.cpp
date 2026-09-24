class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxQueue;
        vector<int> ans;
        for(int i=0; i<k-1; i++)
        {
            maxQueue.emplace(nums[i], i);
        }

        for(int i=0, j=k-1; j<nums.size(); i++, j++)
        {
            maxQueue.emplace(nums[j], j);
            while(!maxQueue.empty())
            {
                auto max = maxQueue.top();
                if(max.second >= i && max.second <= j)
                {
                    ans.push_back(max.first);
                    break;
                }
                else
                {
                    maxQueue.pop();
                }  
            }
        }

        return ans;
    }
};
