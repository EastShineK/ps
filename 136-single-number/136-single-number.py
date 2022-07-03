class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        check = [0] * 60001
        
        for i in nums:
            #print(i)
            check[i+30000] += 1
            
        for i in nums:
            #print(i)
            if check[i+30000] == 1:
                return i