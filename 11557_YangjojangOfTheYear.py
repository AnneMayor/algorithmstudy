import sys

t = eval(sys.stdin.readline())

for tc in range(t):
    n = eval(sys.stdin.readline())
    topUniv = ""
    maxDrink = -1
    for i in range(n):
        univ, drink = sys.stdin.readline().split()
        if maxDrink < int(drink):
            topUniv = univ
            maxDrink = int(drink)
    print(topUniv)