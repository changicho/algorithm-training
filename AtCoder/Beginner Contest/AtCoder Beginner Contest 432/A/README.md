# A - Permute to Maximize

[링크](https://atcoder.jp/contests/abc432/tasks/abc432_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

세개의 숫자 중 큰 순서대로 정렬한다. 이에 O(1)의 시간 복잡도가 소요된다.

### 공간 복잡도

정답에 O(1)의 공간 복잡도가 소요된다.

### 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(1)     |    O(1)     |

```cpp
auto solution(int a, int b, int c) {
  vector<int> nums = {a, b, c};

  sort(nums.begin(), nums.end(), greater<int>());

  string answer = "";
  for (int num : nums) {
    answer += to_string(num);
  }

  return answer;
}
```

## 고생한 점
