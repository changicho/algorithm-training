# 997. Find the Town Judge

[링크](https://leetcode.com/problems/find-the-town-judge/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 인원의 수를 N, 각자 신뢰하는 방향의 크기를 M이라 하자.

각자 신뢰를 순회하며 inBound와 outBound의 수를 센다.

이 경우 O(M)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 인원에 대한 inBound, outBound를 관리할 경우 O(N)의 공간 복잡도를 사용한다.

### count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     197      |    O(M)     |    O(N)     |

judge는 모두가 신뢰하며 아무도 신뢰하지 않는다.

각자 신뢰하는 인원을 count하며, 특정 인원의 신뢰가 N-1인 경우 (자신 제외) 해당 인원이 judge가 될 수 있다.

이 때 judge는 아무도 신뢰하면 안되므로 특정인원이 다른인원을 신뢰하는 수 또한 count한다.

```cpp
int findJudge(int n, vector<vector<int>>& trust) {
  vector<int> counts(n + 1, 0);
  vector<bool> trustSomeones(n + 1, false);

  for (vector<int>& t : trust) {
    int from = t[0], to = t[1];
    trustSomeones[from] = true;
    counts[to]++;
  }

  int answer = -1;
  for (int i = 1; i <= n; i++) {
    if (counts[i] == n - 1 && trustSomeones[i] == false) {
      if (answer != -1) return -1;
      answer = i;
    }
  }
  return answer;
}
```

## 고생한 점
