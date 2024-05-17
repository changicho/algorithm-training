# E - Jump Distance Sum

[링크](https://atcoder.jp/contests/abc351/tasks/abc351_e)

| 난이도 |
| :----: |
|  500   |

## 설계

### 시간 복잡도

입력받은 점들의 크기를 N이라 하자.

모든 경우를 계산할 경우 O(N^2)의 시간 복잡도가 필요하다.

각 점들의 좌표를 분리하고 각각 계산해 이동 가능한 거리를 O(N)의 시간 복잡도로 구할 수 있다.

이 때 직선이동이 아닌 대각선 이동이므로 각 점들을 모두 회전시키고 이동 가능한 거리를 구해야 한다.

이에 총 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 점들을 회전시킨 좌표를 저장해야 하므로 O(N)의 공간 복잡도가 필요하다.

### 오일러 각 회전 & 모든 쌍의 합

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      50      |    O(N)     |    O(N)     |

각 좌표들을 대각선 이동하게 된다. 이 때 어떤 점들은 아무리 이동해도 만나지 못하게 된다.

각 점들을 만날 수 있는 점들끼리 아래와 같이 분류할 수 있다.

- x + y 가 홀수
- x + y 가 짝수

이 때 직선이동으로 맞춰줘야 하므로 각 점들을 오일러 각 회전을 이용해 회전시켜 점들마다 새로운 좌표를 구한다.

각 점들을 분류 한 뒤 각 점들의 변형된 x',y'좌표를 분리해 각 좌표들의 모든 쌍의 거리의 합을 구할 수 있다.

이 때 변형에 사용한 보정치만큼 합을 보정해준다.

```cpp
struct Axis {
  long long y, x;
};

long long getDist(vector<long long> &nums) {
  int MOVE_DIST = 2;
  int size = nums.size();
  sort(nums.begin(), nums.end());

  long long sum = accumulate(nums.begin(), nums.end(), 0LL);

  long long ret = 0;
  for (int i = 0; i < size; i++) {
    ret += (sum - nums[i] * (size - i));
    sum -= nums[i];
  }
  return ret / MOVE_DIST;
}

long long solution(int size, vector<Axis> &positions) {
  vector<long long> firstY, firstX, secondY, secondX;

  for (Axis &p : positions) {
    // rotate 45 degree
    // use euler's formula
    // y' = x sin(45) + y cos(45)
    // x' = x cos(45) - y sin(45)
    // cos(45) = sin(45) = 1 / sqrt(2)
    // so use euler's formula and multiply sqrt(2)
    // p = (x + y, x - y)
    Axis converted = {p.x + p.y, p.x - p.y};

    if ((p.y + p.x) % 2 == 0) {
      firstY.push_back(converted.y);
      firstX.push_back(converted.x);
    } else {
      secondY.push_back(converted.y);
      secondX.push_back(converted.x);
    }
  }

  long long answer = 0;
  answer += getDist(firstY);
  answer += getDist(firstX);
  answer += getDist(secondY);
  answer += getDist(secondX);

  return answer;
}
```

## 고생한 점
