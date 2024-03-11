import bisect
class Solution:
    def pathOfLIS(self, nums):
        sub = []
        subIndex = []  
        path = [-1] * len(nums)  
        for i, x in enumerate(nums):
            if len(sub) == 0 or sub[-1] < x:
                path[i] = -1 if len(subIndex) == 0 else subIndex[-1]
                sub.append(x)
                subIndex.append(i)
            else:
                idx = bisect.bisect_left(sub, x) 
                path[i] = -1 if idx == 0 else subIndex[idx - 1]
                sub[idx] = x
                subIndex[idx] = i

        ans = []
        t = subIndex[-1]
        while t >= 0:
            ans.append(nums[t])
            t = path[t]
        return ans[::-1]

print(Solution().pathOfLIS([10, 22, 9, 33, 21, 50, 41, 60, 80]))


#Answer [10, 22, 33, 41, 60, 80]