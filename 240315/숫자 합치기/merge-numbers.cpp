#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<>> pq;
void init(){
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        pq.push(num);
    }
}

void solve(){
    int result = 0;
    while(pq.size()>1){
        int top1 = pq.top(); pq.pop();
        int top2 = pq.top(); pq.pop();

        result += (top1+top2);
        pq.push(top1+top2);
    }
    cout << result << "\n";
}

int main() {
    init();
    solve();
    return 0;
}