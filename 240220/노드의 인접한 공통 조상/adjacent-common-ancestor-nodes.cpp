#include <iostream>
#include <vector>
#define MAX 15

using namespace std;

int N,U,V,root;
vector<vector<int>> graph;
vector<vector<int>> parent;
vector<int> depth;

void init(){
   cin >> N;
   graph.clear();
   parent.clear();
   depth.clear();
   graph.resize(N+1);
   parent.resize(N+1,vector<int>(MAX,-1));
   depth.resize(N+1,-1);

   for(int i=0; i<N-1; i++){
       int u,v;
       cin >> u >> v;
       graph[u].push_back(v);
       parent[v][0] = u;
   }

    cin >> U >> V;
}

void dfs(int x){
   for(int i=0; i<graph[x].size(); i++){
       int next = graph[x][i];

       if(depth[next]==-1){
           depth[next] = depth[x]+1;
           dfs(next);
       }
   }
}

void setParent(){
   for(int j=0; j<(int)MAX-1; j++){
       for(int i=1; i<N+1; i++){
           if(parent[i][j]!=-1){
               parent[i][j+1] = parent[parent[i][j]][j]; //공식
           }
       }
   }
}

void findRoot(){
    for(int i=1; i<N+1; i++){
        if(parent[i][0]==-1){
            root = i;
            return;
        }
    }
}

void setDepth(){
    findRoot();
    depth[root] = 0;
    dfs(root);
}

int lca(int u, int v){
   if(depth[u] < depth[v])
       swap(u,v);
   if(depth[u] > depth[v]) { 
       int diff = depth[u]-depth[v];
       for(int j=0; diff!=0; j++){
           if( diff%2 != 0 ){
               u = parent[u][j];
           }
           diff/=2;
       }
   }

   if(u!=v){
       for(int i=(int)MAX-1; i>=0; i--){
           if((parent[u][i] != -1) && (parent[u][i] != parent[v][i])){
               u = parent[u][i];
               v = parent[v][i];
           }
       }
       u = parent[u][0];
   }
   return u;
}

void solve(){
   setDepth();
   setParent();
   int ans = lca(U, V);

   cout << ans << "\n";
}

int main(){
   init();
   solve();
   return 0;
}