    void rotateMatrix(vector<vector<int>>& mat) {
        // code here
        int size = mat.size();
        
        for(int i = 0; i<size; i++)
        {
            for(int j = i; j<size; j++)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        
        for(int i = 0 , j = size-1; i<=j; i++, j--)
        {
            swap(mat[i], mat[j]);
        }
        
        return;
    }