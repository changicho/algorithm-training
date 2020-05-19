# 15552. 빠른 A+B

[링크](https://www.acmicpc.net/problem/15552)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Bronze II |   47.832    |

## 설계

### 시간복잡도

T는 최대 1,000,000 까지이다.

시간복잡도는 O(1,000,000)이고 입출력이 늦을경우 제한시간 내에 풀이가 어렵다.

A와 B의 합을 출력하면 되므로 빠른 입출력을 사용한다.

### 빠른 입출력

```cpp
cin.tie(NULL);
sync_with_stdio(false);

cout<<"\n";
```

```java
BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

bw.flush();
bw.close();
```

```python
import sys

sys.stdin.readline().split()
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     232      |       12       |

## 고생한 점
