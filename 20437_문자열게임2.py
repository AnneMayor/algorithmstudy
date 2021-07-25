import sys

t = eval(sys.stdin.readline().rstrip())

for tc in range(t):

    sentence = sys.stdin.readline().rstrip()
    k = eval(sys.stdin.readline().rstrip())

    alphaList = []

    for alpha in range(97, 123):
        alphaChr = chr(alpha)
        if sentence.count(alphaChr) >= k:
            alphaList.append(alphaChr)

    if len(alphaList) <= 0:
        print(-1)
    else:
        minVal = 1000005
        maxVal = -1
        for alpha in alphaList:
            # print(f'alpha: {alpha}')
            alphaIdx = []
            for idx in range(len(sentence)):
                if sentence[idx] == alpha:
                    alphaIdx.append(idx)

            start = 0
            cnt = 0
            for i in range(len(alphaIdx)):
                cnt += 1
                if cnt >= k:
                    minVal = min(minVal, alphaIdx[i] - alphaIdx[start] + 1)
                    maxVal = max(maxVal, alphaIdx[i] - alphaIdx[start] + 1)
                    start += 1
                    cnt -= 1

        print(minVal, maxVal)   
        