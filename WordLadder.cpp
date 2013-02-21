#include <unordered_map>
#include <queue>

#define MAX 0x7FFFFFFF

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = start.length();
        if (len <= 0) return 0;
        if (dict.empty()) return 0;
        unordered_map<string, int> search;
        unordered_map<string, vector<string> >* graph = new unordered_map<string, vector<string> >[len];
        for (auto it = dict.begin(); it != dict.end(); it++) {
            string s = *it;
            search[s] = MAX;
            for (int i = 0; i < len; i++) {
                string tmps = s;
                tmps[i] = '*';
                auto ittmpv = graph[i].find(tmps);
                if (ittmpv == graph[i].end()) {
                    vector<string> tmpv = {s};
                    graph[i][tmps] = tmpv;
                } else {
                    graph[i][tmps].push_back(s);
                }
            }
        }
        search[start] = 1;
        
        queue<string> q;
        q.push(start);
        while (!q.empty()) {
            string s = q.front();
            int curvalue = search[s];
            q.pop();
            for (int i = 0; i < len; i++) {
                string tmps = s;
                tmps[i] = '*';
                auto ittmpv = graph[i].find(tmps);
                vector<string> tmpv = ittmpv -> second;
                for (auto it = tmpv.begin(); it != tmpv.end(); it++) {
                    if (search[*it] > curvalue + 1) {
                        search[*it] = curvalue + 1;
                        q.push(*it);
                    }
                }
            }
        }
        return search[end] == MAX ? 0 : search[end];
    }
};
