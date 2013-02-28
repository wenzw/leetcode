#include <unordered_map>

#define MAX 0x7FFFFFFF

class Solution {
    struct Mark {
        string orgs;
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
        unordered_map<string, bool> searched;
        unordered_map<string, vector<string> >* graph = new unordered_map<string, vector<string> >[len];
        for (auto it = dict.begin(); it != dict.end(); it++) {
            string s = *it;
            searched[s] = false;
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
        unordered_map<string, vector<string> > links;
        for (auto it = dict.begin(); it != dict.end(); it++) {
            vector<string> tmps;
            links[*it] = tmps;
        }
        for (auto it = dict.begin(); it != dict.end(); it++) {
            for (int i = 0; i < len; i++) {
                string tmps = *it;
                tmps[i] = '*';
                auto ittmp = (*graph[i].find(tmps)).second;
                unordered_set<string> tmpset;
                for (auto ittmpv = ittmp.begin(); ittmpv != ittmp.end(); ittmpv++) {
                    if (*ittmpv != *it) {
                        tmpset.insert(*ittmpv);
                    }   
                    //links[*it].push_back(*ittmpv);
                }   
                for (auto ittmps = tmpset.begin(); ittmps != tmpset.end(); ittmps++) {
                    links[*it].push_back(*ittmps);
                }   
            }   
        }
        searched[start] = true;
        for (int i = 0; i < len; i++) {
            graph[i].clear();
        }
        delete[] graph;
        
        //


        vector<Mark> vm;
        Mark mark0;
        mark0.orgs = start;
        mark0.vecIndex = -1;
        vm.push_back(mark0);
        int minTrans = MAX;
        int index = 0;
        while (index >= 0) {
            int i = ++vm[index].vecIndex;
            //if (i >= 0) {
            //    searched[links[vm[index].orgs][i]] = false;
            //}
            //i = ++vm[index].vecIndex;
            if (i >= links[vm[index].orgs].size()) {
                index--;
                continue;
            }
            string curs = links[vm[index].orgs][i];
                        int k = 0;
            for (k = 0; k <= index; k++) {
                if (curs == vm[k].orgs) {
                    break;
                }   
            }   
            if (k <= index) {
                continue;
            }
            if (curs == end) {
                if (minTrans > index) {
                    r.clear();
                    vector<string> vnew;
                    for (int j = 0; j <= index; j++) {
                        vnew.push_back(vm[j].orgs);
                    }
                    vnew.push_back(end);
                    r.push_back(vnew);
                } else if (minTrans == index) {
                    vector<string> vnew;
                    for (int j = 0; j <= index; j++) {
                        vnew.push_back(vm[j].orgs);
                    }
                    vnew.push_back(end);
                    r.push_back(vnew);
                }
                searched[curs] = false;
                index--;
                continue;
            }
            Mark mark;
            mark.orgs = curs;
            mark.vecIndex = -1;
            vm.push_back(mark);
            searched[curs] = true;
            index++;
        }
        return r;
    }
};
