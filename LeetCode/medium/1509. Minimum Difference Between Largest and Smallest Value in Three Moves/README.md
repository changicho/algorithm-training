# 1509. Minimum Difference Between Largest and Smallest Value in Three Moves

[링크](https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 원소의 갯수를 N이라 하자.

원소를 정렬할 경우 순서대로 큰값들을 찾을 수 있다. 이에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

총 3개의 값을 변경할 수 있으며, 이는 큰값, 작은값 들중 어느 값들을 변경시킬지에 따라서 정답을 구할 수 있다.

정답은 총 4가지 경우중 하나 이므로 탐색에 O(4)의 시간 복잡도를 사용한다.

따라서 시간 복잡도는 O(N)이다.

혹은 정렬하지 않고 가장 큰, 가장 작은 값들을 4개씩 골라 정답을 찾을 수 있다.

이 경우 총 시간 복잡도는 O(N)이다.

### 공간 복잡도

입력받은 nums배열 자체로 정렬할 경우 정렬된 배열에 따로 공간복잡도를 사용하지 않는다.

변경하지 않고 유지할 값들을 저장하는 데 슬라이딩 윈도우를 사용할 경우 O(N)의 공간 복잡도를 사용한다.

그 외에 직접 4가지 경우를 탐색할 경우 O(1)의 공간 복잡도를 사용한다.

### 정렬 & 슬라이딩 윈도우

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     100      | O(N \* log_2(N)) |    O(N)     |

모든 값의 차이가 가장 적어지는 경우는 모든 값이 같은 경우이다.

따라서 원소의 갯수가 4개 이하인 경우는 모든 원소를 같은 값으로 변경할 수 있다.

그 외의 경우 정답은 다음과 같은 경우이다.

- size - 3 크기의 연속된 subArray중 맨 앞 값과 맨 뒷 값의 차이.

즉 이는 size - 3 크기의 subArray를 만들고 나머지 값들은 모두 같은 값으로 변경하는것을 의미한다.

이 때 작은값, 큰값들 중에서 변경하는 이유는 배열의 range를 결정하는 값들이기 때문이다.

subArray에서 가장 큰 값과 가장 작은 값을 빠르게 찾기 위해 정렬을 사용한다.

이후 슬라이딩 윈도우를 이용해 subArray를 갱신하며 정답을 찾는다.

```cpp
int minDifference(vector<int>& nums) {
  int size = nums.size();
  int last = size - 1;
  if (size <= 4) return 0;

  sort(nums.begin(), nums.end());

  int answer = nums.back() - nums.front();
  deque<int> dq;
  for (int i = 0; i < size; i++) {
    dq.push_back(nums[i]);

    if (dq.size() == size - 3) {
      int diff = dq.back() - dq.front();
      answer = min(answer, diff);
      dq.pop_front();
    }
  }

  return answer;
}
```

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     136      | O(N \* log_2(N)) |    O(N)     |

위 슬라이딩 윈도우 방법에서 size - 3 크기의 subArray를 구하는 경우는 다음 4가지 경우이다.

여기서 원소 갯수는 변경할 원소의 갯수를 의미한다.

| left 원소 갯수 | right 원소 갯수 |
| :------------: | :-------------: |
|       0        |        3        |
|       1        |        2        |
|       2        |        1        |
|       3        |        0        |

즉 정렬되어 있으므로, 작은 값들과 큰 값들 중에서 총 3개의 수를 변경하는 방법이다.

이를 구현하면 다음과 같다.

```cpp
int minDifference(vector<int>& nums) {
  int size = nums.size();
  int last = size - 1;
  if (size <= 4) return 0;

  sort(nums.begin(), nums.end());

  int first = nums[last] - nums[3], second = nums[last - 1] - nums[2],
      third = nums[last - 2] - nums[1], fourth = nums[last - 3] - nums[0];

  int answer = min({first, second, third, fourth});
  return answer;
}
```

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      49      |    O(N)     |    O(1)     |

위 정렬 방법에서 필요한 값은 큰 값들 중 4개, 작은 값들 중 4개를 찾는 것이다.

이는 한번의 순회로 찾을 수 있다.

```cpp
int minDifference(vector<int>& nums) {
  int size = nums.size();

  int mins[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
  int maxs[4] = {INT_MIN, INT_MIN, INT_MIN, INT_MIN};

  if (size <= 4) {
    return 0;
  }

  for (int& num : nums) {
    for (int i = 0; i < 4; i++) {
      if (mins[i] >= num) {
        for (int j = 2; j >= i; j--) {
          mins[j + 1] = mins[j];
        }
        mins[i] = num;
        break;
      }
    }
    for (int i = 0; i < 4; i++) {
      if (maxs[i] <= num) {
        for (int j = 2; j >= i; j--) {
          maxs[j + 1] = maxs[j];
        }
        maxs[i] = num;
        break;
      }
    }
  }

  int answer = INT_MAX;
  for (int i = 0; i < 4; i++) {
    int cur = maxs[i] - mins[3 - i];
    answer = min(answer, cur);
  }
  return answer;
}
```

## 고생한 점
