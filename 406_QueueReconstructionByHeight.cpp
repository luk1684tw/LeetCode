#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        /*
        [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
        */
        sort(people);
        vector<vector<int>> ans;
        ans.push_back(people[0]);

        for (int i = 1; i < people.size(); i++) {
            int count = people[i][1];
            int index = 0;
            while(count > 0) {
                if (ans[index++][0] >= people[i][0]) {
                    count--;
                }
            }
            ans.insert(ans.begin() + index, people[i]);
        }
        printQueue(people);

        return ans;
    }


    // debugging 
    void printQueue(vector<vector<int>> people) {
        for (auto i: people) {
            cout << "[" << i[0] << ", " << i[1] << "]" << endl;
        }
        return;
    }

    void sort(vector<vector<int>> &people) {
        for (int i = 0; i < people.size() - 1; i++) {
            int toSwap = i;
            for (int j = i + 1; j < people.size(); j++) {
                if (people[toSwap][0] < people[j][0]) {
                    toSwap = j;
                } else if (people[toSwap][0] == people[j][0] && people[toSwap][1] > people[j][1]) {
                    toSwap = j;
                }
            }
            if (toSwap != i) {
                swap(people, i, toSwap);
            }
        }
    }

    void swap(vector<vector<int>> &people, int i, int j) {
        vector<int> temp = people[i];
        people[i] = people[j];
        people[j] = temp;
        return;
    }
};