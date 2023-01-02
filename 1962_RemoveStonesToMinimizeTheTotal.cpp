class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> sort_piles;
        long ans = 0;
        for (auto i: piles)
        {
            sort_piles.push(i);
        }
        
        for (int i = 0; i < k; i++)
        {
            int temp = sort_piles.top();
            sort_piles.pop();
            if (temp == 1)
            {
                sort_piles.push(1);
                break;
            }

            if (temp % 2)
            {
                temp += 1;
            }
            temp /= 2;
            sort_piles.push(temp);
        }

        while (!sort_piles.empty())
        {
            ans += sort_piles.top();
            sort_piles.pop();
        }
        return ans;
    }
};