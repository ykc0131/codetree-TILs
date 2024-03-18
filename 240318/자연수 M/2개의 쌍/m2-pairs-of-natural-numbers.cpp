#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<pair<int,int>> vec;
void init(){
    cin >> N;

    for(int i=0; i<N; i++){
        int x,y;
        cin >> x >> y;
        vec.push_back({y,x});
    }
}

void solve(){
    sort(vec.begin(), vec.end());

    int start=0, end=N-1, ans=0;
    while(start<=end){
        pair<int,int> startP = vec[start];
        pair<int,int> endP = vec[end];

        ans = max(ans, startP.first+endP.first);

        if(startP.second < endP.second){
            vec[end] = make_pair(endP.first, endP.second - startP.second);
            start++;
        }
        else if(startP.second > endP.second){
            vec[start] = make_pair(startP.first, startP.second - endP.second);
            end--;
        }
        else{
            start++;
            end--;
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}