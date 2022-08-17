# 487. Max Consecutive Ones II

[링크](https://leetcode.com/problems/max-consecutive-ones-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

각 원소를 순회하며 연속된 1의 최대 갯수와 시작 위치를 찾는다. 이 경우 O(N)의 시간 복잡도를 사용한다.

이 값들을 순회하며 이어붙일 수 있는 경우, 불가능한 경우에 대해 정답을 갱신한다.

혹인 원소를 순회하며 연속된 1의 갯수를 센다. 이 때 이어 붙일 수 있는 경우까지 세기 위해 직전의 연속된 1의 갯수 또한 저장한다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 count들을 저장하고 순회하며 정답을 구할 경우 O(N)의 공간 복잡도를 사용한다.

한번의 순회와 직전값만 저장을 이용해 풀이할 경우 O(1)의 공간 복잡도를 사용한다.

### 연속된 수 저장

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      75      |    O(N)     |    O(N)     |

각 연속된 1들의 시작 index와 끝 index를 ranges에 저장한다.

이 range들을 순회하며 직전 값과 이어 붙일 수 있는경우 (1칸만 비어있고 연속됨) 직전 값과 현재 값을 이어붙인 값을 정답으로 갱신한다.

혹은 현재 값 + 1을 정답으로 갱신한다.

이 때 최소 1칸을 정답으로 만들 수 있으므로 정답의 최소값은 1이며, 하나의 range만 정답으로 사용할 때도 +1한 값이 정답이 된다.

정답은 N을 넘을 수 없으므로 넘는 경우 크기를 줄인다.

```cpp
int findMaxConsecutiveOnes(vector<int>& nums) {
  int size = nums.size();
  int left = -1, right = -1;
  vector<pair<int, int>> ranges;
  for (int i = 0; i < size; i++) {
    if (nums[i] == 0) {
      if (left != -1 && right != -1) {
        ranges.push_back({left, right});
      }

      left = -1, right = -1;
      continue;
    }

    if (left == -1) left = i;
    right = i;
  }
  if (left != -1 && right != -1) {
    ranges.push_back({left, right});
  }

  int answer = 1;
  for (int i = 0; i < ranges.size(); i++) {
    pair<int, int> range = ranges[i];
    int curLength = range.second - range.first + 1;
    answer = max(answer, curLength);

    if (curLength < size) {
      answer = max(answer, curLength + 1);
    }

    if (i == 0) continue;
    pair<int, int> before = ranges[i - 1];
    if (before.second + 2 == range.first) {
      int beforeLength = before.second - before.first + 1;
      answer = max(answer, curLength + beforeLength + 1);
    }
  }
  return answer;
}
```

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      67      |    O(N)     |    O(1)     |

왼쪽부터 순회하며 연속된 1의 갯수를 센다.

이 때 현재 값이 0인 경우 현재까지 센 1의 연속된 갯수를 before로 저장한다.

이후 현재 index에서, 지금까지 센 연속된 1 직전에 연속된 1이 있는 경우 before와 현재 count한 값을 더해 정답을 갱신한다.

```cpp
int findMaxConsecutiveOnes(vector<int>& nums) {
  int size = nums.size();

  int count = 0, before = 0;
  int answer = 0;
  for (int i = 0; i < size; i++) {
    if (nums[i] == 1) {
      count++;
    } else {
      before = count;
      count = 0;
    }

    answer = max(answer, min(count + 1, size));

    if (0 <= i - count - 1 && nums[i - count - 1] == 1) {
      answer = max(answer, count + before + 1);
    }
  }

  return answer;
}
```

## 고생한 점
