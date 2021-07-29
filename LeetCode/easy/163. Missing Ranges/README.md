# 163. Missing Ranges

[링크](https://leetcode.com/problems/missing-ranges/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

nums의 모든 원소의 개수를 N이라 하자.

각 숫자별로 visit을 체크하는 경우 범위가 매우 크므로 (-10^9 ~ 10^9) 제한시간 내에 불가능하다.

따라서 nums의 원소를 순회하며 range를 구하는 방법으로 풀이한다.

이는 한번의 순회로 가능하므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

정답에 최대 N개의 range가 생길 수 있으므로 공간 복잡도는 O(N)이다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

다음 3가지 영역에 대해서 range를 구성한다.

- lower ~ nums.front()
- nums
- nums.back() ~ upper

여기서 a ~ b 사이에 빈 영역을 채워넣기 위한 값의 range는 (a+1) ~ (b-1)이다.

```cpp
string convert(int from, int to) {
  if (from == to) {
    return to_string(from);
  }
  return to_string(from) + "->" + to_string(to);
}

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
  if (nums.size() == 0) {
    return {convert(lower, upper)};
  }

  vector<string> answer;
  int before = lower;
  if (lower != nums.front()) {
    answer.push_back(convert(lower, nums.front() - 1));
    before = nums.front();
  }
  for (int num : nums) {
    if (num > upper) break;

    if (before + 1 < num) {
      answer.push_back(convert(before + 1, num - 1));
    }
    before = num;
  }
  if (before + 1 <= upper) {
    answer.push_back(convert(before + 1, upper));
  }

  return answer;
}
```

## 고생한 점
