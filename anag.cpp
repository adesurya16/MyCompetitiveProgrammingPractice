#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
typedef vector<vs> vvs;
typedef map<string,vs> mvs; 

#define ALLV(v) v.begin(), v.end()
#define SORTV(v) sort(ALLV(v))
#define watch(x) cout << (#x) << " : " << (x) << endl

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    mvs maps;
    for(string str : strs){
        string s = str;
        SORTV(s);
        maps[s].push_back(str);
    }

    vvs ans;
    for(auto val : maps){
        ans.push_back(val.second);
        cout << val.first << endl;
    }
    return ans;
}

int main(){ 
    vs strs;
    // vs strs = ("eat", "tea", "tan", "ate", "nat", "bat");
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");

    vvs ans = groupAnagrams(strs);    
    return 0;
}