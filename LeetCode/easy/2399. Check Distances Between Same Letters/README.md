# 2399. Check Distances Between Same Letters

[링크](https://leetcode.com/problems/check-distances-between-same-letters/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

각 문자를 왼쪽부터 순회하며 이전에 방문한 문자의 경우 거리를 젠다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 알파벳별로 방문여부, 거리를 저장해야 한다.

이에 O(1)의 공간 복잡도를 사용한다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

문자를 방문할 때마다 idx를 갱신하고, 만약 이전에 방문했던 문자인 경우 거리를 갱신한다.

이후 계산한 거리와 주어진 거리가 같은지 비교한다.

```cpp
bool checkDistances(string s, vector<int>& distance) {
  vector<int> dist(26, 0);
  vector<int> lastIdx(26, -1);

  for (int i = 0; i < s.length(); i++) {
    if (lastIdx[s[i] - 'a'] == -1) {
      lastIdx[s[i] - 'a'] = i;
      continue;
    }
    dist[s[i] - 'a'] = i - lastIdx[s[i] - 'a'] - 1;
  }

  for (int i = 0; i < 26; i++) {
    if (lastIdx[i] == -1) continue;
    if (dist[i] != distance[i]) return false;
  }
  return true;
}
```

## 고생한 점
