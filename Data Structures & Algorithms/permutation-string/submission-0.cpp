class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;

        vector<int> count1(26,0);
        vector<int> count2(26,0);

        for(char c : s1)
        {
            count1[c-'a']++;
        }

        for(int i=0; i<s1.length(); i++)
        {
            count2[s2[i] - 'a']++;
        }

        if(equal(count1.begin(), count1.end(), count2.begin()))
            return true;

        for(int right = s1.length(); right < s2.length(); right++)
        {
            count2[s2[right] - 'a']++;

            int left = right - s1.length();
            count2[s2[left] - 'a']--;

            if(equal(count1.begin(), count1.end(), count2.begin()))
                return true;
        }

        return false;
    }
};
