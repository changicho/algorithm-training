# 362. Design Hit Counter

[링크](https://leetcode.com/problems/design-hit-counter/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

연산의 수를 N이라 하자.

연산마다 timestamp는 오름차순으로 들어옴이 보장된다.

다라서 배열과 이분 탐색을 사용할 경우 O(1)에 hit을 수행할 수 있고, O(log_2(N))에 getHits를 수행할 수 있다.

### 공간 복잡도

배열에 O(N)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) |    O(N)     |

hit연산시 timestamp가 오름차순을 들어오는것이 보장된다.

hit연산시 timestamp를 배열에 추가한다.

이후 getHits연산시 timestamp-300초부터 timestamp사이의 개수를 이분 탐색으로 구한다.

```cpp
class HitCounter {
 private:
  vector<int> nums;

 public:
  HitCounter() {}

  void hit(int timestamp) { nums.push_back(timestamp); }

  int getHits(int timestamp) {
    int count = upper_bound(nums.begin(), nums.end(), timestamp) -
                upper_bound(nums.begin(), nums.end(), timestamp - 300);

    return count;
  }
};
```

## 고생한 점
