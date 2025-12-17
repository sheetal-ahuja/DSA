class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        if((source <0 || source>=n) || (destination<0 || destination>=n) ){
            return false;
        }
        if(source == destination){
            return true;
        }    

        vector<int> vis(n,0);
        vis[source]=1;
        queue<int> q;
        q.push(source);

        vector<int> adj[n];
        for(auto &e: edges){
            if(e.size()<2){
                continue;
            }
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){
                if(!vis[it]){
                    if(it == destination){
                        return true;}
                        vis[it] = 1;
                        q.push(it);
                }
            }
        }

        return false;

    }
};
