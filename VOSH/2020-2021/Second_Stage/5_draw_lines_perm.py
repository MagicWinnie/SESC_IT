import math
import matplotlib.pyplot as plt

points = [
    [2, 0],
    [-2, 3],
    [0, 3],
    [4, 3],
    [0, -3],
    [6, 6]
    ]
angles = []

for i in range(len(points)):
    for j in range(len(points)):
        if i == j: continue

        angles.append(math.atan2(points[i][1] - points[j][1], points[i][0] - points[j][0]))
        
        if angles[-1] < 0:
            angles[-1] = math.pi - abs(angles[-1])
        
        angles[-1] = round(math.degrees(angles[-1]), 3)
        angles[-1] = 0.0 if angles[-1] == 180.0 else angles[-1]

        
        # plt.plot([points[i][0], points[j][0]], [points[i][1], points[j][1]], marker = 'o')
        # plt.axhline(0, color='black')
        # plt.axvline(0, color='black')
        # plt.show()

for i in sorted(list(set(angles))):
    print(i, ":", angles.count(i))
