//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    
    vector<int> toposort(int V,vector<int> adj[]){
        
        
        vector<int>topo;
        
        queue<int>q;
        
        vector<int>indegree(V,0);
        
        
        for(int i=0;i<V;i++){
            for(auto pr:adj[i]){
                indegree[pr]++;
            }
        }
        
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        
        
        while(!q.empty()){
            int node=q.front();
            
            q.pop();
            
            topo.push_back(node);
            
            for(auto pr:adj[node]){
                indegree[pr]--;
                
                if(indegree[pr]==0) q.push(pr);
            }
            
            
            
        }
        return topo;
        
        
        
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<int>topo=toposort(V,adj);
        
        if(topo.size()==V) return false;
        
        return true;
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends