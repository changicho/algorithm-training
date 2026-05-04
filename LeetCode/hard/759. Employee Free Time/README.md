# 759. Employee Free Time

[링크](https://leetcode.com/problems/employee-free-time/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

각 시간을 정렬 후 겹치는 시간을 구할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

BST기반의 map을 사용하는데 O(N)입니다.

### BST map

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      22      | O(N \* log_2(N)) |    O(N)     |

각 인원의 일하는 시간들에 대해서 다음과 같이 bst map에 저장한다.

- 일을 시작하는 시간 +1
- 일을 끝내는 시간 -1

이를 누적해 각 시간을 순회하며 bst map의 value에 대해 diff를 구한다.

diff가 0에서 양수로 변경될 때 사이 구간이 빈 기간이므로 정답에 추가한다.

```cpp
vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
  vector<Interval> answer;

  map<int, int> diff;
  for (vector<Interval>& s : schedule) {
    for (Interval& i : s) {
      diff[i.start]++;
      diff[i.end]--;
    }
  }

  int before = INT_MIN;
  int beforeTemp = 0;
  int temp = 0;
  for (auto [key, val] : diff) {
    beforeTemp = temp;
    temp += val;

    if (temp == 0) {
      before = key;
    } else if (beforeTemp == 0 && temp > 0) {
      if (before > 0) {
        answer.push_back({before, key});
      }
    }
  }

  return answer;
}
```

## 고생한 점
