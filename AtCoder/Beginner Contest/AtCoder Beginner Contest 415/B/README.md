# B - Pick Two

[링크](https://atcoder.jp/contests/abc415/tasks/abc415_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(N)     |

```cpp
vector<pair<int, int>> solution(string &s) {
  vector<pair<int, int>> answer;

  int size = s.size();
  vector<int> nums;
  for (int i = 0; i < size; i++) {
    if (s[i] == '#') {
      nums.push_back(i + 1);
    }
  }

  for (int i = 0; i < nums.size(); i += 2) {
    answer.push_back({nums[i], nums[i + 1]});
  }

  return answer;
}
```

## 고생한 점
