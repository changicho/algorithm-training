# 2393. Count Strictly Increasing Subarrays

[링크](https://leetcode.com/problems/count-strictly-increasing-subarrays/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이다. 이는 제한시간 내에 불가능하다.

한번 순회하며 최대 길이의 연속된 증가하는 subArray를 찾는다고 하자.

가장 긴 subArray의 길이를 이용해 해당 subArray의 부분 배열의 개수를 구할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회하며 갯수와 직전값만 저장할 경우 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     113      |    O(N)     |    O(1)     |

연속되게 증가하는 subArray의 길이를 x라 하자.

해당 subArray에서 찾을 수 있는 부분 증가 배열의 수는 다음과 같다.

- x * (x+1) / 2

이는 길이가 1 ~ x까지인 부분 배열이 존재하며 가능한 모든 경우를 더하기 때문이다.

따라서 순회를 이용해 가장 긴 부분 증가 배열을 찾고 해당 길이를 이용해 정답에 더한다.

```cpp
long long calculate(int size) { return ((long long)size) * (size + 1) / 2; }

long long countSubarrays(vector<int>& nums) {
  int size = nums.size();
  long long answer = 0;

  int before = 0;
  int count = 0;
  for (int& num : nums) {
    if (before >= num) {
      answer += calculate(count);
      count = 0;
      before = 0;
    }

    count++;
    before = num;
  }

  answer += calculate(count);
  return answer;
}
```

## 고생한 점
