# 1578. Minimum Time to Make Rope Colorful

[링크](https://leetcode.com/problems/minimum-time-to-make-rope-colorful/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

로프의 길이를 N이라 하자.

색이 같은 연속된 구간에서 cost가 가장 높은 풍선을 하나만 남기고 나머지를 삭제하는 경우가 총 cost의 합을 최소로 만드는 경우이다.

이를 순회하며 찾을 수 있다. 이 경우 순회에 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     113      |    O(N)     |    O(1)     |

각 같은 풍선 색이 연속된 구간마다 cost가 낮은 풍선들을 삭제하고 하나의 풍선만 남긴다.

이를 위해 순회하며 이전 풍선과 현재 풍선의 색이 같은 경우 이 중 cost가 낮은 쪽을 남긴다.

```cpp
int minCost(string colors, vector<int>& neededTime) {
  int size = colors.size();

  char beforeC = colors[0];
  int beforeT = neededTime[0];

  int answer = 0;
  for (int i = 1; i < size; i++) {
    char c = colors[i];
    int time = neededTime[i];

    if (beforeC != c) {
      beforeC = c;
      beforeT = time;
      continue;
    }

    if (beforeT < time) {
      answer += beforeT;
      beforeT = time;
    } else {
      answer += time;
    }
  }

  return answer;
}
```

## 고생한 점
