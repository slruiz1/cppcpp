#include <bits/stdc++.h>

using namespace std;

void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        stack<int> st;
        st.push(node);

        while (!st.empty()) {
                const int curr = st.top();
                st.pop();
                //cout << "POP " << curr << endl; 
                cout << "{ " ;
                visited[curr] = true;
                cout << curr << " ";

                for (int neighbor : adj[curr]) {
                        if (!visited[neighbor]) {
                                st.push(neighbor);
                                //cout << "PUSH " << neighbor << endl;
                                break;
                                //DFS(neighbor, adj, visited);
                        } else {
                                cout << ", already visited: " << neighbor;
                        }
                }
                cout << " }" ;
        }
}


int main() {

#if 1
        int numNodes = 4;
        vector<vector<int>> adj(numNodes);
        vector<bool> visited(numNodes, false);
        // Add edges to the graph
        auto addEdge = [&](int v, int w) { adj[v].push_back(w); };

        addEdge(0, 1);
        addEdge(0, 2);
        addEdge(1, 2);
        addEdge(2, 0);
        addEdge(2, 3);
        addEdge(3, 1);
#else
        int numNodes, numEdges;
        cout << "Enter the number of nodes: ";
        cin >> numNodes;
        cout << "Enter the number of edges: ";
        cin >> numEdges;

        vector<vector<int>> adj(numNodes);
        vector<bool> visited(numNodes, false);
        cout << "Enter the edges:\n";
        for (int i = 0; i < numEdges; i++) {
                int u, v;
                cin >> u >> v;
                adj[u].push_back(v);
                //adj[v].push_back(u); // For undirected graph
                cout << "> got: " << u << " -> " << v  << endl;
        }
#endif
        cout << "DFS traversal: ";
        for (int i = 2; i < numNodes; i++) {
                //cout << " i: " << i << endl;
                if (!visited[i]) {
                        DFS(i, adj, visited);
                }
        }
        cout << endl;

        return 0;
}
