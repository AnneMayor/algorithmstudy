import sys

n = int(sys.stdin.readline())
students = []
for i in range(n):
    name, d, m, y = sys.stdin.readline().split()
    students.append([name, int(d), int(m), int(y)])

students.sort(key=lambda x : (-x[3], -x[2], -x[1]))

print(students[0][0])
print(students[n-1][0])