# 2433. Find The Original Array of Prefix Xor

[링크](https://leetcode.com/problems/find-the-original-array-of-prefix-xor/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

pref의 크기를 N이라 하자.

현재 i번째 값을 구하기 위해 pref의 i번째 값과 i-1번째 값을 이용할 수 있다.

이 경우 비트 연산을 이용해 구할 수 있다.

따라서 시간 복잡도는 O(N)이다.

### 공간 복잡도

정답으로 반환하는 배열에 O(N)의 공간 복잡도를 사용한다.

### 비트 연산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     250      |    O(N)     |    O(N)     |

pref는 다음과 같은 형태이다.

```
- pref[0] = 5.
- pref[1] = 5 ^ 7 = 2.
- pref[2] = 5 ^ 7 ^ 2 = 0.
```

pref는 모두 주어져 있으므로, 다음과 같은 규칙을 찾을 수 있다.

```
// P' : pref[i-1]
// P : pref[i]
// X : target

P' ^ X = P
P' ^ P = X
```

P'과 X를 xor연산해서 P가 나왔으므로 P'과 P를 xor연산할 경우 X를 구할 수 있다.

다음과 같은 예시를 보자

- P' : 101
- P : 010
- X : 111

이를 구현하면 다음과 같다.

```cpp
vector<int> findArray(vector<int>& pref) {
  int size = pref.size();
  vector<int> answer;

  answer.push_back(pref.front());
  for (int i = 1; i < size; i++) {
    int cur = pref[i];
    int before = pref[i - 1];

    answer.push_back(cur ^ before);
  }

  return answer;
}
```

## 고생한 점
