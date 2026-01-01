# 3623. Count Number of Trapezoids I

[링크](https://leetcode.com/problems/count-number-of-trapezoids-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 points의 크기를 N이라 하자.

각 점들을 y축으로 묶은 뒤 해당 그룹마다 평행선을 그리는 경우의 수로 정답을 구한다.

이에 hash map을 사용할 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

hash map에 O(N)의 공간 복잡도가 소요된다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      67      |    O(N)     |    O(N)     |

문제 조건상 평행사변형중 두 변은 y축에 평행하다.

따라서 같은 y좌표를 가지는 점들끼리 묶은 그룹을 만든다. 그 중 하나의 그룹의 점의 수를 X라 하자.

해당 그룹에서 평행선을 그릴 수 있는 경우의 수는 X \* (X - 1) / 2 이다.

이를 이용해 현재 그룹과 다른그룹에서의 평행선의 조합을 구해 정답에 더해준다.

이 때 현재까지 순회한 그룹의 평행선의 갯수를 갱신하며 정답을 구해 중복을 방지한다.

```cpp
int countTrapezoids(vector<vector<int>>& points) {
  const int MOD = 1e9 + 7;
  unordered_map<int, long long> um;

  for (vector<int>& p : points) {
    int x = p[0], y = p[1];

    um[y]++;
  }

  long long answer = 0;
  long long caseSum = 0;
  for (auto& [_, count] : um) {
    long long cur = (count) * (count - 1) / 2;

    answer += cur * caseSum;
    caseSum += cur;
  }

  return answer % MOD;
}
```

## 고생한 점
