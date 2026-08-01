class Solution {
public:
    int t[23][23];

    int solve( int i, int j, vector<int>& nums){
        if(i>j) return 0;
        if(i==j) return nums[i];

        if( t[i][j] !=-1) return t[i][j];

        int takes_i= nums[i]+ min(solve(i+2, j , nums), solve(i+1, j-1, nums));
        int takes_j= nums[j]+ min(solve(i, j-2, nums), solve(i+1, j-1, nums));

        return t[i][j]= max(takes_i, takes_j);

    }
    bool predictTheWinner(vector<int>& nums) {
        memset(t,-1, sizeof(t));
        int n= nums.size();

        int total_score= accumulate(begin(nums), end(nums),0);
        
        int player_one= solve(0,n-1, nums);
        int player_two= total_score- player_one;

        return player_one>= player_two;

        
    }
};