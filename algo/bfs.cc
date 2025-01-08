#include <bits/stdc++.h>

using namespace std;

enum node_color_t : int8_t {
        WHITE = 0,
        GRAY,
        BLACK
};

ostream& operator<<(ostream& os, node_color_t c) {
        switch(c) {
                case node_color_t::WHITE:
                        os << "WHITE";
                        break;
                case node_color_t::GRAY:
                        os << "GRAY";
                        break;
                case node_color_t::BLACK:
                        os << "BLACK";
                        break;
        }
        return os;
}

void BFS(int node, vector<vector<int>>& adj, vector<node_color_t>& visited) {
        deque<int> queue;
        queue.push_back(node);

        while (!queue.empty()) {
                const int curr = queue.front();
                queue.pop_front();
                //cout << "DEQUEUE " << curr << endl; 
                cout << "{ " ;
                cout << curr << " ";

                for (int neighbor : adj[curr]) {
                        if (visited[neighbor] == WHITE) {
                                queue.push_back(neighbor);
                                visited[neighbor] = node_color_t::GRAY;  // should be marked 'gray' to mean 'discovered'
                                //cout << "ENQUEUE " << neighbor << endl;
                                //break;
                                //BFS(neighbor, adj, visited);
                        } else {
                                cout << ", already visited: " << neighbor << ", " << visited[neighbor];
                        }
                }
                // curr should be marked 'black' to mean 'behind the frontier'
                visited[curr] = node_color_t::BLACK;
                cout << " }" ;
        }
}

int main() {
        int numNodes = 4;
        vector<vector<int>> adj(numNodes);
        vector<node_color_t> visited(numNodes, WHITE);
        // Add edges to the graph
        auto addEdge = [&](int v, int w) { adj[v].push_back(w); };

        addEdge(0, 1);
        addEdge(0, 2);
        addEdge(1, 2);
        addEdge(2, 0);
        addEdge(2, 3);
        addEdge(3, 1);

        cout << "BFS traversal: ";
        for (int i = 2; i < numNodes; i++) {
                if (visited[i] == WHITE) {
                        BFS(i, adj, visited);
                }
        }
        cout << endl << "expected is {2 0 3 1 }" << endl;

        return 0;
}
