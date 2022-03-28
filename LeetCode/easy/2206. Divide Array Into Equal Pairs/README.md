# 2206. Divide Array Into Equal Pairs

[링크](https://leetcode.com/problems/divide-array-into-equal-pairs/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

우선 모든 nums의 원소를 순회하며 갯수를 세야한다. 이 때 특정 수의 갯수가 홀수인 경우는 정답이 false인 경우이다.

모든 원소의 순회에 O(N)의 시간 복잡도를 사용한다.

hash set, counts array등을 사용할 경우 O(1)의 시간 복잡도로 count에 접근이 가능하다.

따라서 최종 시간 복잡도는 O(N)이다.

### 공간 복잡도

숫자들의 범위만큼의 공간 복잡도를 사용한다. 범위는 1 ~ 500 이므로 O(500)의 공간 복잡도를 사용하며, 이는 O(1)이다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      31      |    O(N)     |    O(1)     |

pair를 만들어 주면 되므로 숫자를 순회하며 hash set에 다음 연산을 수행한다.

- hash set에 없는 경우 : 추가한다
- hash set에 있는 경우 : 제거한다

이 과정을 통해서 만약 짝을 만들 수 없는 숫자가 있는 경우 hash set의 크기는 0이 아니게 된다.

```cpp
bool divideArray(vector<int>& nums) {
  // total O(500) = O(1)
  unordered_set<int> us;

  // O(N)
  for (int& num : nums) {
    if (us.count(num) > 0) {
      us.erase(num);
    } else {
      us.insert(num);
    }
  }

  return us.size() == 0;
}
```

## 고생한 점
