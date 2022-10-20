# 2444. Count Subarrays With Fixed Bounds

[링크](https://leetcode.com/problems/count-subarrays-with-fixed-bounds/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자. 이는 최대 10^5 이다.

모든 subArray를 직접 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다. 이 경우 제한시간 내에 불가능하다.

슬라이딩 윈도우를 이용해 현재 fixed-bound subArray의 갯수를 셀 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 범위의 index만 저장할 경우 O(1)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     263      |    O(N)     |    O(1)     |

왼쪽부터 index를 증가시키며 다음과 같은 fixed-bound subArray의 갯수를 센다.

- index까지 subArray에 추가했을 때 가능한 경우의 갯수

현재 값에 따라 다음과 같은 경우가 존재한다.

- 범위를 벗어나는 경우 : subArray는 0개이다.
- 범위 안의 수지만 경계값은 아닌경우
- 경계값인경우

여기서 경계값인 경우는 마지막에 나타난 경계값의 index를 갱신한다.

범위를 벗어나는 경우 해당 값 이전의 값들은 정답이 불가능하므로 마지막에 나타난 범위를 벗어나는 값의 index를 갱신한다.

경계값이거나, 범위안의 수인 경우 현재 가능한 경우의 수는 다음과 같다.

- min(lastMinIdx, lastMaxIdx) - lastOutIdx

여기서 lastOutIdx값이 lastMinIdx나 lastMaxIdx보다 큰 경우는 가능한 subArray의 갯수가 0개인 경우이다. (subArray안에 범위를 초과하는 숫자가 존재함)

만약 위 값이 양수인 경우 꼭 필요한 범위(lastMinIdx ~ lastMaxIdx) 왼쪽에 있는 값의 갯수만큼 경우의 수를 추가할 수 있다.

해당 subArray는 다음과 같은 구조이다.

```javascript
subArray = [leftPart, essential, rightPart, currentIdx]
```

여기서 leftPart를 구성할 수 있는 경우의 수는 leftPart의 길이 만큼이다.

따라서 leftPart의 길이만큼 정답에 더한다.

```cpp
long long countSubarrays(vector<int>& nums, int minK, int maxK) {
  int size = nums.size();
  long long answer = 0;
  int lastOut = -1, lastMin = -1, lastMax = -1;

  for (int i = 0; i < size; ++i) {
    int num = nums[i];

    if (num < minK || maxK < num) {
      lastOut = i;
      continue;
    }
    if (num == minK) lastMin = i;
    if (num == maxK) lastMax = i;

    long long curLength = min(lastMin, lastMax) - lastOut;
    if (curLength <= 0) continue;
    answer += curLength;
  }

  return answer;
}
```

## 고생한 점
