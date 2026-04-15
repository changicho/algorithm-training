# B - Sensor Data Logging

[링크](https://atcoder.jp/contests/abc453/tasks/abc453_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

순회하며 마지막에 기록한 값과 비교하며 정답을 기록하는데 O(N)의 시간 복잡도를 갖는다.

### 공간 복잡도

정답 배열에 O(N)의 공간 복잡도를 갖는다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(N)     |

첫번째 값이 기록되므로, 해당 값을 기준으로 왼쪽부터 순회하며 정답 조건에 맞는 경우 기록한다.

```cpp
vector<pair<int, int>> solution(int time, int x, vector<int>& nums) {
  vector<pair<int, int>> answer;

  answer.push_back({0, nums[0]});
  for (int i = 1; i <= time; i++) {
    int cur = nums[i];

    if (abs(answer.back().second - cur) >= x) {
      answer.push_back({i, cur});
    }
  }

  return answer;
}
```

## 고생한 점
