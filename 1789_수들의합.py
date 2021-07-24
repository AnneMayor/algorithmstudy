s = eval(input())

num = 1
cnt = 0
while num <= s:
    s -= num
    cnt += 1
    num += 1

print(cnt)