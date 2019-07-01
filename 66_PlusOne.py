class Solution:
    def plusOne(self, digits):
        digits[-1] += 1
        if digits[-1] >= 10:
            digits[-1] -= 10
            cin = 1
            for i in reversed(range(len(digits)-1)):
                digits[i] += cin
                if digits[i] >= 10:
                    digits[i] -= 10
                    cin = 1
                else:
                    cin = 0
            if cin:
                digits.insert(0, cin)
        return digits

if __name__ == '__main__':
    sol = Solution()
    a = [9, 9, 9]
    ans = sol.plusOne(a)
    print (ans)
    