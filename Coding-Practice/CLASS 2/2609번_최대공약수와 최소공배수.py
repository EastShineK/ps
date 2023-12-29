num1, num2 = map(int, input().split())

if num1 == 0:
    gcd = num2
elif num2 == 0:
    gcd = num1
    
elif num1 >= num2:
    a = num1
    b = num2

    while a % b != 0:
        r = a % b
        a = b
        b = r
        
    gcd = b
            
else:
    a = num2
    b = num1

    while a % b != 0:
        r = a % b
        a = b
        b = r
        
    gcd = b
    
lcm = num1 * num2 // gcd
    
print(gcd)
print(lcm, end='')