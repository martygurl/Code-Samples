#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

// write a compare function to use with our priority queue later
struct compare {
    bool operator()(const pair<int,string>& p1, const pair<int,string>& p2) const
    {
        if(p1.first !=  p2.first)
        {
            return p1.first > p2.first;
        }
        return p1.second < p2.second;
    }
};

vector<string> topKFrequent(vector<string>& words, int k)  {
    unordered_map<string, int> mp;
    for(int i=0; i<words.size(); i++)
    {
        mp[words[i]]++;
    }
    priority_queue<pair<int,string>, vector<pair<int,string>>, compare> topK;

    for (auto p : mp)
    {
        topK.push({p.second, p.first});
        if(topK.size() > k)
        {
            topK.pop();
        }
    }
    vector<string> ans;
    while(!topK.empty())
    {
        ans.push_back(topK.top().second);
        topK.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
