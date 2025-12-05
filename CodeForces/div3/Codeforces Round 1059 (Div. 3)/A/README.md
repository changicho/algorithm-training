# A. Beautiful Average

[링크](https://codeforces.com/contest/2162/problem/A)

| 난이도 |
| :----: |
|  800   |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

수가 많아질 수록 평균이 줄어드므로 가장 큰 수를 찾는다. 이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      77      |    O(N)     |    O(1)     |

숫자의 갯수가 많아질 수록 평균이 줄어들기 때문에 가장 큰 수 하나를 찾는다.

```cpp
double solution(int size, vector<int>& nums) {
  double answer = 0.0;

  return *max_element(nums.begin(), nums.end());
}
```

## 고생한 점
