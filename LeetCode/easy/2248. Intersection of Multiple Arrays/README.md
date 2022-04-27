# 2248. Intersection of Multiple Arrays

[링크](https://leetcode.com/contest/weekly-contest-290/problems/intersection-of-multiple-arrays/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

nums의 모든 원소의 갯수를 N이라 하자.

각 vector들의 intersection을 구하기 위해서 한번씩 순회해야 하므로 O(N)의 시간 복잡도를 사용한다.

동시에 모든 vector에서 나타나는 값을 구하기 위해 hash map을 이용한 counting을 수행한다.

이후 각 값이 모두 나타나는 경우만 정답에 추가한다.

이후 정답을 정렬해야 하므로 O(N \* log_2(N))의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N \* log_2(N)) 이다.

### 공간 복잡도

count를 수행하기 위해 O(N)의 공간 복잡도를 사용한다.

### 카운팅

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      17      | O(N \* log_2(N)) |    O(N)     |

nums안의 모든 원소를 순회하며 counting한다.

이후 모든 vector에서 나타나는 값들은 counting한 값의 nums의 크기와 같은 경우이다.

(모든 경우에 포함되며 count하므로)

이후 이 값들을 정렬해 정답으로 반환한다.

이를 구현하면 다음과 같다.

```cpp
vector<int> intersection(vector<vector<int>> &nums) {
  int size = nums.size();
  unordered_map<int, int> counts;

  for (vector<int> &array : nums) {
    for (int &n : array) {
      counts[n]++;
    }
  }

  vector<int> ret;
  for (auto &[key, val] : counts) {
    if (val == size) ret.push_back(key);
  }
  sort(ret.begin(), ret.end());
  return ret;
}
```

## 고생한 점
