# 735. Asteroid Collision

[링크](https://leetcode.com/problems/asteroid-collision/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 요소의 개수를 N이라 하자.

먼저 모든 요소를 한번 순회해야 하므로 O(N)의 outer 시간 복잡도가 필요하다.

이후 각 원소별로 이전 값과 충돌할 수 있는 경우에 이전 값들을 한번 순회하게 된다.

이 때 불필요한 값들은 모두 제거해야하며 이 경우 모든 순회에서 탐색에 걸리는 시간은 O(N)이다.

따라서 시간복잡도는 O(N)이다.

### 공간 복잡도

스택에 쌓을 공간이 필요하며 이는 최대 O(N)의 공간 복잡도를 사용한다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |    O(N)     |

원소들을 하나씩 순회하며 이전 정답의 back과 비교하며 스택을 비운다.

절차는 다음과 같다.

1. 현재 원소가 이전 원소와 충돌해 이전 원소를 파괴할 경우, 파괴하지 않을 때 까지 스택을 pop한다.
2. 스택이 비었거나 스택의 top과 현재 값이 같은 방향인 경우 스택에 현재 원소를 삽입한다.
3. 스택의 top이 현재 원소와 같은 절대값인 경우 둘다 파괴한다.
4. 스택의 top이 현재 원소를 파괴할 경우 넘어간다.

```cpp
vector<int> asteroidCollision(vector<int>& asteroids) {
  vector<int> answer;

  for (int asteroid : asteroids) {
    while (!answer.empty() && answer.back() > 0 && answer.back() < -asteroid) {
      answer.pop_back();
    }

    if (answer.empty() || asteroid > 0 || answer.back() < 0) {
      answer.push_back(asteroid);
    } else if (asteroid < 0 && answer.back() == -asteroid) {
      answer.pop_back();
    } else {
      continue;
    }
  }

  return answer;
}
```

## 고생한 점
