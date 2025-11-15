# 898. Bitwise ORs of Subarrays

[링크](https://leetcode.com/problems/bitwise-ors-of-subarrays/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 arr의 크기를 N, 만들어 질 수 있는 쌍의 갯수를 M이라 하자.

각 과정마다 이전에 만든 쌍들에 현재 숫자를 OR 연산하여 새로운 쌍을 만들 수 있다. 이 과정에 O(M)의 시간 복잡도를 사용한다.

이를 N번 반복하므로 전체 시간 복잡도는 O(N \* M)이다.

### 공간 복잡도

현재까지 만든 쌍들을 저장하기 위해 해시셋을 사용하므로 공간 복잡도는 O(M)이다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     1092     |  O(N \* M)  |    O(M)     |

이전까지 과정에서 만든 쌍들을 hash set에 저장한다. 

현재 숫자와 직전에 만든 쌍들을 OR 연산하여 새로운 쌍을 만들고, 이 쌍들을 hash set에 추가한다.

현재 추가된 쌍들을 정답에 추가하며, 다음 숫자에 동일한 연산을 수행한다.

```cpp
int subarrayBitwiseORs(vector<int> arr) {
  unordered_set<int> answer;

  unordered_set<int> cur;
  for (int &num : arr) {
    unordered_set<int> next = {num};
    for (int before : cur) {
      next.insert(num | before);
    }

    swap(cur, next);
    for (int num : cur) answer.insert(num);
  }
  return answer.size();
}
```

## 고생한 점
