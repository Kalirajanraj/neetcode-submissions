class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows(board.size()), coulmns(board.size()), square(board.size());
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if(board[i][j] == '.')
                    continue;
                int squareIdx = (i/3)*3 + (j/3);
                int num = board[i][j] - '0';
                if(rows[i].find(num) != rows[i].end())
                    return false;

                rows[i].insert(num);

                if(coulmns[j].find(num) != coulmns[j].end())
                    return false;

                coulmns[j].insert(num);

                if(square[squareIdx].find(num) != square[squareIdx].end())
                    return false;
                    
                square[squareIdx].insert(num);
            }
        }

        return true;
    }
};
