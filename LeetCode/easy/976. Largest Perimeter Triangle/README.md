# 976. Largest Perimeter Triangle

[링크](https://leetcode.com/problems/largest-perimeter-triangle/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

정렬을 이용해 매번 가장 큰 숫자 3개를 고른다.

이에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      4       | O(N \* log_2(N)) |    O(N)     |

삼각형을 이루는 세 변의 길이를 각각 a, b, c (a <= b <= c)라고 하자.

삼각형이 존재하기 위한 조건은 a + b > c이다.

배열의 원소를 정렬 후 3개의 연이은 수를 탐색하며 정답 조건을 만족하는 경우 정답을 반환한다.

이는 큰 수부터 역순으로 탐색할 경우 먼저 방문한 정답의 후보가 가장 유리하기 때문이다.

```cpp
int largestPerimeter(vector<int>& nums) {
  int size = nums.size();

  sort(nums.begin(), nums.end(), greater<int>());

  int answer = 0;

  for (int i = 0; i < size - 2; i++) {
    int a = nums[i], b = nums[i + 1], c = nums[i + 2];

    if (a < b + c) {
      return a + b + c;
    }
  }

  return 0;
}
```

## 고생한 점
