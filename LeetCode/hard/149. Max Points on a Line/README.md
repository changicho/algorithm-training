# 149. Max Points on a Line

[링크](https://leetcode.com/problems/max-points-on-a-line/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

좌표의 개수를 N이라 하자.

하나의 좌표에서 다른 모든 좌표들의 기울기를 비교하며 같은 기울기의 최대 개수를 비교해 풀이할 수 있다.

이 경우 좌표에서 좌표로 탐색에 O(N^2)의 시간 복잡도가 소요되며, 같은 기울기끼리 hash map을 이용해 묶을 경우 내부적으로 O(1)의 시간 복잡도를 사용한다.

따라서 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

좌표마다 기울기를 저장하는 데 O(N)의 공간 복잡도를 사용한다.

### 기울기 계산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      33      |   O(N^2)    |    O(N)     |

하나의 좌표에서 다음 좌표까지의 기울기는 다음과 같다.

```cpp
Axis a, b;
int gradient = (a.y - b.y) / (a.x - b.x);
```

이 기울기를 double로 선언하고 풀이할 경우 부동소수점 연산에 의하여 다른 기르기를 계산했을 때 같은 값이 나오는 문제가 발생한다.

```javascript
// double error case
[
  [0, 0],
  [5151, 5150],
  [5152, 5151],
];
```

따라서 나눈 값을 직접 사용하지 않고 xDiff, yDiff값으로 조합한 string을 기울기로 사용한다.

이 때 같은 기울기여도 값의 크기의 차이가 있을 수 있기 때문에 각 y, x기울기를 gcd로 나눠준다.

이를 이용해 하나의 좌표에서 다른 모든 좌표까지 기울기들을 구하고, 같은 기울기끼리 묶어 가장 개수가 많은 것을 정답으로 갱신한다.

```cpp
string getGradient(vector<int>& a, vector<int>& b) {
  int yDiff = a[0] - b[0];
  int xDiff = a[1] - b[1];

  int divisor = gcd(yDiff, xDiff);
  yDiff /= divisor;
  xDiff /= divisor;

  return to_string(yDiff) + "/" + to_string(xDiff);
}

int maxPoints(vector<vector<int>>& points) {
  int size = points.size();
  int answer = 1;

  for (vector<int>& from : points) {
    unordered_map<string, int> um;

    for (vector<int>& to : points) {
      if (from[0] == to[0] && from[1] == to[1]) continue;

      string gradient = getGradient(from, to);

      um[gradient] += 1;

      answer = max(answer, um[gradient] + 1);
    }
  }

  return answer;
}
```

## 고생한 점
