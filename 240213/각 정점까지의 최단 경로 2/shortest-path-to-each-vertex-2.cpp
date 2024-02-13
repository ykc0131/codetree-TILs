#include <iostream>
#include <vector>
#include <algorithm>

#define INF 100000001

using namespace std;

int n, m;
vector<vector<pair<int,int>>> graph;
vector<vector<int>> dist;

void init(){
    cin >> n >> m;

    graph.clear();
    dist.clear();
    graph.resize(n+1);
    dist.resize(n+1,vector<int>(n+1,INF));
    for(int i=0; i<m; i++){
        int u,v,cost;
        cin >> u >> v >> cost;
        graph[u].push_back({v,cost});
        dist[u][v] = min(dist[u][v], cost);
    }
}

void solve(){
    for(int k=1; k<n+1; k++){
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if(i==j){
                    dist[i][i] = 0;
                    continue;
                }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    init();
    solve();
    return 0;
}