# 1891. Cutting Ribbons

[링크](https://leetcode.com/problems/cutting-ribbons/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

ribbon의 수를 N, 리본의 최대 길이를 R이라 하자.

k개의 리본을 만들 수 있는 가장 큰 수를 찾기 위해 해당 길이에 대해서 모든 리본을 순회하며 총 몇개를 만들 수 있는지 조사한다.

이 과정에 O(N)의 시간 복잡도를 사용한다.

정답의 범위를 탐색할 때 모든 경우를 탐색할 경우 (1 ~ R)까지 탐색해야 한다.

이를 이분 탐색을 이용해 탐색할 경우 O(log_2(R))번 탐색해 정답을 찾을 수 있다.

따라서 시간 복잡도는 O(N \* log_2(R))이다.

### 공간 복잡도

이분 탐색을 사용하는 데 상수의 공간 복잡도를 사용한다. 따라서 공간 복잡도는 O(1)이다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     289      | O(N \* log_2(R)) |    O(1)     |

ribbon들을 특정 길이로 잘랐을 때 k개 이상의 조각을 만들 수 있는지 판단하는 여부를 다음과 같이 알 수 있다.

```cpp
bool canMake(vector<int> &ribbons, int length, int k) {
  int count = 0;

  for (int &r : ribbons) {
    count += r / length;
  }

  return count >= k;
}
```

위 함수를 이용해 특점 범위에 대해서 이분 탐색을 진행할 수 있다.

- k개 이상의 조각을 만들 수 있는 경우 : 큰 범위를 탐색
- k개 이상의 조각을 만들 수 없는 경우 : 작은 범위를 탐색

탐색의 범위는 다음과 같다.

- 최소값 : 1
- 최대값 : 가장 긴 리본의 길이

가장 긴 리본의 길이 이상이 주어졌을 때는 한조각도 만들지 못하기 때문이다. (k는 1 이상임이 보장)

이를 이용해 구현하면 다음과 같다.

```cpp
int maxLength(vector<int> &ribbons, int k) {
  int maximum = 0;
  for (int &r : ribbons) {
    maximum = max(r, maximum);
  }

  int answer = 0;

  int left = 1, right = maximum + 1;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (canMake(ribbons, mid, k)) {
      // pick right
      answer = mid;
      left = mid + 1;
    } else {
      // pick left
      right = mid;
    }
  }

  return answer;
}
```

## 고생한 점
