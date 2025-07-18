# 3201. Find the Maximum Length of Valid Subsequence I

[링크](https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

동적 계획법을 이용해 최대 길이를 구할 경우 O(N)의 시간 복잡도를 사용한다.

순회를 이용해 최대 길이를 구할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 의해 최대 길이를 구할 경우 O(N)의 공간 복잡도를 사용한다.

직전 값만 사용할 경우 O(1)의 공간 복잡도를 사용한다.

순회를 이용해 값을 갱신할 경우 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      10      |    O(N)     |    O(1)     |

정답의 조건을 만족하는 경우는 다음과 같다.

- 모두 짝수로 이루어진 경우
- 모두 홀수로 이루어진 경우
- 홀수와 짝수가 번갈아가며 나오는 경우

여기서 짝수, 홀수로 모두 통일된 경우 배열 내에서 해당 종류의 count를 구한다.

번갈아 가면서 나오는 경우 다음과 같이 구할 수 있다.

- 제일 앞 원소의 parity를 시작점으로 잡은 뒤 번갈아가며 나오는 숫자의 개수를 센다.
- 만약 제일 앞 원소 외에 정답으로 나올 수 있는 경우들은 다음과 같다

```cpp
// {}로 묶인 부분이 정답으로 예상되는 경우
// 제일 앞 원소와 정답이 될 수 있는 subsequence의 parity가 같은 경우
[0, {0, 1, 0, 1, ...}]
// 시작점은 제일 앞 원소 또한 가능하다.

// 정답이 될 수 있는 subsequence의 parity가 다른 경우
[0, {1, 0, 1, ...}]
// 해당 경우는 제일 앞 원소를 포함한 정답만이 가능하다.
// 정답이 될 수 있는 subsequence에 가장 앞 원소까지 포함해야 더 큰 값이 되기 때문이다.
```

이를 이용해 순회와 동시에 정답을 구한다.

이 때 직전 값과 parity를 비교할 때 직전 값을 -1로 초기화해 첫번째 원소와 비교할 때도 정답이 갱신될 수 있도록 한다.

```cpp
int maximumLength(vector<int>& nums) {
  int size = nums.size();

  int odd = 0, even = 0, toggled = 0, prev = -1;
  for (int& num : nums) {
    if (num % 2 == 1) {
      odd++;
    } else {
      even++;
    }

    if (num % 2 != prev % 2) {
      toggled++;
      prev = num;
    }
  }
  return max({odd, even, toggled});
}
```

## 고생한 점
