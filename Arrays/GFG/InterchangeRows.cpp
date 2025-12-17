class Solution {
  public:
    // Function to interchange the rows of a matrix.
    void interchangeRows(vector<vector<int> > &matrix) {
        // code here
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int i = 0; i<row/2; i++)
        {
            for(int j = 0; j<col; j++)
            {
                swap(matrix[i][j], matrix[row-i-1][j]);
            }
        }
        
    }
};
