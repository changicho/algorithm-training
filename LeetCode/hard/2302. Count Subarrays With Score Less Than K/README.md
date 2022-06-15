# 2302. Count Subarrays With Score Less Than K

[링크](https://leetcode.com/problems/count-subarrays-with-score-less-than-k/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

nums의 길이를 N이라 하자.

모든 subArray를 brute force로 탐색할 경우 범위 지정에 O(N^2)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

슬라이딩 윈도우를 이용해 각 index를 끝점으로 하는 subArray의 최대 크기를 구한다. 이 크기를 이용해 정답을 구할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

queue를 사용해 슬라이딩 윈도우를 구현할 경우 O(N)의 공간 복잡도를 사용한다.

투 포인터를 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     236      |    O(N)     |    O(1)     |

각 index를 탐색하며 해당 위치를 끝점으로 하는 subArray의 최대 갯수를 구한다.

이 때 현재 슬라이딩 윈도우의 크기가 X인경우, 윈도우에서 길이 X이하의 subArray들은 모두 조건을 충족함을 알 수 있다.

슬라이딩 윈도우의 판별은 이전에 추가할 때 sum을 갱신하며 이 sum과 크기, K를 이용해 크기를 늘려야 할지 줄여야 할지 판단한다.

따라서 X일 때의 만들 수 있는 경우의 수는 (1 ~ X)까지의 합이 된다.

이를 이용해 각 index마다 큐의 사이즈를 저장하고, 현재 사이즈가 다음 사이즈 이상인 경우 정답에 경우의 수를 더한다.

이 때 현재 사이즈와 이전 사이즈로 경우의 수를 만들 때 중복되는 경우가 있을 수 있으므로 이를 제거한다.

또는 각 index마다의 슬라이딩 윈도우의 크기를 매번 더한다. (이는 슬라이딩 윈도우의 크기는 증가세인경우 계속 1씩 증가하기 때문에 1 ~ X 까지의 합을 이전부터 구하며 더할 수 있다.)

이를 이용해 구현하면 다음과 같다.

```cpp
long long countSubarrays(vector<int>& nums, long long k) {
  int size = nums.size();

  long long ret = 0;
  long long sum = 0;
  for (int left = 0, right = 0; right < size; right++) {
    sum += nums[right];

    while (left <= right && sum * (right - left + 1) >= k) {
      sum -= nums[left];
      left++;
    }

    ret += (right - left + 1);
  }

  return ret;
}
```

## 고생한 점
