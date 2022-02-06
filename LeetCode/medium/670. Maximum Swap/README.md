# 670. Maximum Swap

[링크](https://leetcode.com/problems/maximum-swap/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 숫자의 길이를 L이라 하자.

두 숫자만 바꾸면 되므로 모든 경우에 대해 brute force로 풀이할 수 있다.

이 경우 시간 복잡도는 O(L^2)이다.

혹은 one pass로 최적의 경우만 변경해 풀이할 수 있다.

이 경우 시간 복잡도는 O(L)이다.

### 공간 복잡도

swap을 쉽게 하기 위해 주어진 숫자를 문자열로 변경한다. 이 경우 O(L)의 공간 복잡도를 사용한다.

브루트 포스로 풀이하는 경우 별도의 공간을 더 사용하지 않으므로 O(1)의 공간 복잡도를 사용한다.

one pass로 풀이하는 경우 maximum index를 저장할 공간이 필요하므로 O(L)의 공간 복잡도를 사용한다.

### 브루트 포스

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(L^2)    |    O(L)     |

변경할 두 index의 범위는 각각 0 ~ (L - 1)이다.

이를 모두 순회하며 가능한 모든 경우를 탐색한다.

```cpp
int maximumSwap(int num) {
  string numStr = to_string(num);
  int length = numStr.length();

  int answer = num;
  for (int from = 0; from < length; from++) {
    for (int to = 0; to < length; to++) {
      swap(numStr[from], numStr[to]);
      answer = max(answer, stoi(numStr));
      swap(numStr[from], numStr[to]);
    }
  }

  return answer;
}
```

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(L)     |    O(L)     |

맨 앞자리부터 비교하며 작은 값과 큰 값을 변경하는 경우가 수를 가장 크게 만드는 경우이다.

이를 위해 앞자리부터 탐색하며, 해당 자리 오른쪽에 자신보다 큰 수가 있는지를 비교한다.

이를 위해 각 index마다 현재 위치에서 오른쪽 끝까지에서 가장 큰 값의 index를 저장하는 배열을 사용한다. (동적 계획법)

이후 변경할 위치를 왼쪽부터 탐색 후 해당 위치와 해당 위치 오른쪽에 있는 maximum index의 위치를 변경한다.

이 때 모든 수가 내림차순으로 정렬되어있는경우 (변경 안하는 경우가 가장 큰 경우) 변경하지 않는다.

```cpp
 int maximumSwap(int num) {
  string s = to_string(num);
  int length = s.length();
  // index of maximum digit in range i ~ (size - 1)
  vector<int> maximumIdx(length, length - 1);

  for (int i = length - 2; i >= 0; i--) {
    maximumIdx[i] = s[i] > s[maximumIdx[i + 1]] ? i : maximumIdx[i + 1];
  }

  int i = 0;
  while (i < length && s[i] >= s[maximumIdx[i]]) {
    i++;
  }
  if (i < length) {
    swap(s[i], s[maximumIdx[i]]);
  }

  int answer = stoi(s);
  return answer;
}
```

## 고생한 점
