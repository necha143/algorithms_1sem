length = int(input())
droids= list(map(int, input().split()))
delete = []
for i in range(2):
    num = droids[0]
    for droid in droids:
        if droid < num:
            num = droid
    delete.append(num)
    droids.remove(num)

print (" ".join(map(str,delete)))