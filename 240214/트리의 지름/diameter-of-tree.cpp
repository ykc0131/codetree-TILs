#include <iostream>
#include <vector>
#include <algorithm>

#define INF 100000

using namespace std;

int n;
vector<vector<pair<int,int>>> tree;
vector<int> dist;

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

vector<bool> visit;
int sum = 0, result = 0;
void dfs(int N, int sum){
    if(visit[N])
        return;
    visit[N] = true;

    for(int i=0; i<tree[N].size(); i++){
        int next = tree[N][i].first;

        if(!visit[next]){
            dist[next] = sum + tree[N][i].second;
            dfs(next, dist[next]);
        }
    }
}

pair<int,int> findVertex(int N){
    visit.clear();
    visit.resize(n+1,false);
    dist.clear();
    dist.resize(n+1,INF);

    dist[N] = 0;
    dfs(N,0);

    int maxV=0, maxD=0;
    for(int i=1; i<n+1; i++){
        if(dist[i] > maxD){
            maxD = dist[i];
            maxV = i;
        }
    }
    return {maxV, maxD};
}

void solve(){
    int maxV = findVertex(1).first;

    int result = findVertex(maxV).second;
    cout << result << "\n";
}

int main() {
    init();
    solve();
    return 0;
}

//트리의 지름을 가장 쉽게 구하는 방법
// 1~N까지 dfs 돌리기