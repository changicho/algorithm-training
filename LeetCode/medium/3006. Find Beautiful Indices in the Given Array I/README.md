# 3006. Find Beautiful Indices in the Given Array I

[링크](https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N, a와 b의 길이를 M이라 하자.

a, b가 s에 나타나는지 직접 탐색할 경우 O(N * M)의 시간 복잡도를 사용한다.

KMP알고리즘을 사용할 경우 O(N + M)의 시간 복잡도를 사용한다.

이후 a, b가 나타나는 index에 대해 K에 대한 조건을 만족하는 쌍들을 찾아야 한다.

index의 최대 갯수는 N이며 이를 모두 탐색할 경우 O(N^2)의 시간 복잡도가 소요된다.

이분 탐색을 사용할 경우 O(N \* log_2(N))의 시간 복잡도가 소요된다.

투 포인터를 사용할 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

KMP 알고리즘에 O(N + M)의 공간 복잡도를 사용한다.

s에 a, b가 나타나는 index를 저장할 경우 O(N)의 공간 복잡도가 필요하다.

### KMP 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |  O(N + M)   |  O(N + M)   |

s에서 a, b가 나타나는 index를 찾는다.

이를 위해 KMP 알고리즘을 사용한다. 이 과정에서 오름차순으로 정렬된 index들을 얻을 수 있다.

이후 a, b가 나타나는 index에 대해 K에 대한 조건을 만족하는 쌍들을 찾는다.

투 포인터를 사용해 다음과 같이 순회하며 찾을 수 있다.

- a의 index에 대해 순회한다.
- 이 때 a의 현재값보다 작으며 차이가 K이하인 b의 index를 증가시키며 찾는다.
- 이 경우 b의 현재 값이 a의 현재 값보다 작은 경우만 b의 index를 증가시킨다.
- 찾은 경우 현재 a의 index를 정답에 추가한다.
- 못찾은 경우 다음 a의 index를 탐색한다.

이를 구현하면 다음과 같다.

```cpp
vector<int> kmp(string &s, string &pattern) {
  int size = s.size(), patternSize = pattern.size();
  vector<int> patternArr(patternSize, 0);
  vector<int> ret;

  for (int i = 1, pI = 0; i < patternSize; i++) {
    while (pI > 0 && pattern[i] != pattern[pI]) {
      pI = patternArr[pI - 1];
    }
    if (pattern[i] == pattern[pI]) {
      pI++;
      patternArr[i] = pI;
    }
  }

  for (int i = 0, pI = 0; i < size; i++) {
    while (pI > 0 && s[i] != pattern[pI]) {
      pI = patternArr[pI - 1];
    }

    if (s[i] == pattern[pI]) {
      if (pI == patternSize - 1) {
        ret.push_back(i - patternSize + 1);

        pI = patternArr[pI];
      } else {
        pI++;
      }
    }
  }
  return ret;
}

vector<int> beautifulIndices(string s, string a, string b, int k) {
  vector<int> aIndexes = kmp(s, a);
  vector<int> bIndexes = kmp(s, b);

  if (aIndexes.empty() || bIndexes.empty()) return {};

  vector<int> answer;
  for (int i = 0, j = 0; i < aIndexes.size(); i++) {
    while (j < bIndexes.size() && aIndexes[i] > bIndexes[j] &&
            abs(aIndexes[i] - bIndexes[j]) > k) {
      j++;
    }

    if (j == bIndexes.size()) break;

    if (abs(aIndexes[i] - bIndexes[j]) <= k) {
      answer.push_back(aIndexes[i]);
    }
  }
  return answer;
}
```

## 고생한 점
