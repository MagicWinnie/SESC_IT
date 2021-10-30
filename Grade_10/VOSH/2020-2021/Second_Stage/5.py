import math

n = int(input())
points = [list(map(int, input().split())) for _ in range(n)]

out = []
for i in range(len(points)):
    angles = []
    for j in range(len(points)):
        if i == j: continue

        if points[i][1] > points[j][1]:
            p0 = (points[j][0], points[j][1])
            p1 = (points[i][0], points[i][1])
        else:
            p1 = (points[j][0], points[j][1])
            p0 = (points[i][0], points[i][1])
        atg = math.atan2(p1[1] - p0[1], p1[0] - p0[0])
        if atg == math.pi:
            atg = 0.0
        angles.append(atg)
    out.append(
        angles.count(
            max(
                set(angles),
                key=angles.count
            )
        ) + 1
    )

print(max(out))
