class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        k = len(nums)
        nums.sort()
        arr = []
        for i in range(0, k):
            start = i+1
            end = k-1
            res = 0-nums[i]
            while start < end:
                if nums[i]+nums[start]+nums[end] == 0 and [nums[i], nums[start], nums[end]] not in arr:
                    arr.append([nums[i], nums[start], nums[end]])
                    start += 1
                    end -= 1
                elif nums[start]+nums[end] > res:
                    end -= 1
                else:
                    start += 1
        return (arr)
