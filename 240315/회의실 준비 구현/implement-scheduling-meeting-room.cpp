#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int>> vec;
void init(){
    cin >> n;

    for(int i=0; i<n; i++){
        int s,e;
        cin >> s >> e;

        vec.push_back({s,e});
    }
}

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second)
        return a.first < b.first;
    return a.second < b.second;
}

void solve(){
    int result = 1;
    sort(vec.begin(), vec.end(), cmp);
    
    pair<int,int> pre=vec[0];
    for(int i=1; i<n; i++){
        pair<int,int> next = vec[i];
        if(pre.second <= next.first){
            pre = next;
            result+=1;
        }
    }
    cout << result << "\n";
}

int main() {
    init();
    solve();
    return 0;
}


// !겹치지 않게 고르기! 
// 1. 회의 시작 시간을 기준으로 오름차순 정렬
// 회의 시작이 빨라도 회의 구간길이가 긴 경우. 

// 2. 회의 구간의 길이 (끝 시간 - 시작 시간) 을 기준으로 오름차순 정렬
// 구간 길이가 짧더라도 [1-4] [3-5] [4-8] 인 경우에 [3-5]만 선택되는 불상사..

// 3. 회의 끝 시간을 기준으로 오름차순 정렬
// 빨리 비워지는 회의를 기준으로 정렬해서 사용할 수 있는 시간 늘리기