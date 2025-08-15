# E - Trapezium

[링크](https://atcoder.jp/contests/abc418/tasks/abc418_e)

| 난이도 |
| :----: |
|  475   |

## 설계

### 시간 복잡도

좌표의 갯수를 N이라 하자.

각 좌표들 쌍의 기울기를 구해 평행사변형과 마름모의 갯수를 센다.

쌍들을 탐색하는데 O(N^2)의 시간 복잡도를 사용한다.

이후 기울기 쌍 들에서 같은 갯수를 세는데 정렬을 사용할 경우 O(N^2 \* log_2(N^2))의 시간 복잡도를 사용한다.

이는 로그의 법칙에 의해 O(N^2 \* log_2(N))이다.

hash map을 사용할 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

기울기 쌍을 저장하는데 O(N^2)의 공간 복잡도를 사용한다.

정렬, hash map에도 동일하게 O(N^2)의 공간 복잡도를 사용한다.

### 기울기 쌍

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도 |
| :----------: | :----------------: | :---------: |
|     580      | O(N^2 \* log_2(N)) |   O(N^2)    |

각 좌표들에 대해서 모든 좌표 쌍의 기울기들을 구한다.

이후 각 기울기 데이터를 이용해 평행 사변형과 마름모의 갯수를 센다.

(기울기를 벡터라 생각한다.)

여기서 기울기 데이터가 같으나 표현이 다를 수 있으므로 정리를 해야한다.

- 수직, 수평인 경우 남은 값의 부호를 양수로 통일
- y축 diff와 x축 diff의 부호의 곱을 통일

평행 사변형의 갯수는 다음과 같이 구할 수 있다.

- 기울기의 방향이 같은 갯수를 센다.
- 해당 쌍 중에서 2개를 선택한다.
- 평행 사변형을 구할 때 벡터의 방향만 중요하므로 gcd를 이용해 기울기를 통일시킨다.

마름모의 경우 벡터의 크기까지 고려하면 된다.

- 기울기의 방향과 크기가 같은 갯수를 센다.
- 해당 쌍 중에서 2개를 선택한다.


이를 이용해 평행 사변형의 갯수 - 마름모의 갯수 / 2 를 구한다.

마름모의 갯수는 하나의 변에 대해서 중복해서 카운트 되므로 나누기 2를 수행한다.

```cpp
struct Axis {
  int y, x;

  bool operator<(const Axis &b) const {
    if (y != b.y) return y < b.y;
    return x < b.x;
  }

  bool operator==(const Axis &b) const { return y == b.y && x == b.x; }
};

Axis getGradient(Axis &a, Axis &b) {
  int dy = b.y - a.y;
  int dx = b.x - a.x;

  // make dy positive
  if (dy < 0) {
    dy *= -1;
    dx *= -1;
  }

  if (dy == 0 && dx == 0) {
    return {0, 0};
  }
  if (dy == 0) {
    return {0, abs(dx)};
  }
  if (dx == 0) {
    return {abs(dy), 0};
  }
  return {dy, dx};
}

Axis divByGCD(Axis &p) {
  if (p.y == 0) {
    return {0, 1};
  }
  if (p.x == 0) {
    return {1, 0};
  }

  int g = gcd(abs(p.y), abs(p.x));
  return {p.y / g, p.x / g};
}

int count(vector<Axis> &points) {
  int size = points.size();
  sort(points.begin(), points.end());
  int ret = 0;

  int index = 0;
  while (index < size) {
    Axis target = points[index];

    int count = 0;
    while (index < size && points[index] == target) {
      count++;
      index++;
    }

    ret += (count - 1) * count / 2;
  }
  return ret;
}

auto solution(int size, vector<Axis> &points) {
  long long answer = 0;

  vector<Axis> originalGradients;
  vector<Axis> normalizedGradients;

  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      Axis gradient = getGradient(points[i], points[j]);

      originalGradients.push_back(gradient);
      normalizedGradients.push_back(divByGCD(gradient));
    }
  }

  return count(normalizedGradients) - count(originalGradients) / 2;
}
```

### 기울기 쌍 (hash map)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     1819     |   O(N^2)    |   O(N^2)    |

추가로 count하는 부분을 hash map을 사용해 구현할 수 있다 (O(N^2)의 시간 복잡도를 사용)

```cpp
struct Axis {
  int y, x;

  bool operator<(const Axis &b) const {
    if (y != b.y) return y < b.y;
    return x < b.x;
  }

  bool operator==(const Axis &b) const { return y == b.y && x == b.x; }

  long long hash() const { return static_cast<long long>(y) * 1e8 + x; }
};

int count(vector<Axis> &points) {
  int ret = 0;
  unordered_map<long long, int> gradientCount;
  for (Axis &p : points) {
    gradientCount[p.hash()]++;
  }

  for (const auto &[hash, count] : gradientCount) {
    ret += count * (count - 1) / 2;
  }

  return ret;
}
```

## 고생한 점
