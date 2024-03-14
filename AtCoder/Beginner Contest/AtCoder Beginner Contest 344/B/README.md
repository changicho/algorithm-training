# B - Delimiter

[링크](https://atcoder.jp/contests/abc344/tasks/abc344_b)

| 난이도 |
| :----: |
|  150   |

## 설계

### 시간 복잡도

배열 A의 크기를 N이라 하자.

배열의 숫자들을 입력받고 이후 이를 뒤집어 출력한다.

배열을 뒤집는 데 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

배열에 O(N)의 공간 복잡도가 필요하다.

### 뒤집기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(N)     |

N이 주어지지 않고 수를 계속 입력받아야 하므로 cin에 while문을 감싼다.

이후 입력받은 배열을 뒤집는다.

```cpp
int A;
vector<int> arr;
while (cin >> A) {
  arr.push_back(A);
}

reverse(arr.begin(), arr.end());
```

## 고생한 점
