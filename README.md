# algorithmstudy

개인적인 알고리즘 스터디 정보 및 자료 공유(소스코드, 개념 설명 등 포함)
사용언어: C/C++

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
- 트리:
- 그래프:

4. 정렬(Sorting) *코드구현 필수 | 시간복잡도 = O(n^2)
- 선택정렬(Selection Sort): 가장 작은 수를 배열에서 찾아 왼쪽으로 하나씩 정렬하는 방법(오름차순 기준)
- 삽입정렬(Insertion Sort): 왼쪽은 정렬된 배열로 오른쪽으로 한 칸씩 가면서 정렬된 왼쪽 배열에서 들어가야하는 위치 찾아 넣는 방법
- 버블정렬(Bubble Sort): 인접한 원소를 차례로 비교하여 큰 수를 오른쪽으로 보내는 방법(오른쪽이 정렬된 배열상태)
- 에라토스테네스의 체(Sieve of Eratosthenes): 특정 범위의 수까지 소수를 판별해내는 방법(소스코드 참조)

## 실전문제

- 코드그라운드(https://www.codeground.org/practice)

- 백준(https://www.acmicpc.net/)

- SW EXPERT Academy(https://swexpertacademy.com/main/main.do)
