#include <exception>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char, int> hash;
        vector<int> ans;

        for (int i = 0; i < S.size(); i++) {
            hash[S[i]] = i;
        }
        
        int size = 0;
        int maxIndex = hash[S[0]];
        for (int i = 0; i < S.size(); i++) {
            if (hash[S[i]] > i || hash[S[i]] < maxIndex) {
                size++;
                maxIndex = (maxIndex > hash[S[i]])? maxIndex: hash[S[i]];                
            } else {
                ans.push_back(++size);
                size = 0;
                if (i < S.size() - 1)
                    maxIndex = hash[S[i+1]];
            }
        }

        return ans;
    }
};