# 3169. Count Days Without Meetings

[링크](https://leetcode.com/problems/count-days-without-meetings/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 배열 meetings의 크기를 N이라 하자.

BST기반의 map을 사용할 경우 O(N * log_2(N))의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

map에 O(N)의 공간 복잡도가 필요하다.

### BST map

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|      72      | O(N * log_2(N)) |    O(N)     |

각 미팅의 시작시간에 따른 가장 늦은 미팅의 끝나는 시간을 저장한다.

이후 각 미팅의 시작시간에 대해 순회하며 이전에 끝나는 시간과 현재 시작시간을 비교한다.

이후 이전에 끝나는 시간을 갱신한다.

```cpp
int countDays(int days, vector<vector<int>> &meetings) {
  map<int, int> m;
  for (vector<int> &meeting : meetings) {
    int left = meeting[0], right = meeting[1];
    m[left] = max(m[left], right);
  }

  int answer = 0;
  int before = 1;
  for (auto &[left, right] : m) {
    if (before < left) {
      answer += left - before;
    }
    before = max(before, right + 1);
  }
  if (before <= days) {
    answer += days - before + 1;
  }

  return answer;
}
```

## 고생한 점
