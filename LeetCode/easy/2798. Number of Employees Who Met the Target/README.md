# 2798. Number of Employees Who Met the Target

[링크](https://leetcode.com/problems/number-of-employees-who-met-the-target/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 hours의 크기를 N이라 하자.

각 원소를 순회하며 target 이상인 경우를 센다. 이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답의 개수를 세는 변수를 선언하는데 O(1)의 공간 복잡도가 필요하다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

```cpp
int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
  int count = 0;
  for (int& h : hours) {
    if (h >= target) count++;
  }
  return count;
}
```

## 고생한 점
