# 89. Gray Code

[링크](https://leetcode.com/problems/gray-code/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

N개의 비트에 대해서 모든 그레이 코드를 순서대로 구해야 한다.

구해야 하는 갯수는 최대 2^N개이다. 숫자를 그레이 코드로 변환하는 데 연산은 O(1)이 소요된다.

따라서 필요한 시간 복잡도는 O(2^N)이다.

재귀 함수를 이용할 경우도 결국 탐색에 O(2^N)이 소요된다.

### 공간 복잡도

숫자를 그레이 코드로 직접 변환할 경우 별도의 공간이 필요하지 않다.

만약 이전 그레이 코드를 이용해 현재 그레이 코드를 구할 경우 이전 그레이코드들의 리스트 만큼의 공간이 필요하다.

따라서 필요한 공간 복잡도는 O(N)이다.

### 그레이 코드로 직접 변환

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |   O(2^N)    |    O(1)     |

i번째 그레이 코드를 구하는 방법은 다음과 같다.

```cpp
// i번째 그레이코드 수
i ^ (i >> 1);
```

바이너리 코드(2비트로 나타낸 수)를 그레이 코드로 바꾸는 방법은 다음과 같다.

제일 큰 자리수는 그대로 사용한다.

현재 자리를 i라고 할때, 그레이 코드에서 i번째 수는 원본 수의 i, i-1 수의 xor연산이다.

따라서 현재 숫자를 오른쪽으로 shift연산한뒤 원본 숫자와 xor연산을 할 경우 위 규칙에 따라 그레이 코드를 만들 수 있다.

```cpp
vector<int> grayCode(int n) {
  vector<int> answer;
  int limit = 1 << n;
  for (int number = 0; number < limit; number++) {
    answer.push_back(number ^ (number >> 1));
  }
  return answer;
}
```

### 재귀 호출 (동적 계획법)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |   O(2^N)    |    O(N)     |

그레이 코드란 인접한 숫자 간의 1bit의 숫자만이 차이가 나는 코드이다.

따라서 이전 그레이 코드를 이용해 현재 그레이 코드를 구할 수 있다.

N비트 그레이 코드를 적고 앞에 0을 붙인 것과, N비트 그레이 코드를 역순으로 적고 앞에 1을 붙인다.

이와 같은 방식으로 N+1비트 그레이 코드를 만들 수 있다.

```cpp
// 1비트
0
1

// 2비트
0 0 // 정방향, 맨 앞에 0을 붙임
0 1 // 정방향, 맨 앞에 0을 붙임
1 1 // 역방향, 맨 앞에 1을 붙임
1 0 // 역방향, 맨 앞에 1을 붙임

// 3비트도 현재와 동일
```

이를 이용해 현재 그레이코드에서 맨 앞자리를 0, 1로 만들고 역순으로 반복해 그레이코드 목록을 구할 수 있다.

재귀 호출을 이용해 top-down방식으로 구현할 경우 다음과 같다.

```cpp
vector<int> grayCode(int n) {
  vector<int> answer;
  grayCode(answer, 0, n, 0);
  return answer;
}

void grayCode(vector<int> &array, int number, int n, int index) {
  if (index == n) {
    array.push_back(number);
    return;
  }

  number &= ~(1 << index);
  grayCode(array, number, n, index + 1);

  number |= 1 << index;
  reverseGrayCode(array, number, n, index + 1);
}

void reverseGrayCode(vector<int> &array, int number, int n, int index) {
  if (index == n) {
    array.push_back(number);
    return;
  }

  number |= 1 << index;
  grayCode(array, number, n, index + 1);

  number &= ~(1 << index);
  reverseGrayCode(array, number, n, index + 1);
}
```

### 반복문 (동적 계획법)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |   O(2^N)    |    O(N)     |

앞서 설명한 그레이코드를 만드는 방법을 이용한다.

현재 그레이 코드를 만들 때 지금까지 만든 그레이 코드를 역순으로 순회하며, 최상위 비트를 추가해준다.

```cpp
vector<int> grayCode(int n) {
  vector<int> answer = {0};
  int limit = 1 << n;

  for (int size = 1; size < limit; size *= 2) {
    for (int i = size - 1; i >= 0; i--) {
      answer.push_back(answer[i] + size);
    }
  }

  return answer;
}
```

## 고생한 점
