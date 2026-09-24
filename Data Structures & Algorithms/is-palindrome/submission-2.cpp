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

        string copy{ str };
        ranges::reverse(str);
        return str == copy;
    }
};
