#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to generate random graph with V vertices and E edges
void generateRandomGraph(int V, int E, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        srand(time(0)); // Seed the random number generator with current time

        file << V << " " << E << endl; // Write number of vertices and edges to file

        // Generate random edges
        for (int i = 0; i < E; i++) {
            int u = rand() % V + 1; // Randomly generate source vertex
            int v = rand() % V + 1; // Randomly generate destination vertex
            file << u << " " << v << endl; // Write edge to file
        }

        file.close();
        cout << " " << filename << " " << endl;
    } else {
        cout << "Failed to create file: " << filename << endl;
    }
}

// Function to perform Breadth-First Search (BFS)
void bfs(vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "BFS traversal: ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : graph[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
    cout << endl;
}

// Function to perform Depth-First Search (DFS)
void dfs(vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    stack<int> st;
    st.push(start);

    cout << "DFS traversal: ";
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!visited[u]) {
            cout << u << " ";
            visited[u] = true;

            for (int v : graph[u]) {
                if (!visited[v]) {
                    st.push(v);
                }
            }
        }
    }
    cout << endl;
}

int main() {
    int V = 10; // Number of vertices
    int E = 15; // Number of edges
    string filename = "input.txt"; // Name of the input file

    generateRandomGraph(V, E, filename); // Call the function to generate random graph

    // Read input values from file
    ifstream file(filename);
    if (file.is_open()) {
        int V, E;
        file >> V >> E;

        vector<vector<int>> graph(V + 1); // 1-indexed graph representation
        int u, v;
        for (int i = 0; i < E; i++) {
            file >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u); // Assuming undirected graph
        }

        file.close();

        int start;
        cout << "Enter starting vertex for traversal: ";
        cin >> start;

        bfs(graph, start); // Perform BFS
        dfs(graph, start); //
    }
}
