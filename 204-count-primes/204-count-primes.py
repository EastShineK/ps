import math
class Solution(object):
    def countPrimes(self, n):
        if n == 0:
            return 0
        if n == 1:
            return 0
            
        count = [1] * (n+1)
        count[0] = 0
        count[1] = 0
        ans = 0
        for i in range(2, int(math.sqrt(n+1))+1):
            if count[i] != 0:
                for j in range(i+i, n+1, i):
                    #if j % i == 0:
                    count[j] = 0
                        
        """for i in range(2, n+1):
            #print(count[i])
            ans += count[i]"""
        ans = sum(count)
            
        if count[n] == 1:
            return ans - 1
        else:
            return ans
            
        