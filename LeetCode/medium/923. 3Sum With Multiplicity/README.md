# 923. 3Sum With Multiplicity

[링크](https://leetcode.com/problems/3sum-with-multiplicity/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

arr의 크기를 N이라 하자.

모든 경우를 다 살펴볼 경우 O(N^3)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

따라서 조합론을 이용해 시간복잡도를 줄일 수 있다.

이 경우 원소의 값의 종류의 갯수를 W라고 하자.

하나의 값을 고정하고, 나머지를 이동시키며 경우의수를 구할 수 있다.

이 경우 O(W^2)의 시간 복잡도를 사용한다. arr을 모두 순회하며 W를 구해야 하므로 O(N)의 시간 복잡도를 순회에 사용한다.

따라서 최종 시간 복잡도는 O(N + W^2)이다.

### 공간 복잡도

각 수의 갯수를 저장해야 하므로 O(W)의 공간 복잡도를 사용한다.

### 투 포인터 & 조합론

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       | O(N + W^2)  |    O(W)     |

한개의 숫자 A에 대해서 정답은 다음 3가지 경우일수있다.

각 경우마다의 정답은 조합론으로 구할 수 있다. A의 갯수를 a이라 하자.

(B의 수를 b, C의 수를 c)

- A 3개로 이루어짐 : aC3
- A 2개로 이루어짐 : aC2 \* (다른 숫자의 갯수)
- A 1개로 이루어짐 : a \* b \* c

여기서 C는 combination이다.

이를 이용해 모든 수를 각 값과 갯수를 나타내는 hash map에 저장한다.

이후 각 값을 순회하며 다음 3가지 경우를 탐색한다.

이 때 현개 값이 1개로 구성된 경우는 투 포인터를 이용해 정답을 구한다.

한개의 수가 고정되어있고, 키가 오름차순으로 정렬되어있을 때 나머지 2개가 정답을 구성하는 경우는 다음과 같이 구할 수 있다.

- 남은 수중 가장 큰 값과 가장 작은 값을 선택하고 더한다.
- 정답이 가능한 경우 count한다.
- 정답 초과인 경우는 큰 값을 이동시킨다.
- 정답 미만인 경우는 작은 값을 이동시킨다.

(여기서 정답인 경우는 둘중 한 경우만 택한다.)

이를 구현하면 다음과 같다.

```cpp
int threeSumMulti(vector<int>& arr, int target) {
  unordered_map<int, long> count;
  vector<int> keys;

  for (int& a : arr) {
    count[a]++;
  }
  for (auto it : count) {
    keys.push_back(it.first);
  }
  sort(keys.begin(), keys.end());

  int size = keys.size();
  long long answer = 0;

  for (int i = 0; i < size; i++) {
    long curCount = count[keys[i]];
    // one case
    int left = i + 1, right = size - 1;
    while (left < right) {
      int cur = keys[i] + keys[left] + keys[right];

      if (cur == target) {
        answer += curCount * count[keys[left]] * count[keys[right]];
      }

      if (cur > target) {
        right--;
      } else {
        left++;
      }
    }

    // two case
    if (count[keys[i]] >= 2 && count.count(target - keys[i] * 2) > 0 &&
        target - keys[i] * 2 != keys[i]) {
      answer += (curCount * (curCount - 1) / 2) * count[target - keys[i] * 2];
    }

    // three case
    if (count[keys[i]] >= 3 && keys[i] * 3 == target) {
      answer += curCount * (curCount - 1) * (curCount - 2) / 6;
    }
  }

  answer %= MOD;
  return answer;
}
```

## 고생한 점
