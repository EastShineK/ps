import sys
N = int(sys.stdin.readline())

coordinates_set = []

for i in range(0, N):
    x, y = map(int, sys.stdin.readline().split())
    coordinate = {"x": x, "y": y}
    coordinates_set.append(coordinate)

sorted_coordinates_set = sorted(coordinates_set, key=(lambda x: (x['x'], x['y'])))

for j in range(0, N):
    print(sorted_coordinates_set[j]['x'], sorted_coordinates_set[j]['y'])