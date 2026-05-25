class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        bool firstrow=false;
        bool firstcol=false;
         for(int i=0;i<row;i++){
            if(matrix[i][0]==0){
                firstcol=true;
            }
        }

        for(int j=0;j<col;j++){
            if(matrix[0][j]==0){
                firstrow=true;
            }
        }
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int cols=1;cols<col;cols++){
            if(matrix[0][cols]==0){
                for(int rows=1;rows<row;rows++){
                    matrix[rows][cols]=0;
                }
            }
        }
        for(int a=1;a<row;a++){
            if(matrix[a][0]==0){
                for(int b=1;b<col;b++){
                    matrix[a][b]=0;
                }
            }
        }
        
        if(firstrow){
            for(int j=0;j<col;j++){
                matrix[0][j]=0;
            }
        }

        if(firstcol){
            for(int i=0;i<row;i++){
                matrix[i][0]=0;
            }
        }
                
        return;
    }
};
