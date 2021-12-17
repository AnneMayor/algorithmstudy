# 🌟 algorithmstudy 🌟

개인적인 알고리즘 스터디 정보 및 자료 공유(소스코드, 개념 설명 등 포함)
사용언어: C/C++
컴파일러: Xcode, Visual Studio Code, Visual Studio 2013(Windows10)

## 📚 자료구조/알고리즘 필수 개념정리

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
- 그래프: 자료들간의 관계를 나타내는 자료구조. 정점(Vertex)과 간선(Edge)로 구성되어있음. 그래프에는 크게 무방향 그래프와 단방향 그래프로 나뉘어짐. 각 정점의 간선 개수에 따라 차수(degree)가 다름. 그래프 구현 시, 인접행렬과 인접리스트 두 가지 방법으로 가능.
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
- DP(다이나믹 프로그래밍): 반복되는 재귀함수 호출에서 저장공간을 만들어 반복부분을 저장하여 부분문제를 통해 전체문제를 해결하는 알고리즘. 흔히, 문제에서 점화식을 찾아내어 해결한다.
** 대표적인 예: 최장증가부분수열, 최장공통부분수열, knapsack
- two-pointer 기법: start, end index를 만들어 각각의 조건에 따라 start 혹은 end index를 증가시키며 답을 구하는 방법. 

6. 탐색(Search)
- 이진탐색(Binary Search): 
- 너비우선탐색(BFS): 자료구조 중 그래프 순회방법 중 한가지로 큐 자료구조를 활용하여 데이터를 순회한다. DFS와는 달리, 인접 리스트에 저장된 각각의 인접한 노드를 먼저 방문하여 탐색을 시작.
- 깊이우선탐색(DFS): 자료구조 중 그래프 순회방법 중 한가지로 인접 리스트로 그래프 자료구조에 저장된 데이터를 순회한다. 시간복잡도는 <italic>O(V+2*E) = O(V+E)</italic> 구현할 때에는 스택 자료구조도 활용.(재귀호출)
- ** Backtracking: 완전탐색을 실행하는 깊이우선탐색(DFS)과 달리, 비효율적인 경로를 차단하고 목표지점에 도달할 때 사용하는 알고리즘 기법. DFS+Pruning(가지치기)를 통해 가도되지않는 루트를 제외시킴.(대표예제: N-Queen문제)

7. 규칙찾기
- 삼성 Advanced Level 알고리즘 시험문제에서 자주 출제되는 유형.
- 대표적인 예제: 1011 Fly me to the Alpha Centauri, 1016 제곱ㄴㄴ수, 1019 책페이지, 1052 물병

8. 그래프
- DFS와 BFS: 깊이우선탐색(재귀함수)과 너비우선탐색(Queue)
- 최단경로 구하기: 다익스트라 알고리즘(양수 가중치에서만 사용가능), Bellman-Ford 알고리즘(음수 가중치에서도 사용 가능)
- 최단경로구하기: 최소스패닝트리(MST) 개념 등장. 구현 방법으로는 Kruskal 알고리즘(시간복잡도: O(ElogE))과 Prim 알고리즘(시간복잡도: O(V^2+E))이 있음. Prim알고리즘의 경우, 그래프 정점 사이에 간선이 밀집되어있을 때 Kruskal보다 효율성이 좋음. 정당성 증명 방법의 경우, 어떤 간선 (u, v)를 지나지 않는 최소 스패닝 트리가 있다는 전제하에 시작.

9. 트라이
(추후 추가예정)

10. 문자열
- KMP 알고리즘: 일반적으로 웹브라우져에서 특정단어 포함 문자열 빠른 검색 시 활용되는 알고리즘. Pi[] 배열을 활용하여 찾고자 하는 문자열에 반복되는 문자가 포함될 경우, 반복 위치와 문자 저장. 시간복잡도: O(N+M)=>각 문자열의 길이의 합
- 라빈 카프 알고리즘: 

11. 비트연산자
- 실제 시물레이션 문제에서 유용하게 활용할 수 있는 컴퓨터 연산장치. &(교집합), |(합집합), ^(차집합) 등 활용할 수 있음. Low 레벨단에서 많이 활용하는 연산(임베디드 프로그래밍)
- 예시: 2020 카카오 블라인드 No.5 기둥과 보 설치, 2018 카카오 블라인드 No. 3 후보키

12. Segment Tree
(추후 추가예정)

13. 투포인터
- Simulation(구현) 문제에서 기본이 되는 개념. 원리는 _정렬된_  배열의 앞, 뒤 두 개의 인덱스(포인터)를 설정하여 각 인덱스에 해당하는 배열값으로 연산한 결과와 주어진 기준의 차가 얼마인가에 따라 포인터 이동을 하는 방식.(투 포인터 값의 합 - 문제에서 주어진 숫자 > 0이면, 뒤의 포인터를 하나 앞으로 이동. 그 반대면 앞의 포인터를 하나 뒤로 이동)

