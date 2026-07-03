class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();//graphs bfs
        vector<int>vis(n,0);
        queue<int>q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int adjNode:rooms[node]){
                if(!vis[adjNode]){
                    vis[adjNode]=1;
                    q.push({adjNode});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0)return false;//vo room khula hi nhin kbhi
        }
        return true;
    }
};