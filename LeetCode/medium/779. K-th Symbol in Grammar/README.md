# 779. K-th Symbol in Grammar

[링크](https://leetcode.com/problems/k-th-symbol-in-grammar/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 단계를 N, 찾고자하는 index를 K라 하자.

이 때 총 문장의 길이는 2^(N-1)이 된다.

직접 모든 문장을 구할 경우 최소 O(2^N)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

따라서 분할 정복을 이용해 탐색을 이어나간다.

이 경우 총 문장의 길이를 각각 절반씩 탐색을 이어나가므로 시간 복잡도는 O(log_2(2^N))이다. 이는 O(N)이다.

### 공간 복잡도

탐색의 call stack에 최대 O(N)의 공간 복잡도를 사용한다.

재귀호출이 아닌 순회로 구현할 경우 O(1)의 공간 복잡도를 사용한다.

### 분할 정복 (재귀호출)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |    O(N)     |    O(N)     |

주어진 문자열이 증가하는 방식을 보면 다음과 같이 구성된다.

- 0
- 01
- 0110
- 01101001

이는 다음과 같은 패턴을 따른다 (B는 A의 반전)

- A
- AB
- ABBA

이는 현재 단계로 다음 단계를 만들 때, 앞 부분은 그대로, 뒷 부분은 반전된 값으로 구성됨을 알 수 있다.

따라서 K번째 index를 찾기 위해 재귀 호출로 탐색을 이어나갈 수 있다.

이 때 정답으로 반환하는 값은 0과 1 이므로 boolean 형을 사용한다.

```cpp
bool recursive(int left, int right, int target, bool flag) {
  if (left == right) return flag;

  int center = left + (right - left) / 2;

  // left ~ center, center+1 ~ right
  if (target <= center) {
    return recursive(left, center, target, flag);
  }
  return recursive(center + 1, right, target, !flag);
}

int kthGrammar(int n, int k) {
  int length = pow(2, n - 1);

  return recursive(0, length - 1, k - 1, false);
}
```

### 분할 정복 (순회)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(0)     |

위 방법에서 재귀호출이 아닌 순회를 사용한다.

```cpp
int kthGrammar(int n, int k) {
  int length = pow(2, n - 1);
  bool flag = false;

  int left = 0, right = length - 1;
  k--;

  while (left != right) {
    int center = left + (right - left) / 2;

    if (k <= center) {
      right = center;
      flag = flag;
    } else {
      left = center + 1;
      flag = !flag;
    }
  }

  return flag;
}
```

## 고생한 점
