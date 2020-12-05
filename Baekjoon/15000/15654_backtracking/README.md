# 15654. N과 M (5)

[링크](https://www.acmicpc.net/problem/15654)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Silver III |   73.997    |

## 설계

### 시간 복잡도

N combination M을 구현해야 한다.

최악의 경우 시간 복잡도는 8! 이다.

### 공간 복잡도

숫자의 개수는 최대 8개이며, 각 수는 10,000보다 작거나 같은 자연수이다.

### 재귀를 이용한 탐색

재귀함수를 이용해 다음과 같이 탐색할 수 있다.

```cpp
void recursive(vector<int> answer) {
  if (answer.size() == M) {
    for (int a : answer) {
      cout << a << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < N; i++) {
    if (visited[i]) continue;
    vector<int> new_answer = answer;
    new_answer.push_back(arr[i]);

    visited[i] = true;
    recursive(new_answer);
    visited[i] = false;
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      48      |       8        |

## 고생한 점
