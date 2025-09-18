class Solution:
    def twoSum(nums, target):
        i = 0
        while i < len(nums):
            current = nums[i]
            needed = target - current

            if needed in nums:
                needed_index = nums.index(needed)
                if needed_index == i:
                    i += 1
                else:
                    break
            else:
                i += 1
    
        return [i,needed_index]