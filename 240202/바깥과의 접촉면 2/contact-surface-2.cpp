#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,t;
vector<vector<int>> vec;
vector<queue<pair<int,int>>> coordi;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void init(){
    cin >> n >> m;
    t = 0;
    vec.clear();
    coordi.clear();
    vec.resize(n,vector<int>(m,0));

    queue<pair<int,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> vec[i][j];
            if(vec[i][j]!=0)
                q.push({i,j});
        }
    }
    coordi.push_back(q);
}

vector<vector<bool>> visit;
void bfs(int y, int x){
    queue<pair<int,int>> c;
    queue<pair<int,int>> q;
    q.push({y,x});

    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second; q.pop();
        if(visit[curY][curX])
            continue;
        visit[curY][curX] = true;

        int cnt = 0;
        for(int i=0; i<4; i++){
            int _y = curY + dy[i];
            int _x = curX + dx[i];

            if(_y<0 || _x<0 || _y>=n || _x>=m)
                continue;
            if(!visit[_y][_x] && vec[_y][_x]==0)
                cnt++;
            else if(!visit[_y][_x] && vec[_y][_x]!=0){
                q.push({_y,_x});
            }
        }
        vec[curY][curX]-=cnt;
        if(vec[curY][curX]<0)
            vec[curY][curX] = 0;
        else if(vec[curY][curX]>0){
            c.push({curY,curX});
        }


        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout << vec[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        
    }
    coordi.push_back(c);
}

bool nope = false;
bool loop(){
    visit.clear();
    visit.resize(n,vector<bool>(n,false));

    int cnt = 0;
    if(coordi[t].empty()){
        nope = true;
        return false;
    }

    while(!coordi[t].empty()){
        int y = coordi[t].front().first;
        int x = coordi[t].front().second; coordi[t].pop();
        if(!visit[y][x] && vec[y][x]!=0){
            if(cnt==1){
                return false;
            }
            bfs(y,x);
            cnt++;
        }
    }
    return true;
}


void solve(){
    while(loop()){
        t++;
    }
    if(nope)
        cout << 0 << "\n";
    else 
        cout << t << "\n";
}

int main() {
    init();
    solve();
    return 0;
}