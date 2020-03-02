#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> partitionLabels(string S) {
    // make a map of letter to its last position
    unordered_map<char, int> mp;
    //update all the letters to its max position
    for (int i = 0; i < S.length(); ++i)
    {
        mp[S[i]] = i;
    }
    
    int prev_pos = 0;
    int pos = 0;
    vector<int> ans;
    for (int i=prev_pos; i < S.length(); ++i)
    {
        pos = max(pos, mp[S[i]]);
        if ( i == pos)
        {
            ans.push_back(1+pos-prev_pos);
            prev_pos = pos+1;
        }
    }
    return ans;
}
