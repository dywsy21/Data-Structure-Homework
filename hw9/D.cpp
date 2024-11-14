#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    int x[n]; for(int i = 0; i < n; i++) cin >> x[i];

    bool found = false;
    int cur_sum = 0, cur_ans = 1000000, cur_strong_sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq; 
    
    for(int i = 0; i < n; i++){
        cur_sum += x[i];
        if(pq.size() == cur_ans and pq.top() < x[i]) {
            cur_strong_sum -= pq.top(); cur_strong_sum += x[i];
            pq.pop(); pq.push(x[i]);

            while(cur_strong_sum - 2 * pq.top() >= k + cur_sum - cur_strong_sum and !pq.empty()) {
                cur_strong_sum -= pq.top(); pq.pop();
            }
            cur_ans = pq.size();
        }

        if(pq.size() < cur_ans){
            pq.push(x[i]); cur_strong_sum += x[i];
            if(cur_strong_sum >= k + cur_sum - cur_strong_sum){
                found = true;
                cur_ans = pq.size();
            } 
        } 
    } 

    if(found) cout << cur_ans;
    else cout << -1;
    // system("pause");
    return 0;
}


// or:

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    int x[n]; for(int i = 0; i < n; i++) cin >> x[i];

    bool found = false;
    int cur_sum = 0, cur_ans = 1000000, cur_strong_sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq; 
    
    for(int i = 0; i < n; i++){
        cur_sum += x[i];
        if(pq.size() == cur_ans and pq.top() < x[i]) {
            cur_strong_sum -= pq.top(); cur_strong_sum += x[i];
            pq.pop(); pq.push(x[i]);

            vector<int> temp; int temp_sum = cur_strong_sum;
            while(temp_sum >= k + cur_sum - temp_sum and !pq.empty()) {
                temp.push_back(pq.top()); temp_sum -= pq.top();
                pq.pop();
            }
            if(not temp.empty()) {
                cur_strong_sum = temp_sum + temp.back();
                pq.push(temp.back()); temp.pop_back();
                cur_ans = pq.size();
            }
        }

        if(pq.size() < cur_ans){
            pq.push(x[i]);
            cur_strong_sum += x[i];
            if(cur_strong_sum >= k + cur_sum - cur_strong_sum){
                found = true;
                cur_ans = pq.size();
            } 
        } 
    } 

    if(found) cout << cur_ans;
    else cout << -1;
    // system("pause");
    return 0;
}

// or:

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    int x[n]; for(int i = 0; i < n; i++) cin >> x[i];

    bool found = false;
    int cur_sum = 0, cur_ans = 1000000, cur_strong_sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq; 
    
    for(int i = 0; i < n; i++){
        cur_sum += x[i];
        if(pq.size() == cur_ans and pq.top() < x[i]) {
            cur_strong_sum -= pq.top(); cur_strong_sum += x[i];
            pq.pop(); pq.push(x[i]);

            int temp_back = -1, temp_sum = cur_strong_sum;
            while(temp_sum >= k + cur_sum - temp_sum and !pq.empty()) {
                temp_back = pq.top(); temp_sum -= pq.top();
                pq.pop();
            }
            if(temp_back != -1) { // found smaller cur_ans
                cur_strong_sum = temp_sum + temp_back;
                pq.push(temp_back);
                cur_ans = pq.size();
            }
        }

        if(pq.size() < cur_ans){
            pq.push(x[i]);
            cur_strong_sum += x[i];
            if(cur_strong_sum >= k + cur_sum - cur_strong_sum){
                found = true;
                cur_ans = pq.size();
            } 
        } 
    } 

    if(found) cout << cur_ans;
    else cout << -1;
    // system("pause");
    return 0;
}
