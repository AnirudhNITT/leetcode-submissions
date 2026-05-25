class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n/2;i++){
            vector<int>temp;
            temp=matrix[i];
            matrix[i]=matrix[n-i-1];
            matrix[n-i-1]=temp;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i>=j)continue;
                else {
                    int temp=matrix[i][j];
                    matrix[i][j]=matrix[j][i];
                    matrix[j][i]=temp;
                }
            }
        }
        return ;
    }
};
