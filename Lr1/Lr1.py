from collections import deque

j = deque()
h = deque()

n = int(input())
for i in range(n):
    s = input().split()
    if s[0] == '-':
        print(j.popleft())
    elif s[0] == '+':
        h.append(s[1])
    else:
        h.appendleft(s[1])

    if len(h) > len(j):
        x = h.popleft()
        j.append(x)