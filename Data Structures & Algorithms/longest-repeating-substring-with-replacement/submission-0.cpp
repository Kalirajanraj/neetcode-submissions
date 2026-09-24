class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0;
        int ans = 0;
        int maxFreq = 0;

        for(int right=0; right<s.size(); right++)
        {
            count[s[right] - 'A']++;
            maxFreq = max(maxFreq, count[s[right] - 'A']);

            int windowSize = right - left + 1;
            int replacement = windowSize - maxFreq;

            if(replacement > k)
            {
                count[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right-left+1);
        }

        return ans;
    }
};
