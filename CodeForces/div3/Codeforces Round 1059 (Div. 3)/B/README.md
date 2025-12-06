# B. Beautiful String

[링크](https://codeforces.com/contest/2162/problem/b)

| 난이도 |
| :----: |
|  1000  |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

모든 경우의 수를 확인하는데 O(2^N)의 시간 복잡도를 사용한다.

이후 각 경우마다 조건을 만족하는지 판단하는데 O(N)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N \* 2^N)이 된다.

### 공간 복잡도

각 경우마다 문자열을 복사하는데 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     140      | O(N \* 2^N) |    O(N)     |

문자열 s를 두 부분 문자열 p, remain으로 나누는 모든 경우를 확인한다.

이후 p는 오름차순으로 정렬되어 있는지, remain은 팰린드롬인지 확인한다.

```cpp
bool isIncreasing(string& s) {
  int size = s.size();
  if (size == 0) return true;

  for (int i = 1; i < size; i++) {
    if (s[i - 1] > s[i]) {
      return false;
    }
  }
  return true;
}

bool isPalindrome(string& s) {
  int size = s.size();
  if (size == 0) return true;

  for (int i = 0; i < size / 2; i++) {
    if (s[i] != s[size - 1 - i]) {
      return false;
    }
  }

  return true;
}

auto solution(int size, string& s) {
  vector<int> answer;

  for (int bit = 0; bit < (1 << size); bit++) {
    string p, remain;
    for (int i = 0; i < size; i++) {
      if (bit & (1 << i)) {
        p.push_back(s[i]);
      } else {
        remain.push_back(s[i]);
      }
    }

    if (isIncreasing(p) && isPalindrome(remain)) {
      for (int i = 0; i < size; i++) {
        if (bit & (1 << i)) {
          answer.push_back(i + 1);
        }
      }
      return answer;
    }
  }

  answer = {-1};

  return answer;
}
```

## 고생한 점
