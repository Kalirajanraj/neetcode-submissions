class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0, i=0, j = heights.size()-1, area = 0;
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
