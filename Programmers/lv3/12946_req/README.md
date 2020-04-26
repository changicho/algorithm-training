# 12946. 하노이의 탑

[링크](https://programmers.co.kr/learn/courses/30/lessons/12946)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
|  lv3   |             |

## 설계

### 하노이의 탑 알고리즘

하노이의 탑의 경우 재귀함수를 이용해 최단 풀이법을 구할 수 있다.

```cpp
void hanoi(int n, int from, int tmp, int to) {
  if (n == 1){
    printf("1 : %d -> %d\n", from, to);
  } else {
    hanoi(n - 1, from, to, tmp);
    printf("%d : %d -> %d\n", n, from, to);
    hanoi(n - 1, tmp, from, to);
  }
}

hanoi(n, 1, 2, 3) // n : 쌓여있는 원판의 개수
```

1. 첫 번째 재귀에서는 맨 밑의 N번째 원반을 목적지로 옮기기 위해 위의 N-1 개의 원반을 경유지로 옮긴다.
2. 그 다음 N 번째 원반을 목적지로 옮긴다.
3. 경유지에 있는 N-1 개의 원반을 to로 옮긴다.

## 고생한 점
