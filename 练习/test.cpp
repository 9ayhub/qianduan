#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <iomanip>
#include <ios>
#include <sstream>
#include <stack>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <iosfwd>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <cwchar>
#include <cwctype>
#include <complex.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <tgmath.h>

using namespace std;
void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m = grid.size();
    int n = grid[i].size();

    if(i < 0 || i >= m || j < 0 || j >= n) return;
    if(visited[i][j] || grid[i][j] == '0') return;

    visited[i][j] = true;
    for(auto dir : directions) {
        dfs(grid, i + dir[0], j + dir[1], visited);
    }
}
int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n));
    int res = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '1' && !visited[i][j]) {
                res++;
                dfs(grid, i, j, visited);
            }
        }
    }

    return res;
}

int main() {
    vector<vector<char>> grid;
    grid.push_back({'1','0'});
    grid.push_back({'0','1'});
    cout << numIslands(grid);
    return 0;
}
