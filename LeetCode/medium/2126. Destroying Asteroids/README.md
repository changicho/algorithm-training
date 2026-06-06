# 2126. Destroying Asteroids

[링크](https://leetcode.com/problems/destroying-asteroids/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

작은 값부터 순회할 경우 정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

정답의 범위가 int형을 벗어날 수 있으므로 long long형으로 선언한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      29      | O(N \* log_2(N)) |    O(N)     |

문제 조건에 따라 작은 행성부터 만나고 질량에 더할 수 있는 편이 유리하다.

따라서 행성들을 정렬 후 작은 값들부터 순회하며 현재 질량과 비교한다.

```cpp
bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
  sort(asteroids.begin(), asteroids.end());

  long long cur = mass;
  for (int& a : asteroids) {
    if (a <= cur) {
      cur += a;
    } else {
      return false;
    }
  }
  return true;
}
```

## 고생한 점
