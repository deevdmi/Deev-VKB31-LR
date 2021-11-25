from itertools import combinations

pupil, group, group2 = map(int, input().split())
pupils = [int(input()) for line in range(pupil)]

print(min(max(x[(i + 1) * group2 - 1] - x[i * group2] for i in range(group))
          for x in map(sorted, combinations(pupils, group * group2))))