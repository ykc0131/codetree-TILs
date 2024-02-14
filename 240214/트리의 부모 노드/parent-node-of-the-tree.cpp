#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> parent;

void init(){
    cin >> n;
    parent.clear();
    parent.resize(n+1,0);

    for(int i=0; i<n; i++){
        int u,v;
        cin >> u >> v;

        parent[v] = u;
    }
}

void solve(){
    for(int i=2; i<n+1; i++){
        cout << parent[i] << "\n";
    }
}

int main() {
    init();
    solve();
    return 0;
}