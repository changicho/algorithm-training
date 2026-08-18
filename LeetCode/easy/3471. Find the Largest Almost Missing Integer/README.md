# 3471. Find the Largest Almost Missing Integer

[링크](https://leetcode.com/problems/find-the-largest-almost-missing-integer/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N, 입력받은 수를 K, 원소의 최대값을 M이라 하자.

완전 탐색을 수행할 경우 O(N \* K + M)의 시간 복잡도를 사용한다.

한번의 순회로 정답을 구할 경우 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 경우마다 숫자의 갯수를 세야하므로 O(M)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |    O(M)     |

K의 경우에 따라 다음과 같이 나눌 수 있다.

- K = 1 : 1개만 존재하는 제일 큰 값이 정답
- K = N : 제일 큰 값이 정답
- K = 2 ~ (N-1) : 시작과 끝 값중 1개만 존재하는 값

K의 크기가 2이상 (N-1)이하인 경우 한번만 존재할 수 있는 값은 양 끝값밖에 없다.

배열을 순회하며 값을 count한다.

이후 각 경우마다 정답을 구한다.

```cpp
int largestInteger(vector<int>& nums, int k) {
  int size = nums.size();
  int maximum = nums[0];
  int count[51] = {0};
  for (int& num : nums) {
    count[num]++;
    maximum = max(maximum, num);
  }

  if (k == size) {
    return maximum;
  }
  if (k == 1) {
    for (int num = 50; num >= 0; num--) {
      if (count[num] == 1) {
        return num;
      }
    }
    return -1;
  }
  int answer = -1;
  if (count[nums[0]] == 1) {
    answer = max(answer, nums[0]);
  }
  if (count[nums.back()] == 1) {
    answer = max(answer, nums.back());
  }
  return answer;
}
```

## 고생한 점
