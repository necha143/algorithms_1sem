n = int(input())
x = []
for i in range(n):
    x.append(list(map(int, input().split())))

k=0
while k<=n:
    for i in range(n-1):
        if x[i][1] < x[i + 1][1]:
            x[i], x[i + 1] = x[i + 1], x[i]
        elif x[i][1] == x[i + 1][1]:
            if x[i][0] > x[i + 1][0]:
                x[i], x[i + 1] = x[i + 1], x[i]
    k+=1

for i in range(n):
    print(x[i][0], x[i][1])