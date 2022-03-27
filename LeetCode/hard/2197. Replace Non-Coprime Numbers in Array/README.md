# 2197. Replace Non-Coprime Numbers in Array

[링크](https://leetcode.com/problems/replace-non-coprime-numbers-in-array/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

nums의 크기를 N, 숫자의 최대값을 M이라고 하자.

LCM, co-prime을 구하는 방법으로 gcd를 이용한다. 이 경우 O(log_2(M))의 시간 복잡도를 사용한다.

각 수를 순회하며 연속된 숫자들이 co-prime이 아닌 경우 LCM으로 합쳐야 한다.

이를 한번의 순회로 진행하기 위해 stack을 사용한다.

이 경우 한번의 순회로 풀이가 가능하므로 O(N)의 시간 복잡도를 사용한다.

따라서 최종 시간 복잡도는 O(N \* log_2(M)) 이다.

### 공간 복잡도

stack을 사용하므로 O(N)의 공간 복잡도를 사용한다.

### stack & gcd

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     216      | O(N \* log_2(M)) |    O(N)     |

LCM, co-prime을 구하기 위해 다음 함수를 사용한다.

```cpp
// O(log_2(A + B))
long long LCM(long long a, long long b) { return a * b / gcd(a, b); }

// O(log_2(A + B))
bool isCoPrime(int &a, int &b) { return gcd(a, b) == 1; }
```

특정숫자 A, B의 gcd의 시간 복잡도는 O(log_2(A + B))이다.

이를 이용해 빠른 시간내에 LCM과 isCoPrime 여부를 판단 가능하다.

연속된 숫자들 끼리 합치는 경우를 생각해보자.

```javascript
[a, b, c, d];
```

위 경우 (a, b), (c, d)끼리 합쳐진다고 했을 때 각 숫자들마다 순회하며 이웃하는 숫자와 합쳐지는지 판단할 수 있다.

LCM을 연쇄적으로 구하는 경우를 생각해보자

```javascript
[a, b, c, d];
```

(a, c), (b, c)가 합쳐지는것이 가능할 때 (b, c)를 먼저 합치고 이후 합쳐진 값과 a를 합칠 수 있다.

이런 연속된 경우를 합치기 위해 직전에 방문한 값, 합쳐진 값을 stack에 계속 쌓고 현재 값과 top이 합쳐지지 않을 때 까지 stack을 비우며 계속합친다.

이를 구현하면 다음과 같다.

```cpp
vector<int> replaceNonCoprimes(vector<int> &nums) {
  int size = nums.size();
  // O(N)
  vector<int> answer;

  // O(N)
  for (int &num : nums) {
    // trim answer if can make LCM back with current
    // total O(N)
    while (!answer.empty() && !isCoPrime(answer.back(), num)) {
      // O(log_2(M))
      num = LCM(num, answer.back());
      answer.pop_back();
    }
    answer.push_back(num);
  }

  return answer;
};
```

## 고생한 점
