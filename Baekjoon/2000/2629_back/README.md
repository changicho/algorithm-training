# 2629. 양팔저울

[링크](https://www.acmicpc.net/problem/2629)

| 난이도  | 정답률(\_%) |
| :-----: | :---------: |
| Gold II |   26.780    |

## 설계

### 시간 복잡도

각 무게추별로 탐색을 진행할 때 경우는 3가지 이다.

- 왼쪽에 무게추를 놓음
- 이번 무게추는 무시함
- 오른쪽에 무게추를 놓음

따라서 모든 경우의 시간 복잡도를 계산하면

3^30이므로 매우 큰 숫자이며, 제한시간 1초 내에 불가능하다.

따라서 backtracking을 적용해야 한다.

backtracking을 적용할 때 각 경우를 살펴본다

- 현재 i 번째 구슬까지 탐색했을 때, 이전에 탐색했을 때 i번째에서 현재와 같은 total을 가지고 있었는지

### 공간 복잡도

무게 추로 만들 수 있는 크기의 범위는 15,000 까지이다.

무게 추는 최대 30개 까지이므로

[31][15,000] 크기의 boolean 배열을 선언한다.

또한 무게 추들로 만들 수 있는 숫자의 범위는 15,000 까지 이므로 int형으로 선언한다.

### backtracking

모든 무게추에 대해서 탐색을 진행한다.

탐색을 진행할 때, 현재 total에서 현재 무게추를 더하는 경우, 빼는 경우, 현재 무게추를 무시하는 경우

세가지 경우를 탐색한다.

빼는 경우에서 음수가 나오는 경우 양수로 보정해준다.

이는 양 팔 저울의 특성과 연관이 있는데, 빼는 경우는 현재 사용하는 쪽의 반대쪽에 추를 올려놓는 경우이기 때문이다.

이 때 현재 index에서 total을 이미 만들었는지 검사한다.

```cpp
void dfs(int index, int total) {
  if (index > weights.size() || visited[index][total]) {
    return;
  }

  visited[index][total] = true;

  int plus = total + weights[index];
  int minus = absolute(total - weights[index]);

  dfs(index + 1, total);
  dfs(index + 1, plus);
  dfs(index + 1, minus);
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
