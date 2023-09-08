# 2844. Minimum Operations to Make a Special Number

[링크](https://leetcode.com/problems/minimum-operations-to-make-a-special-number/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

모든 경우를 시도해 볼 경우 경우의 수는 2^N 이므로 제한시간 내에 불가능하다.

따라서 정답으로 가능한 suffix를 가지는 경우만 탐색한다.

이 경우 하나의 suffix에 대해 O(N)의 시간 복잡도를 사용해 최소 횟수를 구할 수 있으며, 이를 모든 suffix에 대해 수행한다.

suffix의 수는 최대 5개 이므로 총 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

별도의 문자열을 생성하지 않을 경우 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      6       |    O(N)     |    O(1)     |

25로 나눠 떨어지기 위해서는 끝의 두 자리가 25, 50, 75, 00인 경우만 가능하다.

혹은 몇개의 숫자를 삭제해서 0을 만드는 경우가 가능하다.

끝의 두 자리를 특정 숫자로 만들기 위해 뒤에서 부터 탐색을 진행하며, 끝의 두 자리를 특정 숫자로 만들기 위해 필요한 최소 횟수를 구한다.

이 경우들을 탐색하며 최소 횟수를 갱신한다.

```cpp
int minimumCount(string &num, string suffix) {
  int idx = suffix.size() - 1;

  int count = 0;
  for (int i = num.size() - 1; i >= 0 && idx >= 0; i--) {
    if (num[i] == suffix[idx]) {
      idx--;
    } else {
      count++;
    }
  }

  if (idx >= 0) return num.size();

  return count;
}

int minimumOperations(string num) {
  int size = num.size();

  int answer = size;

  vector<string> suffixes = {"00", "25", "50", "75"};

  for (string &suffix : suffixes) {
    int count = minimumCount(num, suffix);

    answer = min(answer, count);
  }

  int zeroCount = 0;
  for (char &c : num) {
    if (c == '0') zeroCount++;
  }
  answer = min(answer, size - zeroCount);

  return answer;
}
```

## 고생한 점
