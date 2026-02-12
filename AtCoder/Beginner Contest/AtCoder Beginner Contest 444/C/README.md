# C - AtCoder Riko

[링크](https://atcoder.jp/contests/abc444/tasks/abc444_c)

| 난이도 |
| :----: |
|  350   |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

정답은 2가지가 가능하며, 각 경우에 대해서 문제 조건을 만족하는지 판단한다.

이를 위해 hash map을 사용할 경우 한번의 순회 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map에 O(N)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      58      |    O(N)     |    O(N)     |

정답으로 가능한 경우는 2가지 이다.

1. 모든 stick이 쪼개진 경우 : 원본 stick의 길이는 가장 짧은 stick의 길이 + 가장 긴 stick의 길이
2. 가장 긴 stick이 기준인 경우 : 원본 stick의 길이는 가장 긴 stick의 길이

위 두가지 경우에 대해 조건을 만족하는지 판단한다.

이 때 hash map을 이용해 현재 길이에 특정 길이를 더했을 때, 기준 길이에 해당하는 stick이 존재하는지 확인한다.

hash map이 비어있지 않은 경우 조건을 만족하지 않는다.

```cpp
bool check(long long val, vector<long long>& nums) {
  unordered_map<long long, int> count;

  for (long long& num : nums) {
    if (num > val) return false;

    if (num == val) continue;
    long long diff = val - num;

    if (count.count(diff) > 0) {
      count[diff]--;
      if (count[diff] == 0) count.erase(diff);
    } else {
      count[num]++;
    }
  }

  if (count.size() == 0) return true;
  return false;
}

vector<long long> solution(int size, vector<long long>& nums) {
  vector<long long> answer;

  long long minimum = *min_element(nums.begin(), nums.end());
  long long maximum = *max_element(nums.begin(), nums.end());

  // remain or broke two cases
  if (check(maximum, nums)) {
    answer.push_back(maximum);
  }

  if (check(minimum + maximum, nums)) {
    answer.push_back(minimum + maximum);
  }

  return answer;
}
```

## 고생한 점
