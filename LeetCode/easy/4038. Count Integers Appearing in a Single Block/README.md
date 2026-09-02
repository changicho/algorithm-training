# 4038. Count Integers Appearing in a Single Block

[링크](https://leetcode.com/problems/count-integers-appearing-in-a-single-block/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N, 값의 범위를 M이라 하자.

각 연속된 구간을 압축하고 각 값마다의 빈도를 셀 수 있다. 이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

갯수를 저장할 공간을 생성하는데 O(M)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(M)     |

연속된 구간을 압축해 갯수를 센다. 해당 갯수가 처음 1개일 때는 정답의 후보가 되므로 정답을 증가시킨다.

만약 2개 이상으로 증가한 경우 정답이 아니므로 정답을 감소시킨다.

이 때 맨 마지막 값은 문제 조건 범위를 초과한 값을 넣어 비교문을 단순화한다.

```cpp
int countSpecialIntegers(vector<int>& nums) {
  int visitedCount[101] = {
      0,
  };

  int before = nums[0];

  nums.push_back(INT_MAX);

  int answer = 0;
  for (int& num : nums) {
    if (before == num) continue;

    visitedCount[before]++;
    if (visitedCount[before] == 1) {
      answer++;
    } else if (visitedCount[before] == 2) {
      answer--;
    }

    before = num;
  }

  return answer;
}
```

## 고생한 점
