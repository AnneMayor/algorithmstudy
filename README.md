# algorithmstudy

개인적인 알고리즘 스터디 정보 및 자료 공유(소스코드, 개념 설명 등 포함)
사용언어: C/C++
컴파일러: Xcode, Visual Studio Code

## 자료구조/알고리즘 필수 개념정리

1. 시간복잡도(Time Complexity)
- 정의: 알고리즘 수행시간
- 계산법: 기본적으론, 프로그램의 연산횟수(실행함수개수)를 세면 된다. 일반적으로 빅오(O(n)) 표기법을 활용하여 최악의 케이스 시간복잡도(worst case time complexity)를 계산한다.
- 예시: for문 = O(n) / 이중for문 = O(n) or O(nlogN) ... / 재귀함수 = T(n) <= c*n -> O(n)
- 참고: https://jhnah917.tistory.com/41 (재귀함수의 시간복잡도)

2. 공간복잡도(Space Complexity)
- 정의: 알고리즘 메모리 사용량
- 계산법: 기본적으로, 메모리 사용량을 측정하면 된다. 시간복잡도에 비해 중요시하게 생각되는 부분은 아니나 만일 메모리 초과 현상이 나타나면 프로그램 실행이 안된다.
- 예시: 1,2차원 배열크기 및 변수(O(1))

3. 자료구조(Data Structure)
- 선형자료구조(Linear): 스택(Stack) / 큐(Queue)
- 트리: 자료를 담기 위한 하나의 구조체. 어떤 자료가 들어있는지 알기 위해 순회하는 방법을 중요시하게 알고 있어야함. (우선순위 큐 구현 시, 시간복잡도 개선을 위해 사용하는 자료구조 = 힙)
- 그래프:
- 리스트(List): 
- 힙(Heap): 
- 해시(Hash): 

4. 정렬(Sorting) *코드구현 필수 | 시간복잡도 = O(n^2)
- 선택정렬(Selection Sort): 가장 작은 수를 배열에서 찾아 왼쪽으로 하나씩 정렬하는 방법(오름차순 기준)
- 삽입정렬(Insertion Sort): 왼쪽은 정렬된 배열로 오른쪽으로 한 칸씩 가면서 정렬된 왼쪽 배열에서 들어가야하는 위치 찾아 넣는 방법
- 버블정렬(Bubble Sort): 인접한 원소를 차례로 비교하여 큰 수를 오른쪽으로 보내는 방법(오른쪽이 정렬된 배열상태)
- 에라토스테네스의 체(Sieve of Eratosthenes): 특정 범위의 수까지 소수를 판별해내는 방법(소스코드 참조)

4-1. 고급정렬 *코드구현 필수 | 시간복잡도 = O(nlogN)
- 4번 정렬방법에서 시간복잡도 개선을 위한 정렬방법
- 퀵정렬(QuickSort): pivot값을 기준으로 pivot보다 작은 값을 왼쪽으로 pivot보다 큰 값을 오른쪽으로 넣고 마지막으로 pivot의 위치를 정하는 과정을 n/2만큼 수행. 따라서, 시간복잡도는 O(nlogN).
- 합병정렬(MergeSort): 주어진 배열을 반으로 나눈 후, 왼쪽과 오른쪽 배열 정렬을 각각 행한 후 이를 하나로 합치는 수행. 시간복잡도는 T(n) = 2*T(n/2) + O(n)이므로 O(nlogN)

5. 알고리즘(algorithm)
- DP(다이나믹 프로그래밍): 

6. 탐색(Search)
- 이진탐색(Binary Search): 
- 너비우선탐색(BFS):
- 깊이우선탐색(DFS):

## 실전문제

- 코드그라운드(https://www.codeground.org/practice)

- 백준(https://www.acmicpc.net/)

- SW EXPERT Academy(https://swexpertacademy.com/main/main.do)
