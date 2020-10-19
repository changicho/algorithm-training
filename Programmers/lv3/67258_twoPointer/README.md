# 67258. [카카오 인턴] 보석 쇼핑

[링크](https://programmers.co.kr/learn/courses/30/lessons/67258)

| 난이도 | 완료 (명) |
| :----: | :-------: |
|  lv3   |    696    |

## 설계

### 시간 복잡도

배열의 크기는 100,000 까지이고, 이는 N^2으로는 풀이가 불가능하다.

따라서 시간복잡도를 줄이기 위해 다음 방법들을 사용한다

- 투 포인터 : 순회
- Map : 갯수 판단

### 공간 복잡도

정답은 int형의 범위이고, 자료구조의 크기 또한 100,000을 넘지않는다.

### 투 포인터

start와 end 지점을 초기에 0으로 세팅한다.

start가 end 이하일 때 다음 조건에 따라 순회한다.

- 현재 보석 범위에 모든 보석이 들어있지 않은 경우
  - end가 범위를 초과하지 않으면 end를 증가
  - 증가된 end에 있는 보석을 범위에 추가
- 그 외의 경우
  - 현재 보석 범위에 모든 보석이 들어있는 경우
    - 정답 갱신
  - 보석 범위에서 start 지점에 있는 보석 삭제
  - start를 증가

```cpp
while (start <= end) {
  if (count < totalCount && end < gems.size() - 1) {
    end++;

    // 포함한 보석 갱신
  } else {
    if (count == totalCount) {
      // 정답 갱신
    }

    // 포함한 보석 갱신
    start++;
  }
}
```

### 보석 범위

현재 범위에 보석의 개수는 map으로 관리한다.

key는 보석의 종류, value는 보석의 개수로 설정

이 때 value가 0에서 1, 1에서 0이 되는 경우는 보석 범위의 보석의 종류의 수가 변동되는 경우이므로 주의한다.

맨 처음 각각 보석의 종류마다 보석의 개수를 0개로 초기화 시켜준다.

```cpp
for (string gem : gems) {
  m[gem] = 0;
}
```

## 고생한 점