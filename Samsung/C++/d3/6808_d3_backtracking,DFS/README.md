# 6808. 규영이와 인영이의 카드게임

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWgv9va6HnkDFAW0&categoryId=AWgv9va6HnkDFAW0&categoryType=CODE)

난이도\_d3_41%

## 정리

내 코드 : 1,441ms
빠른 코드 : 1,040 ms
자바 빠른코드 : 825 ms

vector 보다 일반 배열로 풀었을 때 훨씬 빠르다. (600ms 단축)
next_permutation() 으로 풀었을 때는 모든 경우를 검사하므로 시간 초과 에러가 났다.
무조건 backtracking을 구현해야한다.

dfs를 사용하기 위해서 전역변수 선언을 할 수밖에 없었다.
확실히 dfs 를 호출할 때 인자를 4개 이상은 넣지 않는것이 효율적이다.

두 사람이 171점을 나눠가지는 것이므로 한사람이 85점 이상 받으면 그 케이스에서 더이상 파고 들어가지 않았다.
그 케이스에서 이기는 경우의 수는 factorial로 계산

처음에 next_permutation으로 풀었기 때문에,
이를 dfs로 바꾸는 과정에서 카드 순서의 결과를 계속 인자로 넘기다 보니
next_permutation 보다 오래 걸렸다.

결국 visited 배열을 만들고, depth 번째의 카드와 방문하지 않은 카드들을 비교해 탐색을 이어나가는 구조로 변경
이쪽이 구현도 간단하고, 시간도 훨씬 단축된다.
