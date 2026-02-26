# D - Max Straight

[링크](https://atcoder.jp/contests/abc446/tasks/abc446_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

hash map을 이용해 각 숫자에 대한 최대 연속 길이를 저장한다. 

이에 복잡도는 O(N)이다.

### 공간 복잡도

hash map에 O(N)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      40      |    O(N)     |    O(N)     |

각 숫자별로 최대 연속 길이를 저장하는 hash map을 이용한다.

순회하며 최대 연속길이를 갱신한다.

```cpp
auto solution(int size, vector<int>& nums) {
  int answer = 1;

  unordered_map<int, int> um;

  for (int& num : nums) {
    if (um.count(num - 1) > 0) {
      um[num] = um[num - 1] + 1;
    } else {
      um[num] = 1;
    }
    answer = max(answer, um[num]);
  }

  return answer;
}
```

## 고생한 점
