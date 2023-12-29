import math

class Solution(object):
    def trailingZeroes(self, n):
        """n = math.factorial(n)
        n_str = str(n)
        count = 0
        for i in range(len(n_str)-1, 0, -1):
            if n_str[i] == '0':
                count = count + 1
            else:
                break;"""
        count = 0
        k = 5
        while True:
            count = count + n // 5
            n = n // 5
            if(n / 5 == 0):
                return count
        
        #return count