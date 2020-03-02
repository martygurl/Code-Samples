/* superWordSearch.cpp */
#include "superWordSearch.h"

// Macros
#define FILENAME "tests.txt" // put the name of the test file here


wordSearch::wordSearch() : m(0), n(0), numQueries(0), wrap(false), grid(nullptr), queries(nullptr) {
    // direction vectors up, right, down, left, upper-left, lower-right, upper-right, lower-left
    dir = new vector<vector<int>>{{0,1},{1,0},{0,-1},{-1,0},{-1,1},{1,-1},{1,1},{-1,-1}};
    wordSearchInit();
}


wordSearch::wordSearch(vector<vector<int>> * dir) : m(0), n(0), numQueries(0), wrap(false), grid(nullptr), queries(nullptr), dir(dir) {
    wordSearchInit();
}


// read all the information needed from inFileName
void wordSearch::wordSearchInit()
{
    ifstream inFile;
    string inFileName = FILENAME;

    inFile.open(inFileName);

    if(inFile.is_open()) 
    {
        string line, word;
        int lineNum = 0;
        while(!inFile.eof())
        {
            getline(inFile, line);
            if(line.length() == 0)
            {
                continue;
            }
            if (lineNum == 0)
            {
                istringstream ss(line);
                ss >> n >> m; // getting the dimension of the grid
                if (ss.fail())
                {
                    cout << "input format unsupported. Expected two int types." << endl;
                    break;
                }
                grid = new vector<vector<char>>{};
                grid->reserve(n);
            }
            else
            {
                if (lineNum == n+2) // the line contains the int representing the number of queries
                {
                    istringstream ss(line);
                    ss >> numQueries;
                    if (ss.fail())
                    {
                        cout << "input format unsupported. Expected one int type representing the number of queries." << endl;
                        ss.clear();
                        break;
                    }
                    queries = new vector<string>;
                    queries->reserve(numQueries);
                }
                else if (lineNum == n+1) // the line to have WRAP or NO_WRAP
                {
                    wrap = (line == "NO_WRAP") ? false : true;
                    
                }
                else if (lineNum <= n) // the grid
                {
                    vector<char> charArr;
                    for(unsigned int i = 0; i < line.length(); i++){
                        charArr.push_back(line[i]);
                    }
                    grid->push_back(charArr);
                }
                else // queries
                {
                    queries->push_back(line);
                }
            }
            lineNum++;
        }

        inFile.close();
    }
    else
    {
        cout << "Cannot open file." << endl;
    }
}



void wordSearch::printGrid()
{
    if (grid == nullptr)
    {
        cout << "grid is empty" << endl;
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << (*grid)[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}



void wordSearch::printQueries()
{
    for (int i = 0; i < (int)queries->size(); i++)
    {
        cout << (*queries)[i] << endl;
    }
    cout << endl;
}



wordSearch::~wordSearch()
{
    delete dir;
    delete grid;
    delete queries;
}


// recursive helper function
bool wordSearch::check(int &row, int &col, int pos, string& word, int &stop_r, int &stop_c, vector<vector<int>> &visited, vector<int> &move_dir, vector<vector<int>> &ans)
{
    visited[row][col]++;
    if (pos == ((int)word.length()-1) && (*grid)[row][col] == word[pos]) 
    {
        ans.push_back(vector<int>{row, col});
        return true;
    }
    if ((*grid)[row][col] != word[pos]) {
        return false;
    }
    bool found = false;
    int new_r = row + move_dir[0];
    int new_c = col + move_dir[1];

    if(!wrap)
    {
        if ((new_r >= 0) && (new_c >= 0) && (new_r < n) && (new_c < m) && (visited[new_r][new_c] == 0))
        {
            found = check(new_r, new_c, pos+1, word, stop_r, stop_c, visited, move_dir, ans);
        }
    }
    else 
    {
        // wrapping conditions for our next coordinates
        if (new_r < 0) { new_r = n+new_r; } // shift left
        else if (new_r >= n) { new_r = new_r-n; } // shift right

        if(new_c < 0) { new_c = m+new_c; }
        else if (new_c >= m) { new_c = new_c-m; }

        if(new_r == stop_r && new_c == stop_c) { return found; } // base case where we should stop wrapping
        else
        {
            if ((new_r >= 0) && (new_c >= 0) && (new_r < n) && (new_c < m) && (visited[new_r][new_c] < 2))
            {
                found = check(new_r, new_c, pos+1, word, stop_r, stop_c, visited, move_dir, ans);
            }
        }
    }
    
    return found;
}


// loop helper function to check all directions that we can move in
vector<vector<int>> wordSearch::find(string &word)
{
    vector<vector<int>> ans;
    if (grid->empty()) return ans;
    
    vector<vector<int>> visited(n, vector<int>(m,0)); // map to keep track which node we visited
    
    bool found = false;
    
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            if ((int)word.length() > 0 && (*grid)[r][c] == word[0]) // if first letters match
            {
                for (int i = 0; i < (int)dir->size(); i++) // travel all the directions
                {
                    ans.push_back(vector<int>{r,c}); // store the potential start position
                    vector<int> temp = (*dir)[i]; // get which direction we are currently moving in
                    found = check(r, c, 0, word, r, c, visited, temp, ans);
                    if (!found)
                    {
                        ans.clear();
                    }
                    else
                    {
                        return ans;
                    }
                }
            }                 
        }
    }
    return ans;
}

void wordSearch::findQueries()
{
    if queries.empty() return;
    for (int i = 0; i < numQueries; i++)
    {
        vector<vector<int>> ans = find((*queries)[i]);
        if (ans.empty()) { cout << "NOT FOUND" << endl; }
        else 
        {
            for (int j = 0; j < (int)ans.size(); j++)
            {
                cout << "(" << ans[j][0] << "," << ans[j][1] << ")";
            }
            cout << endl;
        }
    }
}