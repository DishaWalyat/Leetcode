class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        for( int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        for( int i=arr.size()-1; i>=0; i--){
            if(mp[arr[i]]== arr[i]) return arr[i];
        }
        return -1;
    }
};