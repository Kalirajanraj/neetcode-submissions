class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length())
            return "";
        
        if(t == s)
            return s;

        vector<int> need(128,0);
        vector<int> window(128,0);
        int required = 0;
        int formed = 0;

        for(char c : t)
        {
            need[c - 'A']++;
        }

        for(int count : need)
        {
            if(count > 0)
                required++;
        }

        int left = 0;
        int bestLen = INT_MAX;
        int bestStart = 0;

        for(int right=0; right<s.size(); right++)
        {
            int idx = s[right] - 'A';
            window[idx]++;
            if(need[idx] > 0 && window[idx] == need[idx])
                formed++;

            while(formed == required)
            {
                int len = right - left + 1;
                if(len < bestLen)
                {
                    bestLen = len;
                    bestStart = left;
                }

                int leftIdx = s[left] - 'A';
                window[leftIdx]--;

                if(need[leftIdx] > 0 && window[leftIdx] < need[leftIdx])
                    formed--;

                left++; 
            }
        }

        if(bestLen == INT_MAX)
            return "";

        return s.substr(bestStart, bestLen);
    }
};
