A, B = input().split()
C = int(input())

A = int(A)
B = int(B)

hour = C // 60
min = C % 60

hour = hour + A
min = min + B

if min >= 60:
    min -= 60
    hour += 1

if hour >= 24:
    hour -= 24

print(hour,min)