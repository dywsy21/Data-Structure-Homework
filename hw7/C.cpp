#include <bits/stdc++.h>
using namespace std;

struct Player {
    int id, score, strength;
};

// a > b, return descending order
bool comp(const Player &a, const Player &b) {
    if (a.score == b.score) return a.id < b.id;
    return a.score > b.score;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, r, q; cin >> n >> r >> q;

    int totalPlayers = 2 * n;
    vector<Player> players(totalPlayers);

    for (int i = 0; i < totalPlayers; ++i) {
        players[i].id = i + 1;
        cin >> players[i].score;
    }
    for (int i = 0; i < totalPlayers; ++i) cin >> players[i].strength;
    
    sort(players.begin(), players.end(), comp);

    while(r--) {
        vector<Player> nextRoundPlayers(totalPlayers);

        for (int i = 0; i < totalPlayers; i += 2) {
            Player &player1 = players[i];
            Player &player2 = players[i + 1];

            if (player1.strength > player2.strength) {
                player1.score += 1;
                nextRoundPlayers[i / 2] = player1;
                nextRoundPlayers[n + i / 2] = player2;
            } else {
                player2.score += 1;
                nextRoundPlayers[i / 2] = player2;
                nextRoundPlayers[n + i / 2] = player1;
            }
        }

        // Merge winners and losers: two sorted lists
        merge(nextRoundPlayers.begin(), nextRoundPlayers.begin() + n,
              nextRoundPlayers.begin() + n, nextRoundPlayers.end(),
              players.begin(), comp);
    }

    cout << players[q - 1].id << endl;

    return 0;
}
