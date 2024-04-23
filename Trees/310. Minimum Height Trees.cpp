class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
        int m = edges.size();
        vector<int>adjList[n];
        vector<int>degree(n,0);
        // Create adjacency list
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            // cout<<u<<" "<<v<<endl;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        // Store Leaves
        queue<int>leaves;
        for(int i=0;i<n;i++){
            if(degree[i] == 1)
                leaves.push(i);
        }
        int remainingNodes = n;
        while(remainingNodes > 2){
            int size = leaves.size();
            remainingNodes -= leaves.size();
            // cout<<leaves.size()<<endl;
            for(int i=0;i<size;i++){
                // cout<<i<<endl;
                int leaf = leaves.front();
                leaves.pop();
                // cout<<leaf<<endl;
                for(int neighbor:adjList[leaf]){
                    // cout<<neighbor<<" "<<degree[neighbor]<<endl;
                    degree[neighbor]-=1;
                    // cout<<neighbor<<" "<<degree[neighbor]<<endl;
                    if(degree[neighbor] == 1)
                        leaves.push(neighbor);
                }
            }
        }
        vector<int>result;
        while(!leaves.empty()){
            int node = leaves.front();
            leaves.pop();
            result.push_back(node);
        }

        return result;
        
    }
};