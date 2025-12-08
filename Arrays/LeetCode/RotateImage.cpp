void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i<n; i++)
        {
            for(int j = i; j<n; j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i = 0, j = n-1;i<=j; i++, j--)
        {
            for(int k = 0; k <n ; k++)
            {
                swap(matrix[k][i],matrix[k][j]);
            }
        }

    }