# D - Line Crossing

[링크](https://atcoder.jp/contests/abc402/tasks/abc402_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

좌표의 수를 N, 선의 수를 M이라 하자.

각 선을 순회하며 각 선마다 기울기를 구할 수 있다.

이에 O(M)의 시간 복잡도를 사용한다.

이후 해당 기울기가 같은 선을 제외한 나머지 선의 갯수를 정답에 추가해 교차하는 경우를 모두 구할 수 있다.

이에 O(M)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 기울기를 저장하는데 O(M)의 공간 복잡도를 사용한다.

### 기울기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      66      |    O(M)     |    O(M)     |

각 선들마다 기울기가 같은 선들은 평행하므로 절대 마주치지 않는다.

따라서 각 선들마다 기울기를 구하며, 각 선에 대해 기울기가 같은 선을 제외한 나머지 선의 갯수를 정답에 추가한다.

이후 중복된 수를 빼야 하므로 나누기 2를 해준다.

각 선마다 기울기를 구하는 방법은 선마다 시작점, 끝점의 index를 더한 값을 N으로 나눈 값이 된다.

```cpp
long long solution(int n, vector<pair<int, int>> &lines) {
  long long answer = 0;
  long long size = lines.size();

  unordered_map<int, long long> um;

  for (pair<int, int> &line : lines) {
    int left = line.first, right = line.second;

    long long diff = (left + right) % n;

    um[diff]++;
  }

  for (pair<int, int> &line : lines) {
    int left = line.first, right = line.second;

    long long diff = (left + right) % n;

    answer += size - um[diff];
  }

  return answer / 2;
}
```

## 고생한 점
