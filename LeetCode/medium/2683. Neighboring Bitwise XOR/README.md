# 2683. Neighboring Bitwise XOR

[링크](https://leetcode.com/problems/neighboring-bitwise-xor/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 derived의 크기를 N이라 하자. (N <= 10^5)

모든 배열의 경우를 시도할 경우 제한시간 내에 불가능하다.

따라서 입력받은 배열 derived의 값을 이용해 원본 배열을 생성하고 이것이 순회하는지를 판단한다.

이에 순회를 진행하므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

원본 배열을 직접 생성할 경우 O(N)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     351      |    O(N)     |    O(N)     |

derived 배열을 이용해 원본 배열을 생성한다.

이 때 원본 배열에서 연이은 값에 대해 xor연산을 진행해 원본 배열의 값을 생성하므로, 이를 이용한다.

현재 derived의 index를 i라 하자.

- i번째 값이 1인 경우 : 원본 배열의 i+1번째 값은 i번째 값과 다르다.
- i번째 값이 0인 경우 : 원본 배열의 i+1번째 값은 i번째 값과 같다.

이를 이용해 원본 배열의 값을 생성한다.

이후 맨 처음값과 맨 마지막 값에 대해 derived의 값을 만족하는지 판단한다.

```cpp
bool doesValidArrayExist(vector<int>& derived) {
  int size = derived.size();
  bool converted[100001] = {
      false,
  };
  converted[0] = true;

  for (int i = 0; i < size - 1; i++) {
    int next = i + 1;

    if (derived[i] == 1) {
      converted[next] = !converted[i];
    } else {
      converted[next] = converted[i];
    }
  }

  if (derived[size - 1] == 1) {
    if (converted[0] == converted[size - 1]) return false;
  } else {
    if (converted[0] != converted[size - 1]) return false;
  }
  return true;
}
```

### 1 count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     353      |    O(N)     |    O(1)     |

1의 갯수가 짝수인지 판단한다.

이는 원형 관계에서 현재 값과 이웃 값에 따라 1의 갯수가 짝수개씩 변화하기 때문이다.

```cpp
bool doesValidArrayExist(vector<int>& derived) {
  int countOne = accumulate(derived.begin(), derived.end(), 0);
  return countOne % 2 == 0;
}
```

## 고생한 점
