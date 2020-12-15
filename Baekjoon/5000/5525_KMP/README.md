# 5525. IOIOI

[링크](https://www.acmicpc.net/problem/5525)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Silver II |   33.094    |

## 설계

### 시간 복잡도

1 ≤ N ≤ 1,000,000, 2N+1 ≤ M ≤ 1,000,000 이다.

M 문자열에서 N을 검사하는데 최악의 경우 시간 복잡도는 O(NM) 이므로 제한시간 내에 불가능하다.

따라서 KMP 알고리즘을 이용해 패턴을 찾는다.

KMP 알고리즘의 경우 시간 복잡도는 O(N+M) 이므로 제한시간 내에 충분하다.

### 공간 복잡도

정답의 개수는 최대 1,000,000 이하이므로 int형으로 선언한다.

### KMP 알고리즘

패턴 index 배열 생성

```cpp
int patternLength = pattern.length();
int lineLength = line.length();

vector<int> patternIndexArr(patternLength, 0);
for (int curIdx = 1, patternIdx = 0; curIdx < patternLength; curIdx++) {
  while (patternIdx > 0 && pattern[curIdx] != pattern[patternIdx]) {
    patternIdx = patternIndexArr[patternIdx - 1];
  }
  if (pattern[curIdx] == pattern[patternIdx]) {
    patternIdx++;
    patternIndexArr[curIdx] = patternIdx;
  }
}
```

문자열을 순회하며 패턴의 위치들을 찾는다.

```cpp
vector<int> answers;

for (int lineIdx = 0, patternIdx = 0; lineIdx < lineLength; lineIdx++) {
  while (patternIdx > 0 && line[lineIdx] != pattern[patternIdx]) {
    patternIdx = patternIndexArr[patternIdx - 1];
  }

  if (line[lineIdx] == pattern[patternIdx]) {
    if (patternIdx == patternLength - 1) {
      answers.push_back(lineIdx - lineLength + 1);

      patternIdx = patternIndexArr[patternIdx];
    } else {
      patternIdx++;
    }
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      20      |       0        |

## 고생한 점
