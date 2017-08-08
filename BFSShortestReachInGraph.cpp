#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include<queue>
#include <iostream>
#include <algorithm>
#define pb push_back 
using namespace std;

class Graph {
    public:
        int nodes;
       
        vector <vector<int>> vs;
        Graph(int n) {
            nodes = n;
            vector<vector<int>> vin(n);
            vs = vin;
           
        }
    
        void add_edge(int u, int v) {
            vs[u].pb(v);
            vs[v].pb(u);
        }
    
        vector<int> shortest_reach(int start) {
            
            vector<int> ans = {numeric_limits<int>::max(), 0};
            vector<int> distances(nodes,-1);
            
            vector<int> visited(nodes);
            queue<int> unvisited;
            unvisited.push(start);
            int current  = start;
            distances[start] = 0;
            int cdis = 0;
            visited[current] = 1;
            while(unvisited.size() > 0){
                
                current = unvisited.front();
                unvisited.pop();
                visited[current] = 1;
                cdis = distances[current];
                for(int i = 0; i < vs[current].size(); i++){
                    int neighbor = vs[current][i];
                    if(neighbor != start){
                    if(distances[neighbor] > cdis + 6 || distances[neighbor] == -1){
                        distances[neighbor] = cdis + 6 ;
                        
                    }
                    if(visited[neighbor] == 0){
                        unvisited.push(neighbor);
                        visited[neighbor] =  1;
                        
                    }
                    }
                }
                
                
            }
            
            return distances;
            
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
