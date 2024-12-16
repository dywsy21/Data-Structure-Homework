#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int N = 40007;
vector<pair<int, int>> children[N]; // dest, length
bool found = false; int dest;

int get_path_len(int begin, int banned) { // if can't reach, return 0
    for(auto [child, len]: children[begin]) if(child != banned) {
        int next_len = get_path_len(child, begin);
        if(found) return len + next_len;
        if(child == dest){
            found = true;
            return len;
        }
    }
    return 0;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i {}; i < n - 1; i++) {
        int x, y, c; cin >> x >> y >> c;
        children[x].push_back({y, c});
        children[y].push_back({x, c});
    }

    while(m--) {
        int a; cin >> a >> dest; found = false;
        cout << get_path_len(a, -1) << '\n';
    }

    // system("pause");
    return 0;
}