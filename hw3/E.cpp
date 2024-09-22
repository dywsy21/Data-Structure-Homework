#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int m; cin >> m;
    vector<unordered_map<char, vector<int>>> pos(26);
    vector<unordered_map<int, int>> lower_bound(26);

    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        pos[c - 'a'][c].push_back(i);
    }

    for (int i = 0; i < 26; ++i) {
        int index = 0;
        for (int j = 0; j <= 1e5; ++j) {
            while (index < pos[i]['a' + i].size() && pos[i]['a' + i][index] < j) {
                ++index;
            }
            lower_bound[i][j] = index;
        }
    }

    while (m--) {
        int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
        unordered_map<char, char> map1, map2;
        bool isomorphic = true;

        for (int i = 0; i < 26; ++i) {
            int start1 = lower_bound[i][l1];
            int start2 = lower_bound[i][l2];
            int end1 = lower_bound[i][r1 + 1];
            int end2 = lower_bound[i][r2 + 1];

            if (end1 - start1 != end2 - start2) {
                isomorphic = false;
                break;
            }

            for (int j = start1; j < end1; ++j) {
                char c1 = s[pos[i]['a' + i][j]];
                char c2 = s[pos[i]['a' + i][j + start2 - start1]];

                if (map1.count(c1) && map1[c1] != c2) {
                    isomorphic = false;
                    break;
                }
                if (map2.count(c2) && map2[c2] != c1) {
                    isomorphic = false;
                    break;
                }

                map1[c1] = c2;
                map2[c2] = c1;
            }

            if (!isomorphic) break;
        }

        cout << (isomorphic ? "Yes" : "No") << endl;



    }


    system("pause");
    return 0;
}
