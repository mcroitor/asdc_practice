#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;

int N, M;
int grid[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

bool can_move(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M && !visited[r][c];
}

int get_potential(int r, int c) {
    vector<pair<int, int>> q;
    q.push_back({r, c});
    
    // temp visited array to avoid modifying the original visited
    static bool temp_v[MAX_N][MAX_M];
    for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) temp_v[i][j] = visited[i][j];
    
    int sum = 0;
    int head = 0;
    temp_v[r][c] = true;
    
    while(head < q.size()){
        pair<int, int> curr = q[head++];
        sum += grid[curr.first][curr.second];
        
        for(int i=0; i<4; ++i){
            int nr = curr.first + dr[i], nc = curr.second + dc[i];
            if(nr >= 0 && nr < N && nc >= 0 && nc < M && !temp_v[nr][nc]){
                temp_v[nr][nc] = true;
                q.push_back({nr, nc});
            }
        }
    }
    return sum;
}

// Minimax with Alpha-Beta pruning
pair<int, int> minimax(int r1, int c1, int r2, int c2, int s1, int s2, int depth, int alpha, int beta, bool is_first) {
    // Depth limit to respect Time Limit
    if (depth == 0) {
        return {s1 + get_potential(r1, c1)/2, s2 + get_potential(r2, c2)/2};
    }

    bool moved = false;
    pair<int, int> best = {s1, s2};

    if (is_first) {
        int max_eval = -1e9;
        for (int i = 0; i < 4; ++i) {
            int nr = r1 + dr[i], nc = c1 + dc[i];
            if (can_move(nr, nc)) {
                moved = true;
                visited[nr][nc] = true;
                pair<int, int> res = minimax(nr, nc, r2, c2, s1 + grid[nr][nc], s2, depth - 1, alpha, beta, false);
                visited[nr][nc] = false;
                
                if (res.first - res.second > max_eval) {
                    max_eval = res.first - res.second;
                    best = res;
                }
                alpha = max(alpha, max_eval);
                if (beta <= alpha) break;
            }
        }
    } else {
        int min_eval = 1e9;
        for (int i = 0; i < 4; ++i) {
            int nr = r2 + dr[i], nc = c2 + dc[i];
            if (can_move(nr, nc)) {
                moved = true;
                visited[nr][nc] = true;
                pair<int, int> res = minimax(r1, c1, nr, nc, s1, s2 + grid[nr][nc], depth - 1, alpha, beta, true);
                visited[nr][nc] = false;
                
                if (res.second - res.first > min_eval) {
                    min_eval = res.second - res.first;
                    best = res;
                }
                beta = min(beta, min_eval);
                if (beta <= alpha) break;
            }
        }
    }

    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> N >> M)) return 0;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> grid[i][j];

    // Initial positions
    int r1 = 0, c1 = 0;
    int r2 = N - 1, c2 = M - 1;
    
    visited[r1][c1] = true;
    visited[r2][c2] = true;

    // Depth 8-10 is usually sufficient for 100x100 matrices within 2 seconds
    pair<int, int> result = minimax(r1, c1, r2, c2, grid[r1][c1], grid[r2][c2], 10, -1e9, 1e9, true);

    cout << result.first << " " << result.second << endl;

    return 0;
}
