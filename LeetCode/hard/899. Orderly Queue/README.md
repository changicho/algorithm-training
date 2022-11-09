# 899. Orderly Queue

[링크](https://leetcode.com/problems/orderly-queue/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

k가 1인 경우와 1이 아닌 경우에 대해서 나눠 생각할 수 있다.

k가 1인 경우는 순환 큐 이므로 가능한 경우의 수 중에서 가장 빠른 정답을 찾을 수 있다.

이 때의 시간 복잡도는 직접 모든 문자열을 생성할 경우 O(N^2)이다.

k가 2 이상인 경우는 문자열의 순서를 마음대로 배치가 가능하다.

따라서 정렬을 이용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정답 문자열에 O(N)의 공간 복잡도를 사용한다.

### 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      9       |   O(N^2)    |    O(N)     |

K가 1인 경우는 맨 앞의 문자만 맨 뒤로 이동 가능하므로 순환 큐의 형태를 띄게 된다.

따라서 생성 가능한 모든 경우 중 정답을 찾아 반환한다.

K가 2 이상인 경우를 살펴보자.

이 경우 앞의 K개 중에서 유리한 경우만 남기고 불리한 경우는 맨 뒤로 보낼 수 있다.

앞의 K개의 문자가 정렬된 상태라고 가정하자.

이 경우 다시 앞의 K개를 맨 뒤로 보낸 뒤, 원래 K+1번째 문자를 맨 앞으로 두고 이를 똑같이 정렬할 수 있다.

이를 반복하면, 결국 모든 문자를 정렬할 수 있다.

이를 구현하면 다음과 같다.

```cpp
string orderlyQueue(string s, int k) {
  int length = s.length();

  if (k > 1) {
    sort(s.begin(), s.end());
    return s;
  }

  string answer = s;
  for (int i = 1; i < length; i++) {
    string temp = "";
    temp += s.substr(i);
    temp += s.substr(0, i);

    answer = min(answer, temp);
  }
  return answer;
}
```

## 고생한 점
