#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0)
            return vector<vector<string>>();
        else if (strs.size() == 1)
            return vector<vector<string>>({strs});
        else {
            vector<vector<string>> ans;
            unordered_map<string, vector<string>> composes;
            vector<string> empty;
            bool hasEmpty = false;
            for (int i = 0; i < strs.size(); i++) {
                if (strs[i] == "") {
                    hasEmpty = true;
                    empty.push_back("");
                    strs[i] = "-1";
                    continue;
                }
                for (int j = 0; j < strs[i].size(); j++) {
                    if (strs[i] != "-1") {
                        string tempStr = strs[i];
                        sort(tempStr.begin(), tempStr.end());

                        if (composes.find(tempStr) == composes.end()) {
                            composes[tempStr] =  vector<string>({strs[i]});
                        } else {
                            composes[tempStr].push_back(strs[i]);
                        }
                        strs[i] = "-1";
                    }
                }
            }
            if (hasEmpty)
                ans.push_back(empty);
            for (auto i: composes) {
                ans.push_back(i.second);
            }
            return ans;
        }
    }
};