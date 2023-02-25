# 2562. Find the Array Concatenation Value

[링크](https://leetcode.com/problems/find-the-array-concatenation-value/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자. (N <= 1,000)

nums의 각 숫자의 범위는 0 ~ 10^4 이다.

시뮬레이션을 이용해 각 경우마다 맨 앞과 맨 뒤의 수를 변환해 정답에 더할 경우 순회에 O(N), 숫자 변환에 최대 O(8)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N)이다.

### 공간 복잡도

별도의 문자열을 이용해 수를 변환할 경우 O(8)의 공간 복잡도를 사용한다.

투 포인터를 이용해 양 끝값에 접근할 경우 O(1)의 공간 복잡도를 사용한다.

### 시뮬레이션 & 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |    O(N)     |    O(1)     |

투 포인터를 이용해 양 끝 값에 접근하며, 각 값을 변환해 정답에 더한다.

```cpp
long long convert(int a, int b) {
  string str = to_string(a) + to_string(b);

  return stoll(str);
}

long long findTheArrayConcVal(vector<int>& nums) {
  long long answer = 0;

  int left = 0, right = nums.size() - 1;

  while (left < right) {
    answer += convert(nums[left], nums[right]);
    left++;
    right--;
  }

  if (left == right) {
    answer += nums[left];
  }
  return answer;
}
```

## 고생한 점
