# 43236. 징검다리

[링크](https://programmers.co.kr/learn/courses/30/lessons/)

| 난이도 |
| :----: |
|  lv4   |

## 설계

### 시간 복잡도

바위의 갯수를 M, 입력받은 숫자를 N, 도착점까지 거리를 D라고 하자.

N개의 바위를 부시고 각 바위마다 거리를 구할 경우 바위를 부시는 경우의 수는 combination(M, N)이 되며 이는 매우 큰 숫자이다.

각 바위를 부시고 최소길이를 구하기 위해 다음과 같이 생각한다.

"N개의 돌을 없애서 돌 사이 거리의 최솟값이 X로 만들 수 있는지"

이 경우 주어진 X에 대해서 바위의 위치들을 오름차순으로 순회하며 판단할 수 있다.

이 경우 정렬에 O(M * log_2(M)), 순회에 O(M)의 시간 복잡도를 사용한다.

X의 범위는 D까지이므로 이를 이분탐색해 풀이할 경우 O(log_2(D))이다.

따라서 총 시간 복잡도는 O(M * (log_2(M) + log_2(D))) 이다.

### 공간 복잡도

각 바위마다의 거리의 차이를 별도로 저장해 사용할 경우 O(M)의 공간 복잡도를 사용한다.

### 이분 탐색

주어진 바위를 오름차순으로 정렬하고 시작점 0과 도착점 D를 추가한 뒤 각 거리들마다의 차이를 구한다.

그리고 minimum distance가 X일 때 몇개의 바위를 부셔야하는 바위의 갯수를 센다.

이는 X를 설정했을 때 N개 이하의 바위를 부수고 만들 수 있는지를 판단하기 위함이다.

따라서 판별식은 다음과 같다.

```cpp
// get crush count to make all distance lower than minimum dist
int getCrush(vector<int> &diffs, int minDist) {
  int crush = 0;

  int curDist = 0;
  for (int &diff : diffs) {
    curDist += diff;

    if (curDist < minDist) {
      // can ignore current rock so crush it
      crush++;
    } else {
      curDist = 0;
    }
  }

  return crush;
}
```

이를 이용해 주어진 범위에 대해서 이분탐색으로 풀이한다.

```cpp
int solution(int distance, vector<int> rocks, int n) {
  int answer = distance;

  rocks.push_back(0);
  rocks.push_back(distance);
  sort(rocks.begin(), rocks.end());

  vector<int> diffs;
  for (int i = 0; i < rocks.size() - 1; i++) {
    diffs.push_back(rocks[i + 1] - rocks[i]);
  }

  int left = 0, right = distance + 1;

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (getCrush(diffs, mid) <= n) {
      answer = mid;

      // move right
      left = mid + 1;
    } else {
      // move left
      right = mid;
    }
  }

  return answer;
}
```

## 고생한 점
