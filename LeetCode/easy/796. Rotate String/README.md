# 796. Rotate String

[링크](https://leetcode.com/problems/rotate-string/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N, goal의 길이를 M이라 하자.

s를 shift했을 때 goal로 도달할 수 있는지 여부를 판별해야한다.

투 포인터를 이용해 모든 index에서 시작했을 때 goal로 변환 가능한지 판별할 수 있다.

이 경우 O(N \* M)의 시간 복잡도를 사용한다.

KMP알고리즘을 이용해 풀이할 경우 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

투 포인터를 사용할 경우 상수크기의 공간복잡도를 사용한다. O(1)

KMP 알고리즘을 이용할 경우 s를 이어붙이는데 O(N), goal의 index 배열을 만드는데 O(M)의 공간 복잡도를 사용하므로 O(N + M)의 공간 복잡도를 사용한다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |  O(N \* M)  |    O(1)     |

s의 문자를 순회하며 해당 문자를 시작점으로 하는 문자열에 대해(circular) goal과 같은지 비교한다.

```cpp
bool rotateString(string s, string goal) {
  if (s.length() != goal.length()) return false;
  int length = s.length();

  for (int start = 0; start < length; start++) {
    if (s[start] != goal[0]) continue;

    bool isSame = true;
    for (int i = 0; i < length; i++) {
      if (s[(start + i) % length] != goal[i]) {
        isSame = false;
        break;
      }
    }

    if (isSame) return true;
  }
  return false;
}
```

### KMP

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |  O(N + M)   |

s를 2번 반복한 문자열에 goal이 포함되는지 여부로 문제를 풀이할 수 있다.

이 때 goal에 대해서 KMP알고리즘을 이용해 pattern index 배열을 만든다.

goal 문자열에 비슷한 패턴이 있는경우 mismatch시에 이전 index로 돌아가며 탐색을 진행한다.

이를 다음과 같이 구현한다.

```cpp
bool rotateString(string s, string goal) {
  // edge case
  if (s.length() != goal.length()) return false;

  string line = s + s;

  vector<int> patterns(goal.length(), 0);
  for (int i = 1, pIdx = 0; i < goal.length(); i++) {
    // restore parent's index
    while (pIdx > 0 && goal[i] != goal[pIdx]) {
      pIdx = patterns[pIdx - 1];
    }

    if (goal[i] == goal[pIdx]) {
      pIdx++;
      patterns[i] = pIdx;
    }
  }

  for (int i = 0, pIdx = 0; i < line.length(); i++) {
    // restore parent's index
    while (pIdx > 0 && line[i] != goal[pIdx]) {
      pIdx = patterns[pIdx - 1];
    }

    if (line[i] != goal[pIdx]) continue;
    if (pIdx < goal.length() - 1) {
      pIdx++;
      continue;
    }

    // reach to goal's end
    return true;
  }

  return false;
}
```

## 고생한 점
