class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        // pehle reverse 
        for ( int i =0; i < image.size(); i++){
            reverse(image[i].begin(), image[i].end());
        }
        // abh invert karo 
        for ( int i =0; i< image.size(); i ++){
            for ( int j = 0; j < image[0].size(); j ++){
                if( image[i][j]==0) image[i][j]=1;
                else if ( image[i][j]==1) image[i][j]=0;
            }
        }
        return image;
    }
};