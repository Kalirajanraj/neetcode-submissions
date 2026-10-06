class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;
        for(int i=0; i<=n; i++)
        {
            int currHeight = (i==n) ? 0 : heights[i];
            while(!st.empty() && heights[st.top()] > currHeight)
            {
                int h = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                int w = right - left - 1;
                int area = h*w;
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }

        return maxArea;
    }
};
