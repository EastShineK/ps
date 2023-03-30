import sys
print = sys.stdout.write
N = int(sys.stdin.readline())
c_set = []

for i in range(0, N):
    x, y = map(int, sys.stdin.readline().split(' '))
    coordinate = {"x": x, "y": y}
    c_set.append(coordinate)
sort_set = sorted(c_set, key=(lambda x: (x['y'], x['x'])))
for i in range(0, N):
    print(str(sort_set[i]['x'])+" "+str(sort_set[i]['y'])+"\n")