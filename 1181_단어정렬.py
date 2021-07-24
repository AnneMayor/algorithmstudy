import sys
n = sys.stdin.readline().rstrip()

words = set()
for i in range(int(n)):
    word = sys.stdin.readline().rstrip()
    words.add(word)

words = list(words)
words.sort(key=lambda x : (len(x), x))

for word in words:
    print(word)