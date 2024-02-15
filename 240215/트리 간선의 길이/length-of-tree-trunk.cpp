#include <iostream>
#include <vector>
#define INF 10000000

using namespace std;

int n;
vector<vector<pair<int,int>>> tree;

void init(){
    cin >> n;
    tree.clear();
    tree.resize(n+1);

    for(int i=0; i<n; i++){
        int u,v,cost;
        cin >> u >> v >> cost;

        tree[u].push_back({v,cost});
        tree[v].push_back({u,cost});
    }
}

vector<int> visit;
vector<int> dist;
void dfs(int n, int sum){
    if(visit[n])
        return;
    visit[n] = true;

    for(int i=0; i<tree[n].size(); i++){
        int next = tree[n][i].first;

        if(!visit[next]){
            int d = tree[n][i].second;
            dist[next] = sum + d;
            dfs(next, sum + d);
        }
    }
}

pair<int,int> findLongestVertex(int x){
    visit.clear();
    dist.clear();
    visit.resize(n+1,false);
    dist.resize(n+1,INF);
    dist[x] = 0;
    dfs(x,0);

    int maxV = 0, maxD = 0;
    for(int i=1; i<n+1; i++){
        if(maxD < dist[i]){
            maxD = dist[i];
            maxV = i;
        }
    }
    return {maxV, maxD};
}

void solve(){
    pair<int,int> longest = findLongestVertex(1);

    pair<int,int> diameter = findLongestVertex(longest.first);

    cout << diameter.second << endl;
}

int main() {
    init();
    solve();
    return 0;
}