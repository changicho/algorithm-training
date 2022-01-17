# 528. Random Pick with Weight

[링크](https://leetcode.com/problems/random-pick-with-weight/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

원소의 갯수를 N이라 하자.

모든 원소의 가중치에 대해 random하게 index를 뽑아야한다.

이를 위해 index별로 가중치의 합을 구하고 0부터 총합까지의 범위의 값에 해당하는 index를 반환할 수 있다.

모든 원소의 가중치의 prefixSum을 구하는데 O(N)의 시간 복잡도를 사용한다.

이후 index를 구할 때 이분 탐색을 이용할 경우 O(log_2(N))의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

prefixSum을 구하는 데 O(N)의 공간 복잡도를 사용한다.

### prefixSum + 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     137      |    O(N)     |    O(N)     |

각 가중치를 index마다 모두 순서대로 나열한다고 하자.

이후 random하게 수를 뽑는다고 하자.

원점에서부터 해당 수의 크기만큼 이동했을 때, 위치한 값을 포함하는 index가 random하게 뽑을 수 있는 index가 된다.

이를 위해 prefixSum을 미리 구한다.

random하게 뽑는 수의 범위는 다음과 같아야 한다.

- 0 <= ~ < 모든 가중치의 합

이는 단순히 0을 포함한 양의 정수만을 생각하는 범위를 생각할 때 다음과 같이 생각할 수 있다.

- 가중치가 3, 3 두개인 경우
- 0, 1, 2 : 첫번째
- 3, 4, 5 : 두번째

이렇게 index를 나타낼 수 있다.

이 경우 prefixSum에 대입해 생각해보자.

- 0, 1, 2 : 3
- 3, 4, 5 : 6

이는 prefixSum에 대한 upper_bound값이된다.

따라서 pickIndex의 시간 복잡도는 O(log_2(N))으로 수행 가능하다.

이를 구현할 경우 다음과 같다.

```cpp
class Solution {
 private:
  vector<int> preSum;

 public:
  Solution(vector<int>& w) {
    preSum.resize(w.size(), 0);

    // fill prefixSum
    preSum[0] = w.front();
    for (int i = 1; i < w.size(); i++) {
      preSum[i] = preSum[i - 1] + w[i];
    }
  }

  int pickIndex() {
    int target = rand() % (preSum.back());

    int index =
        upper_bound(preSum.begin(), preSum.end(), target) - preSum.begin();
    return index;
  }
};
```

## 고생한 점
