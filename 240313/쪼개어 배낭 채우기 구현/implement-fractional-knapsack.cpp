#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n,m;
vector<tuple<int,int,double>> input;
bool cmp(tuple<int,int,double> a, tuple<int,int,double> b){
    if(get<2>(a) == get<2>(b))
        return get<0>(a) < get<0>(b);
    return get<2>(a) > get<2>(b);
}
void init(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        int w,v;
        cin >> w >> v;
        input.push_back({w,v,(double)v/(double)w});
    }

    sort(input.begin(), input.end(), cmp);
}

void solve(){
    double result = 0;
    for(int i=0; i<n; i++){
        if(m-get<0>(input[i])<0){
            double ratio = (double)m/(double)get<0>(input[i]);
            result += get<1>(input[i])*ratio;
            break;
        }
        m-=get<0>(input[i]);
        result += get<1>(input[i]);
    }
    printf("%.3f\n",result);
}

int main() {
    init();
    solve();
    return 0;
}