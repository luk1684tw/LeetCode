class Solution:
    def lengthOfLongestSubstring(self, s):
        ans = 0
        word_set = list()
        for i, char in enumerate(s):
            if char not in word_set:
                word_set.append(char)
            else:
                print ('repeated char: ', char)
                ans = max(ans, len(word_set))
                idx = word_set.index(char)
                word_set = word_set[idx + 1:]
                word_set.append(char)
            print ('current word set:', word_set)
        return max(ans, len(word_set))

            


if __name__ == '__main__':
    sol = Solution()
    testCase = 'abcabcbb'
    print (sol.lengthOfLongestSubstring(testCase))