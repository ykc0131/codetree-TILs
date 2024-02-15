#include <iostream>
#include <vector>
#include <queue>
#define INF 100001

using namespace std;

int n;
vector<vector<int>> tree;
vector<int> edgeCnt;
queue<int> q;

void init(){
    cin >> n;
    tree.clear();
    edgeCnt.clear();
    tree.resize(n+1);
    edgeCnt.resize(n+1,0);

    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int maxN = 0;
    for(int i=1; i<n+1; i++){
        edgeCnt[i] = tree[i].size();
        if(maxN < edgeCnt[i]){
            q = queue<int>();
            maxN = edgeCnt[i];
            q.push(i);
        }
    }
}

int bfs(int x){
    vector<int> visit(n+1,false);
    queue<pair<int,int>> bq;
    bq.push({x,0});
    int cnt = 0;

    while(!bq.empty()){
        int cur = bq.front().first;
        int curCost = bq.front().second; bq.pop();
        if(visit[cur])
            continue;
        visit[cur] = 0;

        for(int i=0; i<tree[cur].size(); i++){
            int next = tree[cur][i];

            if(!visit[next]){
                bq.push({next, curCost + 1});
            }
        }
        cnt++;
        if(cnt==n)
            return curCost;
    }
}

void solve(){
    int result = INF;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        int longest = bfs(cur);
        result = min(result, longest);
    }

    cout << result << endl;
}

int main() {
    init();
    solve();
    return 0;
}