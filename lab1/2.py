length = int(input())
numbers = list(map(int,input().split()))
blisk=int(input())
need=[]
for i in range (1,length):
    ch = numbers[0]
    for numb in numbers:
        if numb >= ch:
            ch = numb
    need.append(ch)
    numbers.remove(ch)
print(ch)