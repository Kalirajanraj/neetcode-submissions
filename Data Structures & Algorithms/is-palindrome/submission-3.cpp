class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        ranges::for_each(s, [&str](const char c)
	    {
		    char lowerCase = tolower(c);
		    if (lowerCase >= 'a' && lowerCase <= 'z' || (lowerCase >= '0' && lowerCase <= '9'))
			    str.append(1, lowerCase);
	    });

        for(int i=0, j=str.size()-1; i<=j; i++, j--)
        {
            if(str[i] != str[j])
                return false;
        }
        return true;
    }
};
