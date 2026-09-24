class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        map<int, vector<int>, greater<int>> m;
        for(const auto& n : nums)
        {
            freq[n]++;
        }

        for(const auto& iter : freq)
        {
            m[iter.second].push_back(iter.first);
        }

        vector<int> ans;
        int j=0;
        for(const auto& iter : m)
        {
            for(int i=0; i<iter.second.size(); i++)
            {
                if(j>=k)
                    return ans;

                ans.push_back(iter.second[i]);
                j++;
            }
        }

        return ans;
    }
};
