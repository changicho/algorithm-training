# 945. Minimum Increment to Make Array Unique

[링크](https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자. 각 수의 최대값을 M이라 하자.

각 수를 작은순으로 순회하며 중복된 수를 증가시키는 방법을 사용할 수 있다.

이를 위해 카운팅 정렬을 수행할 경우 O(N + M)의 시간 복잡도가 소요된다.

### 공간 복잡도

카운팅 정렬에 O(M)의 공간 복잡도가 필요하다.

### 카운팅 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      92      |  O(N + M)   |    O(M)     |

nums의 각 수를 count한다.

이후 현재 수가 중복된 경우, 1개의 숫자만 남긴 뒤 해당 숫자들을 모두 다음 숫자로 이동시킨다.

이 때 이동하는 숫자의 갯수만큼 cost가 증가한다.

최대값까지 순회하며 최대값의 갯수가 1개 초과인 경우 남은 숫자들을 중복되지 않게 이동시키는 횟수는 다음과 같다.

- 남은 수의 갯수 X라 할 때
- X(X-1)/2 만큼의 cost가 증가한다.

이를 구현하면 다음과 같다.

```cpp
int minIncrementForUnique(vector<int>& nums) {
  int counts[100002] = {
      0,
  };
  for (int& num : nums) {
    counts[num]++;
  }

  int answer = 0;
  for (int num = 0; num <= 1e5; num++) {
    if (counts[num] > 1) {
      int move = counts[num] - 1;
      answer += move;
      counts[num + 1] += move;
      counts[num] = 1;
    }
  }
  if (counts[100001] > 0) {
    int num = counts[100001];

    answer += (num) * (num - 1) / 2;
  }

  return answer;
}
```

## 고생한 점
