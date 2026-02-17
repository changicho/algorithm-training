# 3719. Longest Balanced Subarray I

[링크](https://leetcode.com/problems/longest-balanced-subarray-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자. 원소의 가장 큰 값을 M이라 하자.

완전 탐색을 이용해 모든 부분 배열을 확인한다.

이에 O(N^2)의 시간 복잡도를 사용한다.

이 때 각 부분배열에 대해 방문 배열, 혹은 hash set을 사용할 수 있다.

방문 배열의 초기화에 O(M)의 시간 복잡도를 사용한다.

### 공간 복잡도

방문 배열을 이용할 경우 O(M)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     130      | O(N^2 + M)  |    O(M)     |

숫자의 범위는 0 ~ 10^5 이다.

각 부분 배열에 대해 방문 배열을 이용해 홀수와 짝수의 개수를 센다.

이후 두 개수가 같을 경우 정답을 갱신한다.

```cpp
int longestBalanced(vector<int>& nums) {
  int size = nums.size();

  int answer = 0;
  bool visited[100001] = {
      0,
  };

  for (int left = 0; left < size; left++) {
    memset(visited, false, sizeof(visited));
    int oddCount = 0;
    int evenCount = 0;

    for (int right = left; right < size; right++) {
      int cur = nums[right];
      if (cur % 2 == 1) {
        if (visited[cur] == false) oddCount++;
        visited[cur] = true;
      } else {
        if (visited[cur] == false) evenCount++;
        visited[cur] = true;
      }

      if (oddCount == evenCount) {
        answer = max(answer, right - left + 1);
      }
    }
  }
  return answer;
}
```

## 고생한 점
