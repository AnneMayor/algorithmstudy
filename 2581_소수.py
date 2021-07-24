import sys

m = int(sys.stdin.readline().rstrip())
n = int(sys.stdin.readline().rstrip())

totalSum = 0
minPrime = 100000

for num in range(m, n+1):
    if num == 1:
        continue
    isPrime = True
    for i in range(2, num):
        if num % i == 0:
            isPrime = False
            break

    if isPrime:
        totalSum += num
        minPrime = min(minPrime, num)

if totalSum == 0:
    print(-1)
else:
    print(totalSum)
    print(minPrime)
