#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int N = 1e5 + 7, NO_CHOICE = -1, CHOICE_A = 0, CHOICE_B = 1;
int a[N], b[N];

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, c; cin >> n >> c;
    for(int i {}; i < n; i++) cin >> a[i];
    for(int i {}; i < n; i++) cin >> b[i];

    int ans = 0, prev_choice = -1, cur_a_penalty = c, cur_b_penalty = c;
    bool equal_flag = false;
    for(int i {}; i < n; i++) {
        cout << "Iteration " << i << ": a[i]=" << a[i] << ", b[i]=" << b[i] << endl;
        if(not equal_flag) {
            int gain_a = a[i] - (prev_choice == NO_CHOICE or prev_choice == CHOICE_B ? c : cur_b_penalty);
            int gain_b = b[i] - (prev_choice == NO_CHOICE or prev_choice == CHOICE_A ? c : cur_a_penalty);
            cout << "gain_a=" << gain_a << ", gain_b=" << gain_b << endl;
            if(gain_a > gain_b) {
                ans += gain_a;
                cur_b_penalty *= 2;
                cur_a_penalty = c;
                prev_choice = CHOICE_A;
                cout << "Choosing A: ans=" << ans << ", cur_b_penalty=" << cur_b_penalty << endl;
            }
            if(gain_a < gain_b) {
                ans += gain_b;
                cur_a_penalty *= 2;
                cur_b_penalty = c;
                prev_choice = CHOICE_B;
                cout << "Choosing B: ans=" << ans << ", cur_a_penalty=" << cur_a_penalty << endl;
            }
            if(gain_a == gain_b) {
                equal_flag = true;
                ans += gain_a;
                cout << "Equal gain: ans=" << ans << endl;
            } 
        }

        else if(equal_flag) {
            equal_flag = false;
            int gain_a = a[i] - c;
            int gain_b = b[i] - c;
            cout << "Equal flag active: gain_a=" << gain_a << ", gain_b=" << gain_b << endl;
            if(gain_a > gain_b) {
                ans += gain_a;
                prev_choice = CHOICE_A;
                cout << "Choosing A: ans=" << ans << endl;
            }
            if(gain_a < gain_b) {
                ans += gain_b;
                prev_choice = CHOICE_B;
                cout << "Choosing B: ans=" << ans << endl;
            }
            if(gain_a == gain_b) {
                equal_flag = true;
                ans += gain_a;
                cout << "Equal gain: ans=" << ans << endl;
            }
            cur_a_penalty = cur_b_penalty = 2 * c;
        }
    }
    cout << "Final answer: " << ans << endl;

    // system("pause");
    return 0;
}