class Solution(object):
    def calculateBaseRep(self, num, base, loop):
        k = 1
        for i in range(loop):
            num = num - k
            k = k * base
        if num > 0:
            return -1
        elif num < 0:
            return 1
        else:
            return 0

    def smallestGoodBase(self, n):
        # n type str
        n = int(n)
        bound = pow(10, 18) - 1
        # print(bound)
        for i in range(63, 1, -1):
            low = 2
            high = bound
            while(low <= high):
                mid = low + (high - low) // 2
                # print(mid)
                mark = self.calculateBaseRep(n, mid, i)
                if mark == 0:
                    return mid
                elif mark == -1:
                    low = mid + 1
                else:
                    high = mid - 1

str = input()
s = Solution()
print(s.smallestGoodBase(str))