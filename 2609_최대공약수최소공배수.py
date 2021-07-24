import sys

def getLCD(a, b):
    if a % b == 0:
        return b;
    return getLCD(b, a%b)

a, b = sys.stdin.readline().rstrip().split()

minVal = min(int(a), int(b))
maxVal = max(int(a), int(b))

lcd = getLCD(maxVal, minVal)
lcm = int(lcd * (int(a) / lcd) * (int(b) / lcd))

print(lcd)
print(lcm)
