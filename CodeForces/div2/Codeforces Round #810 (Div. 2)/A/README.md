# A. Perfect Permutation

[링크](https://codeforces.com/contest/1711/problem/A)

| 난이도 |
| :----: |
| \*800  |

## 설계

### 시간 복잡도

원소의 갯수를 N이라 하자.

그리디 알고리즘을 이용해 배열을 생성할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답을 배열로 반환할 경우 O(N)의 공간 복잡도를 사용한다.

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      31      |    O(N)     |    O(N)     |

Pi를 i로 나누었을때 지수가 0인 경우는 Pi가 i보다 작은경우이다.

결국 1 ~ N까지의 수로만 채워넣어야 하고, 다음과 같이 배열을 구성할 경우 지수가 최소가 되는 경우가 된다.

- Pi : i-1
- i : i

즉 i보다 1 작은 값을 할당한다.

이를 구현하면 다음과 같다.

```cpp
vector<int> solution(int &n) {
  vector<int> answer(n);

  for (int i = 0; i < n; i++) {
    int target = (i + 1) % n;

    answer[target] = (i + 1);
  }

  return answer;
}
```

## 고생한 점
