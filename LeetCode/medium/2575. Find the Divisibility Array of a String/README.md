# 2575. Find the Divisibility Array of a String

[링크](https://leetcode.com/problems/find-the-divisibility-array-of-a-string/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

word의 길이를 N, 입력받은 수를 M이라 하자. (N <= 10^5, M <= 10^9)

N이 매우 크므로 직접 수를 계산할 경우 메모리 초과 & 시간 초과가 발생한다.

따라서 수를 나누는 연산을 생략하고, 나머지를 이용해야 한다.

이 경우 각 과정마다 이전의 값을 이용해 O(1)의 시간 복잡도로 연산이 가능하다.

이를 모든 자리수에 대해 반복하므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도를 사용한다.

### 나머지 연산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      48      |    O(N)     |    O(N)     |

큰 수 num을 a로 나눈 나머지를 다음과 같이 구할 수 있다.

```cpp
int mod(string num, int a) {
  long res = 0; // int형으로 하면 overflow 발생할수도 있음

  for (int i = 0; i < num.length(); i++)
    res = (res * 10 + (int)num[i] - '0') % a;

  return res;
}
```

각 자리수별로 나머지들을 구하고, 이를 증가시킨뒤 나머지를 구한다.

이 경우 num의 길이만큼 시간 복잡도를 사용한다.

주어진 word에서 앞에서부터의 prefix마다의 나머지가 0인지를 구해야 한다.

이를 순회를 이용해 prefix를 증가시키며 정답을 구한다.

```cpp
vector<int> divisibilityArray(string word, int m) {
  string num = "";

  long long temp = 0;

  vector<int> answer;
  for (char &c : word) {
    temp = (temp * 10 + (int)c - '0') % m;

    if (temp == 0) {
      answer.push_back(1);
    } else {
      answer.push_back(0);
    }
  }
  return answer;
}
```

## 고생한 점
