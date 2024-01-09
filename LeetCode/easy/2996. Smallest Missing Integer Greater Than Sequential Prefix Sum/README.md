# 2996. Smallest Missing Integer Greater Than Sequential Prefix Sum

[링크](https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

가장 긴 prefix를 구하는 데 O(N)의 시간 복잡도를 사용한다. 이후 해당 prefix이상의 배열에 없는 가장 작은 수를 구한다.

이는 최대 N이하의 값이므로 이에 O(N)의 시간 복잡도를 사용한다.

각 수가 배열에 존재하는지 판단하는데 별도 visited 배열을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

visited 배열에 O(N)의 공간 복잡도를 사용한다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

첫번째 숫자부터 시작하는 1씩 증가하는 가장 긴 prefix를 구한다.

이후 해당 prefix이상의 배열에 없는 가장 작은 수를 구한다.

이 때 배열의 숫자는 최대 50까지이므로 prefix부터 50까지 직접 순회한다.

만약 모든 수가 배열에 존재하는 경우 배열에 존재할 수 없는 가장 작은 수인 51이 정답이다.

```cpp
int missingInteger(vector<int>& nums) {
  int size = nums.size();

  int visited[51] = {
      0,
  };
  for (int& num : nums) {
    visited[num] = true;
  }

  int prefix = nums[0];
  for (int j = 1; j < size; j++) {
    if (nums[j] - nums[j - 1] == 1) {
      prefix += nums[j];
    } else {
      break;
    }
  }

  int answer = prefix;
  while (answer <= 50 && visited[answer]) {
    answer++;
  }
  return answer;
}
```

## 고생한 점
