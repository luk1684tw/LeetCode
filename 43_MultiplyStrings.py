class Solution:
    def multiply(self, num1: str, num2: str):
        numDict = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4,
                    '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}
        n1 = 0
        n2 = 0
        for cnt, i in enumerate(reversed(range(len(num1)))):
            print (numDict[num1[i]]*10**cnt)
            n1 += numDict[num1[i]]*10**cnt
        for cnt, i in enumerate(reversed(range(len(num2)))):
            n2 += numDict[num2[i]]*10**cnt
        print (n1, n2)
        return (str(n1*n2))

if __name__ == '__main__':
    sol = Solution()
    a = '123'
    b = '456'
    ans = sol.multiply(a, b)
    print (ans)
    
        