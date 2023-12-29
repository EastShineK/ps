class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        count = 0
       # while i < len(nums):
       #     print(nums[i])
       #     if nums[i] == 0:
       #         count += 1
       #         nums.remove(0)
       #     i += 1
        #nums.remove(0)
        nums_copy = []
        
        for i in nums:
            #print(i)
            if i != 0:
                nums_copy.append(i)
            else:
                count += 1
        
        i = 0
        while i < count:
            nums_copy.append(0)
            i += 1
            
        i = 0
        while i < len(nums_copy):
            #print(nums_copy[i])
            nums[i] = nums_copy[i]
            i += 1
        