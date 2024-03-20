#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int,int>

using namespace std;

int C,N;
vector<int> cVec;
vector<pii> nVec;
void init(){
    cin >> C >> N;

    for(int i=0; i<C; i++){
        int n;
        cin >> n;
        cVec.push_back(n);
    }

    for(int i=0; i<N; i++){
        int a,b;
        cin >> a >> b;
        nVec.push_back({a,b});
    }
}

bool cmp(pii a, pii b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

priority_queue<pii,vector<pii>,greater<pii>> pq;
void solve(){
    sort(cVec.begin(), cVec.end());
    sort(nVec.begin(), nVec.end());

    int i=0, nIdx=0, result=0;
    for(int i=0; i<C; i++){
        while(nIdx<N && nVec[nIdx].first <= cVec[i]){
            pq.push({nVec[nIdx].second, nVec[nIdx].first});
            nIdx++;
        }
        while(!pq.empty() && pq.top().first < cVec[i]){
            pq.pop();
        }
        if(!pq.empty()){
            pq.pop();
            result++;
        }
    }

    cout << result;
}

int main() {  
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}