class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedStr;
        for(const auto& str : strs)
        {
            encodedStr.append(to_string(str.size()) + "#" + str);
        }
        return encodedStr;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(int i=0; i<s.size();)
        {
            string temp;
            while(s[i] != '#')
            {
                temp += s[i];
                i++;
            }

            i++;
            int size = stoi(temp);
            temp.clear();
            for (int j = 0; j < size; j++) {
                temp += s[i];
                i++;
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
