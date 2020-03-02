#ifndef _SEARCH_H
#define _SEARCH_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>
using namespace std;

class wordSearch {
private:
    
    int m; // rows of grid
    int n; // columns of grid
    int numQueries;
    bool wrap;
    vector<vector<char>> *grid;
    vector<string> *queries;
    vector<vector<int>> *dir;

    // methods
    bool check(int &row, int &col, int pos, string& word, int &stop_r, int &stop_c, vector<vector<int>> &visited, vector<int> &move_dir, vector<vector<int>> &ans);
    vector<vector<int>> find(string &word);
    void wordSearchInit();
    
public:
    wordSearch();
    wordSearch(vector<vector<int>> * dir);
    void printGrid();
    void printQueries();
    void findQueries();
    ~wordSearch();

};

#endif