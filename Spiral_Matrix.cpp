class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> v;
    
            int row_size = matrix.size();
            if (row_size == 0) return v;
            int col_size = matrix[0].size();
    
            int top = 0, bottom = row_size - 1;
            int left = 0, right = col_size - 1;
    
            while (top <= bottom && left <= right) {
                for (int j = left; j <= right; j++) {
                    v.push_back(matrix[top][j]);
                }
                top++;
    
                for (int i = top; i <= bottom; i++) {
                    v.push_back(matrix[i][right]);
                }
                right--;
    
                if (top <= bottom) {
                    for (int j = right; j >= left; j--) {
                        v.push_back(matrix[bottom][j]);
                    }
                    bottom--;
                }
    
                if (left <= right) {
                    for (int i = bottom; i >= top; i--) {
                        v.push_back(matrix[i][left]);
                    }
                    left++;
                }
            }
    
            return v;
        }
    };