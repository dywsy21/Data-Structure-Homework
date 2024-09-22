#include <bits/stdc++.h>
using namespace std;
#define int long long

#define DEBUG

bool is_equal(unordered_set<unordered_set<int>> a, unordered_set<unordered_set<int>> b) {
    if (a.size() != b.size()) return false;
    for (auto& s : a) {
        if (b.find(s) == b.end()) return false;
    }
    return true;
}


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int m; cin >> m;
#ifdef DEBUG
    cout << "Input string: " << s << endl;
#endif
    vector<unordered_map<char, vector<int>>> pos(26);
    vector<unordered_map<int, int>> lower_bound(26);

    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        pos[c - 'a'][c].push_back(i);
    }

    for (int i = 0; i < 26; ++i) {
        int index = 0;
        for (int j = 0; j <= s.size(); ++j) {
            while (index < pos[i]['a' + i].size() && pos[i]['a' + i][index] < j) {
                ++index;
            }
            lower_bound[i][j] = index;
        }
#ifdef DEBUG
        cout << "Lower bound for character " << (char)('a' + i) << ": " << endl;
        for (int j = 0; j <= s.size(); ++j) {
            cout << lower_bound[i][j] << " ";
        }
        cout << endl;
#endif
    }

    while (m--) {
        int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
        --l1; --r1; --l2; --r2;
#ifdef DEBUG
        cout << "Query: (" << l1 << ", " << r1 << ") and (" << l2 << ", " << r2 << ")" << endl;
#endif
        bool isomorphic = true;
        unordered_set<char> chars1, chars2;

        for (int i = 0; i < 26; ++i) {
            if (lower_bound[i][r1 + 1] > lower_bound[i][l1]) {
                chars1.insert('a' + i);
            }
            if (lower_bound[i][r2 + 1] > lower_bound[i][l2]) {
                chars2.insert('a' + i);
            }
        }

#ifdef DEBUG
        cout << "Chars1: ";
        for (char c : chars1) cout << c << " ";
        cout << "\nChars2: ";
        for (char c : chars2) cout << c << " ";
        cout << endl;
#endif

        if (chars1 != chars2) {
#ifdef DEBUG
            cout << "Character sets differ." << endl;
#endif
            isomorphic = false;
        } else {
            // write a hash for unordered_set<unordered_set<int>>
            unordered_set<unordered_set<int>, > all_positions1, all_positions2;
            for (char c : chars1) {
                unordered_set<int> positions1, positions2;
                for (int j = lower_bound[c - 'a'][l1]; j < lower_bound[c - 'a'][r1 + 1]; ++j) {
                    positions1.insert(pos[c - 'a'][c][j] - l1);
                }
                for (int j = lower_bound[c - 'a'][l2]; j < lower_bound[c - 'a'][r2 + 1]; ++j) {
                    positions2.insert(pos[c - 'a'][c][j] - l2);
                }
#ifdef DEBUG
                cout << "Positions for character " << c << " in first substring: ";
                for (int pos : positions1) cout << pos << " ";
                cout << "\nPositions for character " << c << " in second substring: ";
                for (int pos : positions2) cout << pos << " ";
                cout << endl;
#endif
                all_positions1.insert(positions1);
                all_positions2.insert(positions2);
            }
            if (!is_equal(all_positions1, all_positions2)) {
#ifdef DEBUG
                cout << "Position sets differ." << endl;
#endif
                isomorphic = false;
            }
        }
        cout << (isomorphic ? "Yes" : "No") << endl;
    }

    return 0;
}
