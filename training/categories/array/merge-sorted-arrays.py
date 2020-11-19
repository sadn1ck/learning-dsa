# User function Template for python3
import sys
from collections import deque


class Solution:
    def merge(self, arr1, arr2, n, m):
        # code here
        res = []
        i, j = 0, 0
        while i < n and j < m:
            if arr1[i] <= arr2[j]:
                res.append(arr1[i])
                i += 1
            else:
                res.append(arr2[j])
                j += 1

        while j != m:
            res.append(arr2[j])
            j += 1
        while i != n:
            res.append(arr1[i])
            i += 1

        print(*res)
        return res


# {
#  Driver Code Starts
# Initial Template for Python 3
if __name__ == "__main__":
    sys.stdin = open('/home/anik/projects/learning/dsa/input.txt', 'r')
    sys.stdout = open('/home/anik/projects/learning/dsa/output.txt', 'w')
    tc = int(input())
    while tc > 0:
        n, m = map(int, (input().strip().split()))
        arr1 = list(map(int, input().strip().split()))
        arr2 = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.merge(arr1, arr2, n, m)
        # for x in arr1:
        #     print(x, end=" ")
        # for x in arr2:
        #     print(x, end=" ")
        # print()
        tc = tc-1
# } Driver Code Ends
