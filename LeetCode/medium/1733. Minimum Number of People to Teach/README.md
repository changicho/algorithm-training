# 1733. Minimum Number of People to Teach

[링크](https://leetcode.com/problems/minimum-number-of-people-to-teach/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

사람의 수를 N, 총 언어의 수를 M, 연결의 수를 E라 하자.

각 연결에서 서로 언어가 겹치는지 판단하는데 O(E + M)의 시간 복잡도를 사용한다.

각 과정에서 서로 언어가 통하지 않는 사람들에게 특정 언어를 가르치는 방법을 사용할 수 있다.

이 경우 언어가 통하지 않는 사람을 저장하는데 hash set에 총 O(N)의 시간 복잡도를 사용한다.

이후 이를 순회하며 언어를 가르치는 경우 O(N + M)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N + M + E)가 된다.

### 공간 복잡도

hash set에 사람을 저장하는데 O(N)의 공간 복잡도를 사용한다.

각 언어의 갯수를저장하는데 O(M)의 공간 복잡도를 사용한다.

### 탐욕 알고리즘 & hash set

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|     246      | O(N + M + E) |  O(N + M)   |

```cpp
int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships) {
  unordered_set<int> needs;

  for (vector<int> &e : friendships) {
    int a = e[0] - 1, b = e[1] - 1;

    bool hasSame = false;
    unordered_set<int> visited;
    for (int &l : languages[a]) {
      visited.insert(l);
    }
    for (int &l : languages[b]) {
      if (visited.count(l)) {
        hasSame = true;
        break;
      }
    }
    if (!hasSame) {
      needs.insert(a);
      needs.insert(b);
    }
  }

  int maxCount = 0;
  vector<int> count(n + 1, 0);
  for (int p : needs) {
    for (int &l : languages[p]) {
      count[l]++;
      maxCount = max(maxCount, count[l]);
    }
  }
  return needs.size() - maxCount;
}
```

## 고생한 점
