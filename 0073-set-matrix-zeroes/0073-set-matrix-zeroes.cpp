class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // optimal space complexity solution 

        bool isrow0 = false;
        bool iscol0 = false;

        for( int i= 0 ; i < matrix.size(); i ++){
            if( matrix[i][0] == 0) iscol0= true;
        }
        for( int j = 0 ; j < matrix[0].size(); j ++){
                if( matrix[0][j]==0) isrow0= true;
        }
        

        for( int i=1 ; i < matrix.size(); i ++){
            for( int j = 1 ; j < matrix[0].size(); j ++){
                if (matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }

        for( int i=1 ; i < matrix.size(); i ++){
            for( int j = 1 ; j < matrix[0].size(); j ++){
                if ( matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;

                }
                
            }
        }


        if (isrow0){

            for( int j=0; j < matrix[0].size(); j++){
                matrix[0][j]=0;
            }
        }

        if (iscol0){

            for( int i=0; i < matrix.size(); i++){
                matrix[i][0]=0;
            }
        }

      
    }
};