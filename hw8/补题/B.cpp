#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    long sum;
    int posa;
    int posb;
    bool operator<(const Node& other) const {
        return sum > other.sum; // Max-heap by default, so we invert the comparison for min-heap behavior
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    priority_queue<Node> pq;
    for (int i = 0; i < n; i++) {
        pq.push({a[0] + b[i], 0, i});
    }

    for (int i = 0; i < n; i++) {
        Node current = pq.top();
        pq.pop();
        cout << current.sum << " ";

        if (current.posa + 1 < n) {
            pq.push({a[current.posa + 1] + b[current.posb], current.posa + 1, current.posb});
        }
    }

    return 0;
}
