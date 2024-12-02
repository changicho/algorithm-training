# 1346. Check If N and Its Double Exist

[링크](https://leetcode.com/problems/check-if-n-and-its-double-exist/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 arr의 길이를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이다.

hash set을 이용할 경우 한번 순회로 해결이 가능하다. 이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

hash set에 O(N)의 공간 복잡도가 필요하다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

arr의 원소를 순회하며 직전까지 방문한 숫자들 중에 조건을 부합하는 수가 있는지 확인한다.

```cpp
bool checkIfExist(vector<int>& arr) {
  unordered_set<int> us;

  for (int& num : arr) {
    if (us.count(num * 2) > 0) return true;
    if (num % 2 == 0 && us.count(num / 2) > 0) return true;
    us.insert(num);
  }
  return false;
}
```

## 고생한 점
