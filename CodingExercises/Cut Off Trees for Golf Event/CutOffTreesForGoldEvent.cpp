#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};

int nextStep(vector<vector<int>>& forest, int r, int c, int dr, int dc)
{
    if (r == dr && c == dc) return 0;
    
    int row = forest.size();
    int col = forest[0].size();
    
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    queue<pair<int, int>> q;
    q.push({r,c});
    visited[r][c] = true;
    int steps = 0;
    while(!q.empty())
    {
        steps++;
        int sz = q.size();

        for (int i = 0; i < sz; i++)
        {
            int qr = q.front().first;
            int qc = q.front().second;
            q.pop();
            for (int j = 0; j < dir.size(); j++)
            {
                int new_r = qr+dir[j][0];
                int new_c = qc+dir[j][1];
                
                if (new_r<0 || new_c<0 || new_r>=row || new_c>=col || visited[new_r][new_c] || forest[new_r][new_c] == 0) continue;
                if (new_r == dr && new_c == dc) return steps;
                visited[new_r][new_c] = true;
                q.push({new_r,new_c});
            }
        }
    }
    return -1;   
}


int cutOffTree(vector<vector<int>>& forest) {
    if (forest.empty() || forest[0].empty()) return 0;
    
    // sort the tree first;
    vector<vector<int>> trees;
    
    int row = forest.size();
    int col = forest[0].size();
    
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            if (forest[r][c] > 1)
            {
                trees.push_back({forest[r][c], r, c});
            }
        }
    }
    
    int steps = 0;
    sort(trees.begin(), trees.end());
    for(int i = 0, r = 0, c = 0; i < trees.size(); i++)
    {
        int count = nextStep(forest, r, c, trees[i][1], trees[i][2]);
        if (count == -1) return -1;
        steps += count;
        r = trees[i][1];
        c = trees[i][2];
    }
    return steps;
}
