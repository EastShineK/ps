N, K = map(int, input().split())

arr = [i+1 for i in range(N)]
josephus = -1

print('<', end='')
for i in range(1, N+1):
        
    for j in range(0, K):
        josephus = josephus + 1
        if josephus >= N :
            josephus = josephus - N
        while arr[josephus] == 0:
            josephus = josephus + 1
            if josephus >= N :
                josephus = josephus - N
        
    if i == N :
        print(josephus+1, end='')
    else :
        print(josephus+1, end=', ')
        
    arr[josephus] = 0
print('>', end='')