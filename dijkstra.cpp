#include <bits/stdc++.h>
using namespace std;
#define INF 100000


void dijkstra(int graph[][10], int V, int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INF);
    dist[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Shortest distances " << src << "  using Dijkstra's algorithm :"<<endl;
    for (int i = 0; i < V; ++i) {
        cout << i << ": " << dist[i] << " ";
    }
}


void bellmanFord(int graph[][10], int V, int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                if (graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    cout << "Shortest Dis  " << src << "  using Bellman-Ford algorithm:"<<endl;
    for (int i = 0; i < V; ++i) {
        cout << i <<endl<< " : " << dist[i] << endl;
    }
}

int main() {
    int V, E, graph[10][10], src;

    cout << "Enter vartices number  : ";
    cin >> V;

    cout<< "Enter  edges number : ";
    cin>> E;

    cout << "Enter the adjacency  weight :"<<endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }

    }


    cout << "Enter the source vertex: "<<endl;
    cin >> src;

    string name;

    cout<<"ENTER D FOR Dijkstra and ENTER B FOR Bellman-Ford :"<<endl;
    cin>>name;


    if (name == "D") {
        dijkstra(graph, V, src);

    } else if (name=="B")
    {
        bellmanFord(graph, V, src);
    }
    else {
        cout << "you enter worng string "<<endl;
    }

    return 0;
}

