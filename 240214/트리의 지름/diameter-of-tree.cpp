#include <iostream>
#include <vector>
#include <algorithm>

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
            dfs(next, sum + tree[N][i].second);
        }
    }
    result = max(result, sum);
}

void solve(){
    for(int i=1; i<n+1; i++){
        visit.clear();
        visit.resize(n+1,false);
        dfs(i,0);
    }
    cout << result << "\n";
}

int main() {
    init();
    solve();
    return 0;
}

//트리의 지름을 가장 쉽게 구하는 방법
// 1~N까지 dfs 돌리기