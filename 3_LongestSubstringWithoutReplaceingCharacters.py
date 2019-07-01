class Solution:
    def lengthOfLongestSubstring(self, s):
        ans = 0
        left = 0
        position = dict()
        for i in range(len(s)):
            if s[i] not in position:
                position[s[i]] = i
        cnt = 0
        for i in range(len(s)):
            if i > position[s[i]]:
                left = position[s[i]] + 1
                position[s[i]] = i
                ans = max(ans, cnt)
                cnt = i + 1 - left
            else:
                cnt += 1
                if i == len(s) - 1:
                    ans = max(ans, cnt)

            print ('Current Left:', left)
            print ('Current position:', i)
            print ('Current ans:', ans)
            print ('Current dict:', position, '\n')
        return ans

            


if __name__ == '__main__':
    sol = Solution()
    testCase = 'tmmzuxt'
    print (sol.lengthOfLongestSubstring(testCase))