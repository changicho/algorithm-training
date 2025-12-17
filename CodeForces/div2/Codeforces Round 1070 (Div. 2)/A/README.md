# A. Operations with Inversions

[링크](https://codeforces.com/contest/2176/problem/A)

| 난이도 |
| :----: |
|        |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N이라 하자.

배열을 순회하며 내림차순으로 내려가는 값들을 셀 경우 순회에 O(N)의 시간이 걸린다.

### 공간 복잡도

갯수를 세는 데 상수크기의 변수만 필요하므로 O(1)의 공간복잡도를 가진다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      46      |    O(N)     |    O(1)     |

i < j인 index쌍에서 `nums[i]` > `nums[j]`인 경우 삭제가 가능하다.

따라서 특정 index보다 뒤에 있는 값들 중 작은 값들을 삭제할 수 있고 이 수들을 세면된다.

```cpp
int solution(int size, vector<int>& nums) {
  int beforeMax = INT_MIN;
  int delCount = 0;
  for (int& num : nums) {
    if (num >= beforeMax) {
      beforeMax = num;
    } else {
      delCount++;
    }
  }

  return delCount;
}
```

## 고생한 점
