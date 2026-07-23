class Solution {
public:
    void dfs(int i, vector<int>&visited, vector<int> adjLS[]){
        visited[i]=1;
        for( auto it : adjLS[i]){
            if(!visited[it]){
                dfs(it,visited,adjLS);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //adjlist made 
        int V= isConnected.size();
        vector<int> adjLS[V];
          for(int i =0; i<isConnected.size(); i++){
            for( int j=0; j<isConnected[0].size(); j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLS[i].push_back(j);
                    adjLS[j].push_back(i);
                }
            }
          }
          int count=0;
          vector<int> visited(V,0);

          for(int i=0; i<V; i++){
            if(!visited[i]){
                count++;
                dfs(i, visited, adjLS);
            }
          }
        return count;
    }
};
