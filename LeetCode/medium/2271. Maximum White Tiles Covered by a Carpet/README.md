# 2271. Maximum White Tiles Covered by a Carpet

[링크](https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

tiles의 크기를 N이라 하자.

우선 tiles는 겹치지 않으므로, 시작점에 대해 오름차순으로 정렬할 경우 순서대로 방문할 수 있다.

이 정렬에 O(N * log_2(N))의 시간 복잡도를 사용한다.

슬라이딩 윈도우를 이용할 경우 O(N)의 시간 복잡도를 사용한다.

prefix sum과 이분 탐색을 사용할 경우 O(N * log_2(N))의 시간 복잡도를 사용한다.

따라서 두 방법 모두 O(N * log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

슬라이딩 윈도우를 이용할 경우 index, sum만 변화시키며 탐색할 수 있다.

이 경우 O(1)의 공간 복잡도를 사용한다.

prefix sum & 이분 탐색을 이용할 경우 O(N)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|     371      | O(N * log_2(N)) |    O(1)     |

tiles는 범위가 겹치지 않으므로 시작점에 대해 오름차순으로 정렬할 경우, 순서대로 방문이 가능하다.

정답이 될 수 있는 후보는 각 시작점에서 부터 카펫을 깔았을 때 덮는 타일의 갯수 이므로 각 시작점들에 대해서 타일을 덮는 갯수를 센다.

각 시작점에 대해서 매번 타일의 갯수를 구할 경우 O(N^2)의 시간 복잡도를 사용한다.

따라서 슬라이딩 윈도우를 이용해 매번 구하지 않고 모든 순회에서 O(N)의 시간 복잡도를 이용해 정답을 구한다.

현재 경우는 다음 2가지 경우일것이다.

- 맨 마지막 타일 범위가 카펫을 초과하는 경우 : 초과하는 부분은 제거함
- 맨 마지막 타일 범위가 카펫에 포함되는 경우

순회하며 정답을 갱신한다.

```cpp
int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
  int size = tiles.size();
  sort(tiles.begin(), tiles.end());

  int maximum = 0;
  int sum = 0;

  int left = 0, right = 0;
  while (maximum < carpetLen && right < size) {
    if (left == right || tiles[right][1] < tiles[left][0] + carpetLen) {
      sum += min(carpetLen, tiles[right][1] - tiles[right][0] + 1);
      maximum = max(maximum, sum);

      right++;
    } else {
      int partial = max(0, tiles[left][0] + carpetLen - tiles[right][0]);
      maximum = max(maximum, sum + partial);
      sum -= (tiles[left][1] - tiles[left][0] + 1);

      left++;
    }
  }

  return maximum;
}
```

### prefix sum & 이분 탐색

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|     370      | O(N * log_2(N)) |    O(N)     |

타일을 정렬 후 i번째 타일을 시작점으로 설정하고 포함되는 최대 타일까지 찾는다.

이후 마지막 타일이 범위를 넘어서는 경우 이를 제거한다.

여기서 i ~ j번째 타일들의 합을 빠르게 구하기 위해 prefix sum을 구한다.

```cpp
int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
  sort(tiles.begin(), tiles.end());
  int size = tiles.size();

  vector<int> prefix(size + 1, 0), ends(size, 0);

  for (int i = 0; i < size; i++) {
    prefix[i + 1] = prefix[i] + (tiles[i][1] - tiles[i][0] + 1);
    ends[i] = tiles[i][1];
  }

  int maximum = 0;
  for (int i = 0; i < size; i++) {
    int left = tiles[i][0];
    int right = left + carpetLen - 1;

    int idx = upper_bound(ends.begin(), ends.end(), right) - ends.begin();
    int curSum = prefix[idx] - prefix[i];

    if (idx < size && tiles[idx][0] <= right) {
      curSum += right - tiles[idx][0] + 1;
    }

    maximum = max(maximum, curSum);
  }
  return maximum;
}
```

## 고생한 점

풀이는 생각났으나 구현이 어려웠다. sliding window의 경우 구현방법을 몇가지 더 알아놔야겠다.