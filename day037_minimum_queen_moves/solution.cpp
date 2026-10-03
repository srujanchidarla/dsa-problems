#include <bits/stdc++.h>
using namespace std;

// ─────────────────────────────────────────────────────────────────────────
// BRUTE FORCE — BFS on the 8x8 board | O(64 * 8 * 8) time | O(64) space
// General approach — would still work if obstacles were added
// ─────────────────────────────────────────────────────────────────────────
int minQueenMovesBruteForce(vector<int>& source, vector<int>& target) {
    int dist[9][9];
    memset(dist, -1, sizeof(dist));

    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    queue<pair<int, int>> q;
    q.push({source[0], source[1]});
    dist[source[0]][source[1]] = 0;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (r == target[0] && c == target[1]) return dist[r][c];

        for (int d = 0; d < 8; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            while (nr >= 1 && nr <= 8 && nc >= 1 && nc <= 8) {
                if (dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
                nr += dr[d];
                nc += dc[d];
            }
        }
    }

    return -1;
}

// ─────────────────────────────────────────────────────────────────────────
// OPTIMIZED — O(1) time | O(1) space
// 0 if same square, 1 if same row/col/diagonal, else 2
// ─────────────────────────────────────────────────────────────────────────
int minQueenMovesOptimized(vector<int>& source, vector<int>& target) {
    int dr = abs(source[0] - target[0]);
    int dc = abs(source[1] - target[1]);

    if (dr == 0 && dc == 0) return 0;
    if (dr == 0 || dc == 0 || dr == dc) return 1;
    return 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> source(2), target(2);
    if (cin >> source[0] >> source[1] >> target[0] >> target[1]) {
        cout << minQueenMovesOptimized(source, target) << "\n";
    }

    return 0;
}
