import sys
from collections import deque

def triangle_Check(side1, side2, side3):
    if side1+side2 <= side3:
        return 'Invalid'
    elif side1==side2==side3:
        return 'Equilateral'
    elif side1==side2 or side1==side3 or side2==side3:
        return 'Isosceles'
    else:
        return 'Scalene'

if __name__ == '__main__':
    
    print = sys.stdout.write
    
    while 1:
        sides = list(map(int,input().split()))
        sides.sort()
    
        if sides[0] == 0 :
            break;
        else:
            print(triangle_Check(sides[0], sides[1], sides[2])+'\n')
            #print(str(sides))