t = int(input())
for tc in range(0, t):
    r, s = input().split()
    # ans = ""
    # for s1 in s:
    #     for r1 in range(0, r):
    #         ans += s1
    # print(ans)

    for s1 in s:
        print(s1*int(r), end='')
    print()
