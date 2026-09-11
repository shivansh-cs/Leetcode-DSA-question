class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // 9 rows, 9 columns, 9 boxes
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                char num = board[i][j];

                // Ignore empty cells
                if (num == '.') {
                    continue;
                }

                // Find which 3x3 box this cell belongs to
                int box = (i / 3) * 3 + (j / 3);

                // Check for duplicate
                if (rows[i].count(num) ||
                    cols[j].count(num) ||
                    boxes[box].count(num)) {
                    return false;
                }

                // Add number
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[box].insert(num);
            }
        }

        return true;
    }
};