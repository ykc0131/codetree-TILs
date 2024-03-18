#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C,N;
vector<int> cVec;
vector<pair<int,int>> nVec;
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

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

void solve(){
    sort(cVec.begin(), cVec.end());
    sort(nVec.begin(), nVec.end(), cmp);

    int i=0, nIdx=0, result=0;
    while(i<C){
        int c = cVec[i];
        if(nIdx>=N)
            break;

        if(nVec[nIdx].first <= c && nVec[nIdx].second >= c){
            nIdx++;
            i++;
            result++;
        }
        else if(nVec[nIdx].first > c)
            i++;
        else
            nIdx++;
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