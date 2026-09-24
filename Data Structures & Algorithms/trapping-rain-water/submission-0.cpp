class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lheights(height.size(), 0);
        vector<int> rheights(height.size(), 0);

        int curr = 0;
        for(int i=0; i<height.size(); i++)
        {
            lheights[i] = curr;
            if(height[i] > curr)
                curr = height[i];
        }

        curr = 0;
        for(int i=height.size()-1; i>=0; i--)
        {
            rheights[i] = curr;
            if(height[i] > curr)
                curr = height[i];
        }

        int total = 0;
        for(int i=0; i<height.size(); i++)
        {
            int cap = min(lheights[i], rheights[i]) - height[i];
            if(cap > 0)
                total += cap;
        }

        return total;
    }
};
