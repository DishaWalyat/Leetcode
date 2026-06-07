class Solution {
public:
    void dfs(int node, vector <int> adjLS[], vector<int>& visited){ 
        visited[node]=1;
        for( auto it : adjLS[node]){
            if(!visited[it]){
                dfs(it, adjLS,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // so we are given a adj matrix --> lets convert it into a list first
        int V = isConnected.size();
        vector<int> adjLS[V];

        for(int i =0; i <V; i++){
            for (int j =0; j <V; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLS[i].push_back(j);
                    adjLS[j].push_back(i);
                }

            }
        }

        // now we can traverse the nodes
        vector<int> visited(V, 0);
        int count=0; 

        for( int i=0; i <V; i++){
            if(!visited[i]){
                count++;
                dfs(i, adjLS, visited);
            }
        }

        return count;

        
        
    }
};