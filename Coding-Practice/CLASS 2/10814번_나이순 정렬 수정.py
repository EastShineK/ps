import sys
N = int(sys.stdin.readline())

dic_in_arr = [] 

for i in range(0, N):
    age, name = sys.stdin.readline().split()
    age = int(age)
    k = {"age": age, "name": name}
    dic_in_arr.append(k)
    
sorted_arr = sorted(dic_in_arr, key=(lambda x: x['age']))

for j in range(0, N):
    print(sorted_arr[j]['age'], end=' ')
    print(sorted_arr[j]['name'])