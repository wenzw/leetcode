#include <unordered_map>

#define MAX 0x7FFFFFFF

class Solution {
    struct Mark {
        int graphIndex;
        int vecIndex;
    };
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function  
        vector<vector<string> > r;
        int len = start.length();
        if (len <= 0) return r;
        if (dict.empty()) return r;
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

        vector<Mark> vm;
        Mark mark0;
        mark0.graphIndex = -1;
        vm.push_back(mark0);
        int minTrans = MAX;
        int index = 0;
        while (index >= 0) {
            // choose the next node
            if (vm[index].graphIndex == -1) {
                vm[index].graphIndex = 0;
                string tmps;
                if (index == 0) {
                    tmps = start;
                } else {
                    tmps = *(vm[index-1].it);
                }
                tmps[0] = '*';
                vm[index].it = (graph[0].find(tmps)->second).begin();
            } else {
                vm[index].it++;
                string parent;
                string tmps;
                if (index == 0) {
                    parent = start;
                    tmps = start;
                } else {
                    tmps = *(vm[index-1].it);
                    parent = tmps;
                }
                tmps[vm[index].graphIndex] = '*';
                if (vm[index].it == (graph[vm[index].graphIndex].find(tmps)->second).end()) {
                    vm[index].graphIndex++;
                    if (vm[index].graphIndex >= len) {
                        vm[index].graphIndex = -1;
                        index--;
                        continue;
                    }
                    tmps = parent;
                    tmps[vm[index].graphIndex] = '*';
                    vm[index].it = (graph[vm[index].graphIndex].find(tmps)->second).begin();
                }
            }
            if ((*(vm[index].it)) == end) {
                if (index <= minTrans) {
                    if (index < minTrans) {
                        r.clear();
                    }
                    minTrans = index;
                    vector<string> tmpvs;
                    tmpvs.push_back(start);
                    for (int i = 0; i <= index; i++) {
                        tmpvs.push_back(*(vm[i].it));
                    }
                    r.clear();
                    r.push_back(tmpvs);
                }
                vm[index].graphIndex = -1;
                index--;
                continue;
            }
            index++;
            if (index >= vm.size()) {
                Mark tmpm;
                tmpm.graphIndex = -1;
                vm.push_back(tmpm);
            }
        }
        
        return r;
    }
};
