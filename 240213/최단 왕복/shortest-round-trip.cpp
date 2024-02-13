#include <iostream>
#include <vector>
#define INF 100000001

using namespace std;

int n,m;
vector<vector<pair<int,int>>> vec;
vector<vector<int>> dist;

void init(){
    cin >> n >> m;

    dist.clear();
    dist.resize(n+1,vector<int>(n+1,INF));
    
    for(int i=0; i<m; i++){
        int u,v,cost;
        cin >> u >> v >> cost;

        dist[u][v] = cost;
    }

    for(int i=1; i<n+1; i++){
        dist[i][i] = 0;
    }
}

void solve(){
    int result = INF;
    for(int k=1; k<n+1; k++){
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(i==j)
                continue;
            if(dist[j][i]==INF || dist[i][j]==INF)
                continue;
            result = min(result, dist[i][j]+dist[j][i]);
            //왕복이기 때문에 dist[i][j] + dist[j][i]
            // dist[i][j] : i->j
            // dist[j][i] : j->i 
            // 따라서, 왕복이다. 
        }
    }
    cout << result << endl;
}

int main() {
    init();
    solve();
    return 0;
}