# 1394. Find Lucky Integer in an Array

[링크](https://leetcode.com/problems/find-lucky-integer-in-an-array/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 arr의 크기를 N이라 하자.

순회하며 count 후 정답을 구할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

count 배열을 사용하므로 O(N)의 공간 복잡도를 사용한다.

### 순회 & count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

각 숫자의 갯수를 센 뒤, 해당 숫자가 갯수와 같은지 확인한다.

```cpp
int findLucky(vector<int>& arr) {
  int count[501] = {
      0,
  };

  for (int& num : arr) {
    count[num]++;
  }

  int answer = -1;
  for (int i = 1; i <= 500; i++) {
    if (count[i] == i) answer = i;
  }
  return answer;
}
```

## 고생한 점
