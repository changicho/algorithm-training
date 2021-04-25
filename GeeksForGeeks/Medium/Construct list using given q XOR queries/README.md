# Construct list using given q XOR queries

[링크](https://practice.geeksforgeeks.org/problems/construct-list-using-given-q-xor-queries/0/#)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

쿼리의 길이는 최대 10^5 이다.

하나의 xor 연산을 배열에 직접 적용하는 데 들어가는 시간 복잡도는 O(N) 이다.

배열안에 숫자는 최대 O(N) 이라고 했을 때 브루트 포스 방법의 경우 시간 복잡도는 O(N^2) 이다.

이는 제한 시간 내에 불가능하다.

따라서 XOR의 성질을 이용해 O(N) 이내로 최적화한다.

이후 정렬을 해줘야 하므로 시간 복잡도는 O(N \* log_2(N))이 된다.

### 공간 복잡도

배열의 크기만큼 필요하므로 O(N)의 공간 복잡도가 기본적으로 필요하다.

## xor

- 시간 복잡도 : O(N \* log_2(N))
- 공간 복잡도 : O(N)

xor 연산의 성질은 다음과 같다.

```cpp
a ^ a; // 0
a ^ 0; // a
0 ^ 0; // 0
(a ^ b) ^ c; // a ^ (b ^ c)
(a ^ a) ^ b; // b
(a ^ b) ^ a; // b
```

여기서 자기 자신을 xor하는 경우 0이 나오는 것에 유의한다.

다음과 같은 예시를 생각해보자

```cpp
array = {{0, A}, {1, a}, {0, B}, {1, b}, {0, C}}
```

배열 안에는 A,B,C 숫자가 들어있을 것이며 각각 xor연산은 다음과 같다.

```cpp
A > A^a^b
B > B^b
C > C
```

자기 자신을 xor연산하는경우 0 이므로 위 식을 다음과 같이 바꿀 수 있다.

```cpp
A > A^(a^b)^0
B > B^(a^b)^a
C > C^(a^b)^a^b
```

여기서 a와 b는 쿼리에서 받은 모든 xor연산을 수행해야할 숫자들이다.

즉 모든 숫자들은 입력받은 xor연산 대상인 숫자들이 모두 포함되어 있다고 생각할 수 있다.

여기서 A, B, C에서 xor연산 대상 이후 나오는 숫자들은 각 쿼리에서 이전까지 xor해야되는 숫자들이다.

따라서 다음과 같이 일반화 할 수 있다.

(XOR : 현재까지 xor쿼리가 나왔을 때마다 그 숫자를 xor한 숫자)

- 입력하는 쿼리의 경우 : (숫자^XOR)를 배열에 넣는다.
- xor하는 쿼리의 경우 : XOR^새로운 숫자.
- 모든 쿼리가 끝난 후 배열의 모든 숫자에 XOR를 xor연산을 해준다.
- 정렬해준다.

```cpp
vector<int> constructList(vector<vector<int>> Q, int N) {
  // code here
  int XOR = 0;
  vector<int> ret = {
      0,
  };

  for (vector<int> query : Q) {
    if (query[0] == 0) {
      ret.push_back(query[1] ^ XOR);
    } else {
      XOR ^= query[1];
    }
  }

  for (int i = 0; i < ret.size(); i++) {
    ret[i] ^= XOR;
  }

  sort(ret.begin(), ret.end());

  return ret;
}
```

## 고생한 점
