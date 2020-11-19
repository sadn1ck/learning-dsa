import sys
sys.stdin = open('/home/anik/projects/learning/dsa/input.txt', 'r')
sys.stdout = open('/home/anik/projects/learning/dsa/output.txt', 'w')
for _ in range(int(input())):
    n, x = map(int, input().split())
    arr = list(map(int, input().split()))
    a, b = -1, -1
    for i, v in enumerate(arr):
        if v == x:
            a = i
            break
    for i, v in enumerate(arr[::-1]):
        if v == x:
            b = i
            break
    if a == -1 or b == -1:
        print(-1)
    else:
        print(a, n - b - 1)
