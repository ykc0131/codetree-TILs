#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.first < b.first;
    }
};

int N;
vector<int> numbers;
vector<int> cardA;
vector<int> cardB;
priority_queue<pair<int,int>, vector<pair<int,int>>, Cmp> pq;
void init(){
    cin >> N;

    numbers.resize(2*N+1,0);
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        numbers[n] = 1;
    }

    for(int i=1; i<2*N+1; i++){
        if(!numbers[i])
            cardA.push_back(i);
        else
            cardB.push_back(i);
    }
}

void solve(){
    for(int i=0; i<N; i++){
        int cur = cardB[i];
        int fromTotal = 2*N - cur,fromB = N-i-1;
        int left = fromTotal - fromB;

        if(left==0)
            continue;
        pq.push({cur, left});
    }

    int cnt = 0, result = 0;
    while(!pq.empty()){
        pair<int,int> cur = pq.top(); pq.pop();

        if(cur.second-cnt>=0){
            result++;
            cnt++;
        }
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