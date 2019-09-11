# 7985. Rooted Binary Tree 재구성

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWu1JmN6Js4DFASy&categoryId=AWu1JmN6Js4DFASy&categoryType=CODE)

### 난이도 d3

## 정리

- BFS
- array index 접근
- 분할 정복 기법

배열을 나누어 생각하면
왼쪽 자식들, 최상단, 오른쪽 자식들
이렇게 볼 수 있다.

각 배열들을 최상단을 기준으로 왼쪽, 오른쪽으로 나눈다
나눈 배열들의 최상단을 구하고, 다시 왼쪽 오른쪽으로 나눈다
이를 반복하면 트리 구조를 복원할 수 있다.
출력 순서를 맞추기 위해 큐를 이용해 BFS 를 사용했다.

vector 로 큐를 만들지 말고 queue 를 이용하는게 더 편하다.
vector의 메모리 동적 할당 (사용한 메모리 해제)를 위해서는

```cpp
vector<vector_type>().swap(vector_name);
// vector_name : 해제하고 싶은 벡터의 이름
// vector_type : 해제하고 싶은 벡터의 타입
```
