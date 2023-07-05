# 859. Buddy Strings

[링크](https://leetcode.com/problems/buddy-strings/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s와 goal의 길이를 N이라 하자.

s와 goal을 구성하고 있는 문자들의 수를 count한 뒤 이를 이용해 비교할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

문자는 소문자만 주어진다. 따라서 count를 위한 공간 복잡도는 O(1)이다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

s와 goal의 길이가 다른 경우 두 문자열은 같을 수 없다.

이를 먼저 판별 후 두 문자열의 길이가 같은 경우만 비교한다.

만약 두 문자열의 각 알파벳의 수가 다를 경우 s에서 두 문자를 swap하더라도 goal이 될 수 없다.

s와 goal에서 index에서 다른 문자의 수가 2인 경우 두 문자를 swap하면 같아질 수 있다.

만약 다른 문자의 수가 0인 경우 다음 두가지 경우가 존재한다.

- 같은 문자를 변경해 같은 문자열을 만들 수 있는 경우. (동일한 문자가 2개 이상 나오는 경우)
- 같은 문자를 변경해 같은 문자열을 만들 수 없는 경우. (동일한 문자가 없는 경우)

이를 구현하면 다음과 같다.

```cpp
bool buddyStrings(string s, string goal) {
  if (s.size() != goal.size()) return false;

  int size = s.size();

  int diffCount = 0;
  int sCount[26] = {
      0,
  };
  int goalCount[26] = {
      0,
  };
  int sMax = 0, goalMax = 0;

  for (int i = 0; i < size; i++) {
    sCount[s[i] - 'a']++;
    goalCount[goal[i] - 'a']++;
    sMax = max(sMax, sCount[s[i] - 'a']);
    goalMax = max(goalMax, goalCount[goal[i] - 'a']);

    if (s[i] != goal[i]) {
      diffCount++;
    }
  }

  for (int i = 0; i < 26; i++) {
    if (sCount[i] != goalCount[i]) return false;
  }

  if (diffCount == 2 || diffCount == 0 && sMax >= 2) return true;
  return false;
}
```

## 고생한 점
