class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;
        int i=0;
        int j = heights.size()-1;
        int area = 0;
        while(i<j)
        {
            area = min(heights[i], heights[j]) * (j-i);
            if(area > max)
                max = area;

            heights[i] < heights[j] ? i++ : j--;
        }

        return max;
    }
};
