# A - Content Too Large

[링크](https://atcoder.jp/contests/abc413/tasks/abc413_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

배열의 길이를 N이라 하자.

순회하며 합을 구할 경우 O(N)의 시간 복잡도를 갖는다.

### 공간 복잡도

순회후 합을 구하는 데 O(1)의 공간 복잡도를 갖는다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(1)     |

```cpp
bool solution(int n, int m, vector<int> &a) {
  for(int &num : a){
    m -= num;

    if(m < 0){
      return false;
    }
  }

  return true;
}
```

## 고생한 점
