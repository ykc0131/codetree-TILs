#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 18

using namespace std;

int N,Q;
vector<vector<int>> tree;
vector<pair<int,int>> pairs;
vector<int> depth;
vector<vector<int>> parent;

void init(){
    cin >> N;
    tree.clear();
    pairs.clear();
    depth.clear();
    tree.resize(N+1);
    depth.resize(N+1,-1);
    parent.resize(N+1,vector<int>(MAXN,-1));

    for(int i=0; i<N-1; i++){
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    cin >> Q;
    for(int i=0; i<Q; i++){
        int u,v;
        cin >> u >> v;
        pairs.push_back({u,v});
    }
}

vector<bool> visited;
void dfs(int n){
    if(visited[n])
        return;
    visited[n] = true;

    for(int i=0; i<tree[n].size(); i++){
        int next = tree[n][i];

        if(!visited[next]){
            parent[next][0] = n;
            depth[next] = depth[n] + 1;
            dfs(next);
        }
    }
}

int root = 1;
void findDepth(){
    visited.clear();
    visited.resize(N+1,false);
    depth[root] = 0;
    dfs(root);
}

void findParent(){
    for(int j=0; j<MAXN-1 ;j++){
        for(int i=1; i<N+1; i++){
            if(parent[i][j]!=-1){
                parent[i][j+1] = parent[parent[i][j]][j];
            }
        }
    }
}

int LCA(int u, int v){
    //u와 v 높이 맞추기
    if(depth[u]<depth[v])
        swap(u,v);
    if(depth[u]>depth[v]){
        int diff = depth[u] - depth[v];

        for(int i=0; diff!=0; i++){
            if(diff%2){
                u = parent[u][i];
            }
            diff/=2;
        }
    }

    if(u!=v){
        for(int i=MAXN-1; i>=0 ; i--){
            if(parent[u][i]!=-1 && parent[u][i]!=parent[v][i]){
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        u = parent[u][0];
    }
    return u;
}

void solve(){
    findDepth(); //정점별 높이 구하기
    findParent(); //Sparse Table

    vector<int> ans;
    for(auto p : pairs){
        ans.push_back(LCA(p.first, p.second));
    }

    for(int i=0; i<Q; i++){
        cout << ans[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solve();
    return 0;
}