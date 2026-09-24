class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<char, 26>, vector<string>> m;
        for(const auto& str : strs)
        {
            array<char, 26> chars{};
            for(const char c : str)
            {
                chars[(int)c - 97]++;
            }
            m[chars].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto iter : m)
        {
            ans.push_back(iter.second);
        }

        return ans;
    }
};