## 💻 실전문제

- 코드그라운드(https://www.codeground.org/practice)

- 백준(https://www.acmicpc.net/)

- SW EXPERT Academy(https://swexpertacademy.com/main/main.do)

- 알고스팟(algospot): https://algospot.com/

- Codejam 기출문제(https://codingcompetitions.withgoogle.com/codejam/archive)

- 프로그래머스(Programmers): https://programmers.co.kr/

- AlgoExpert: https://www.algoexpert.io/product

## 🥇 알고리즘 대회

- 코드포스(온라인) : https://codeforces.com/

- Code Jam(온라인) : https://codingcompetitions.withgoogle.com/codejam

- ACM-ICPC : http://icpckorea.org/

- Atcoder: https://kenkoooo.com/atcoder/#/table/pranne1224 

## 👀 참고자료

- 10158 개미(백준) : https://hanstemcell.tistory.com/entry/%EB%B0%B1%EC%A4%80-%EA%B0%9C%EB%AF%B8?category=672485
- 1963 소수 경로(백준) : https://lmcoa15.tistory.com/63
- 2580 스도쿠(백준) : https://dongyeollee.github.io/2018/09/03/Al/2580/
- 6549 히스토그램에서 가장 큰 직사각형(백준) : https://greeksharifa.github.io/ps/2018/07/07/PS-06549/
- 13144 List of Unique Numbers(백준) : 재귀함수로 풀면, 시간초과 뜸. 이 문제는 two-pointer 기법을 적용하여 풀어야 함. http://blog.naver.com/PostView.nhn?blogId=programmer18&logNo=220876732845
- 3032 홍준이의숫자놀이 D3(SWExpertAcademy) : 확장된 유클리드 알고리즘 활용(https://brilliant.org/wiki/extended-euclidean-algorithm/)
- 1011 Fly me to the Alpha Centauri(백준) : 규칙찾기 연습문제(https://www.acmicpc.net/board/view/13747) => 문제 풀기 전 반드시 체크해야할 내용: https://www.acmicpc.net/board/view/26059
- 1016 제곱ㄴㄴ수(백준): 시간초과나는 문제를 규칙을 찾아 간결한 코드로 정리 가능!(https://wootool.tistory.com/39)
- 1019 책페이지(백준): 나중에 다시 풀어봐야할 문제list 중 하나.(https://jm25.tistory.com/53)
- 1052 물병(백준): 재귀함수로 짤 경우, 시간초과나는 문제. 마찬가지로, 문제에서 규칙을 찾아 효율적인 코드 작성을 필요로 하는 문제.(https://yabmoons.tistory.com/199)
- 1992 쿼드트리(백준): 재귀함수 설계 시, x와 y좌표도 매개변수로 넣어줘야한다.(https://jaimemin.tistory.com/1072)
- 1074 Z(백준) : 재귀함수 시간초과 연습하기 좋은 문제. 재귀함수 기저조건을 찾고자 하는 위치의 좌표로 놓고 생각해보는 문제다!(https://sanghoon3018.tistory.com/49)
- 2263 트리의순회(백준) : 트리의 정렬순서와 재귀함수를 이용한 문제. 정렬순서별 규칙을 찾아야 한다!(https://donggod.tistory.com/103)
- 공백 포함 문자열 입력받는 방법에 관한 글: https://jiwondh.github.io/2017/09/23/cin.getline/
- 2610 회의준비(백준) : DFS와 BFS 두 개를 활용하는 문제. 이 문제처럼 최단거리를 구해야할 경우엔 BFS를 써줘야 한다. 처음에 그래프 정점 중 가장 많은 정점과 연결된 정점이 답일 거라 생각하여 설계하였으나 설계 가정 자체가 틀렸음을 발견함. 따라서, 최단거리 관련한 문제는 BFS 접근방식을 먼저 떠올려야 한다.
- 1014 컨닝(백준) : 일반 DFS,BFS로는 시간초과가 걸리는 문제. 해결방법은 네트워크 플로우와 Bitmasking DP 총 두 가지 기법으로 다음 링크는 Bitmasking DP 기법을 활용한 풀이를 공유해놓음. https://github.com/cannalee90/Problem_Solving/blob/master/BOJ/1014_%EC%BB%A8%EB%8B%9D.cpp
- 16137 견우와직녀(백준) : BFS 문제에서도 한 번만 증가하는 것이 아닌 계속 방문했던 정점을 지날 수 있는 경우의 최소값을 구하는 풀이 연습하기 좋은 문제. 조건에서 "하나의 오작교만 만든다"는 조건의 의미 파악하는 것이 중요! https://yabmoons.tistory.com/207
- 2020 Codejam Contest : kdh9949님과 cki86201님 제출답변. 새로운 구현방법을 터득할 수 있었음.(+독창적인 풀이법)
- 2020 KAKAO BLIND No.5 기둥과 보 설치: https://biewoom.github.io/coding%20test/kakao%202020%20blind/2020/04/20/pillar.html
