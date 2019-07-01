class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def stripNum(self, node):
        num = list()
        while node.next is not None:
            # print (node.val)
            num.append(node.val)
            node = node.next
        num.append(node.val)
        return num

    def addTwoNumbers(self, l1, l2):
        num1 = self.stripNum(l1)
        num2 = self.stripNum(l2)
        print (num1, num2)
        len1 = len(num1)
        len2 = len(num2)
        print (len1, len2)
        length = max(len1, len2)
        first = num1[0] + num2[0]
        if first >= 10:
            ans = ListNode(first - 10)
            cin = 1
        else:
            ans = ListNode(first)
            cin = 0
        tmp = ans
        for i in range(1, length):
            if i >= len1:
                digit = num2[i] + cin
            elif i >= len2:
                digit = num1[i] + cin
            else:
                digit = num1[i] + num2[i] + cin

            if digit >= 10:
                tmp.next = ListNode(digit - 10)
                tmp = tmp.next
                cin = 1
            else:
                tmp.next = ListNode(digit)
                tmp = tmp.next
                cin = 0
        if cin == 1:
            tmp.next = ListNode(1)

        return ans

            
if __name__ == '__main__':
    num1 = ListNode(1)
    tmp = num1
    for i in range(2, 8):
        tmp.next = ListNode(i)
        tmp = tmp.next

    num2 = ListNode(5)
    tmp = num2
    for i in range(6, 8):
        tmp.next = ListNode(i)
        tmp = tmp.next
    sol = Solution()
    ans = sol.addTwoNumbers(num1, num2)
    while ans.next is not None:
        print (ans.val)
        ans = ans.next
    print (ans.val)