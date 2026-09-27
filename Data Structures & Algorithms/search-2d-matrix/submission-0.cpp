class Solution {
public:

    bool helper(int st, int end, vector<int>& row, int target)
    {
        if(st > end)
            return false;
        int mid = st + (end-st)/2;
        if(row[mid] == target)
            return true;
        else if(row[mid] > target)
            return helper(st, mid-1, row, target);
        else
            return helper(mid + 1, end, row, target);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++)
        {
            if(helper(0, matrix[i].size()-1, matrix[i], target))
                return true;
        }

        return false;
    }
};
