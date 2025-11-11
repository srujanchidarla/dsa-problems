#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// O(M) Time, O(1) Space - Greedy Single Pass
void solve_alternate_seating() {
    int N, M;
    if (!(cin >> N >> M)) return; // Read N and M

    vector<int> seats(M);
    for (int i = 0; i < M; ++i) {
        if (!(cin >> seats[i])) return; // Read seat configuration
    }

    int people_seated = 0;

    for (int i = 0; i < M; ++i) {
        if (people_seated >= N) break;

        // Check 1: Seat must be vacant
        if (seats[i] == 0) {
            
            // Check 2: Left neighbor must be empty (or boundary)
            bool left_empty = (i == 0) || (seats[i-1] == 0);
            
            // Check 3: Right neighbor must be empty (or boundary)
            bool right_empty = (i == M - 1) || (seats[i+1] == 0);
            
            if (left_empty && right_empty) {
                // Greedily take the seat (set to occupied)
                seats[i] = 1; 
                people_seated++;
            }
        }
    }

    if (people_seated >= N) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    solve_alternate_seating();
    return 0;
}