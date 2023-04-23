# 2611. Mice and Cheese

[링크](https://leetcode.com/problems/mice-and-cheese/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 reward1, reward2의 수를 N이라 하자.

두 값은 결국 모두 선택되므로 첫번째 쥐가 선택했을 때 이익이 큰 순서대로 K개를 고른다.

이를 위해 가장 이득이 되는 순서대로 정렬한다.

이에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

새로운 배열을 생성할 경우 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     208      | O(N \* log_2(N)) |    O(N)     |

각각의 reward의 이익이 다음과 같다고 하자.

- 1번 쥐 : A
- 2번 쥐 : B

이 때 각 reward마다 1번 쥐가 선택했을 때 반대의 경우보다(A-B)만큼 이익이 증가한다

따라서 모든 reward에 대해 1번 쥐가 선택했을 때 이익의 증가가 큰 순서대로 정렬 후 앞에서부터 K개를 선택한다.

```cpp
int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
  int size = reward1.size();

  vector<pair<int, int>> nums;
  for (int i = 0; i < size; i++) {
    nums.push_back({reward1[i], reward2[i]});
  }

  sort(nums.begin(), nums.end(), [](auto& a, auto& b) {
    return (a.first - a.second) > (b.first - b.second);
  });

  int answer = 0;
  for (int i = 0; i < k; i++) {
    answer += nums[i].first;
  }
  for (int i = k; i < size; i++) {
    answer += nums[i].second;
  }
  return answer;
}
```

## 고생한 점
