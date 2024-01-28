#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int n,maxTime;
map<int,queue<int>> m;
priority_queue<int> pq;

void init(){
    cin >> n;
    maxTime=0;
    m.clear();
    for(int i=0; i<n; i++){
        int d,p;
        cin >> d >> p;
        m[p].push(d);
        maxTime = maxTime > p ? maxTime : p;
    }
}

void solve(){
    long long sum=0;
    for(auto iter=m.rbegin(); iter!=m.rend();iter++){
        queue<int> q = iter->second;
        if(pq.empty())
            maxTime=iter->first;
        else{
            while(!pq.empty() && maxTime>iter->first){
                sum+=pq.top(); pq.pop();
                maxTime--;
            }
            maxTime=iter->first;
        }

        while(!q.empty()){
            pq.push(q.front()); q.pop();
        }

        while(!pq.empty() && maxTime>=iter->first){
            sum+=pq.top(); pq.pop();
            maxTime--;
        }
    }

    while(!pq.empty() && maxTime>=1){
        sum+=pq.top(); pq.pop();
        maxTime--;
    }
    cout << sum << "\n";
}

int main() {
    init();
    solve();
    return 0;
}