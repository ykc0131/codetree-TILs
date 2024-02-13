#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100001

using namespace std;

int n;
vector<vector<int>> grid;
//vector<vector<int>> dist;

void init(){
    cin >> n;
    
    grid.clear();
    //dist.clear();
    grid.resize(n+1,vector<int>(n+1,0));
    //dist.resize(n+1,vector<int>(n+1,INF));
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            cin >> grid[i][j];
            // if(grid[i][j])
            //     dist[i][j] = 1;
        }
    }
}

void solve(){
    for(int k=1; k<n+1; k++){
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if(i==j)
                    grid[i][i] = 1;
                if(grid[i][k] && grid[k][j])
                    grid[i][j] = 1;
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    init();
    solve();
    return 0;
}