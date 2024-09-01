# 3265. Count Almost Equal Pairs I

[링크](https://leetcode.com/problems/count-almost-equal-pairs-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 배열 nums의 크기를 N이라 하자.

nums의 최대값은 10^6 이다.

두 수가 거의 같은지 판단하는데 O(1)의 시간 복잡도를 사용한다.

이를 모든 수 쌍에 대해 판단할 경우 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

입력받은 두 수를 비교하는 데 O(log_10(10^6))의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     164      |   O(N^2)    |    O(1)     |

두 수가 거의 같은지 다음과 같이 비교할 수 있다.

각 수의 자리수를 비교하며 다른 자리수의 갯수가 2개 이하이며 해당 숫자가 포함하는 숫자들이 같은지 비교한다.

위를 만족하는 경우 거의 같다.

nums의 각 수 쌍에 대해 위를 판별하며, 만족하는 경우 count를 증가시킨다.

```cpp
bool isEqual(int a, int b) {
  if (a == b) return true;

  string aCount = string(10, 0), bCount = string(10, 0);

  int diff = 0;
  while (a > 0 || b > 0) {
    int curA = a % 10, curB = b % 10;
    if (curA != curB) diff++;
    aCount[curA]++;
    bCount[curB]++;
    a /= 10;
    b /= 10;
  }

  if (diff <= 2 && aCount == bCount) return true;

  return false;
}

int countPairs(vector<int>& nums) {
  int size = nums.size();
  int answer = 0;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < i; j++) {
      if (isEqual(nums[i], nums[j])) {
        answer++;
      }
    }
  }
  return answer;
}
```

## 고생한 점
