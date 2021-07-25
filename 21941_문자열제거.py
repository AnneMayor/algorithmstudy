import sys

sentence = sys.stdin.readline().rstrip()
n = int(sys.stdin.readline().rstrip())
N = len(sentence)

removalList = []
dp = [-1] * (N+1)

def dfsSearch(idx):
    if idx >= N:
        return 0
    if dp[idx] != -1:
        return dp[idx]
    maxVal = 0;

    for word in removalList:
        score , wordLen = word[0], len(word[1])
        if idx + wordLen - 1 < N:
            if sentence[idx : idx + wordLen] == word[1]:
                maxVal = max(maxVal, score + dfsSearch(idx+wordLen))
    
    maxVal = max(maxVal, 1 + dfsSearch(idx+1))
    dp[idx] = maxVal
    
    return dp[idx]

removalList.clear()

for i in range(n):
    word, score = sys.stdin.readline().rstrip().split()
    removalList.append([eval(score), word])

removalList.sort(reverse=True)

maxScore = dfsSearch(0)

print(maxScore)