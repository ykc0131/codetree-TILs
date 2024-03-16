#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int N;
map<int,vector<int>, greater<int>> mm;
void init(){
    cin >> N;

    for(int i=0; i<N; i++){
        int n,m;
        cin >> n >> m;

        mm[m].push_back(n);
    }
}

void solve(){
    priority_queue<int, vector<int>, less<>> pq;
    int result = 0, preNum=mm.begin()->first + 1;

    auto iter = mm.begin();
    for(; iter!=mm.end(); iter++){
        int timer = iter->first;
        vector<int> vec = iter->second;

        int cnt = preNum - timer;
        while(cnt-- && !pq.empty()){
            result += pq.top(); pq.pop();
        }
       
        for(int i=0; i<vec.size(); i++){
            pq.push(vec[i]);
        }

        preNum = timer;
    }


    while(preNum-- && !pq.empty()){
        result += pq.top(); pq.pop();
    }

    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}