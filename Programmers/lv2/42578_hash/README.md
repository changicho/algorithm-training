# 42578. 위장

[링크](https://programmers.co.kr/learn/courses/30/lessons/42578)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
|  lv2   |             |

## 설계

### 시간복잡도

하나의 옷의 종류에서 선택 가능한 수가 n일 때, 아무것도 선택하지 않는 것까지 포함해 가능한 수는 n+1이다.

그러나 모든 종류에서 전부 선택하지 않는 경우는 존재하지 않으므로 "전부 선택하지 않는 경우" 한가지를 뺀다.

따라서 각 종류별 갯수 n+1 들을 곱한 뒤 1을 빼면 정답이다.

이 방법은 한번 순회하는데 N번, 또 곱하는데 최대 N번이 소요되므로 시간복잡도는 O(N) 이다.

### Map을 사용

각 종류별 테이블에 저장하기 위해 Map을 사용한다.

get과 set으로 Map을 갱신한다.

```javascript
clothes.forEach((cur) => {
  if (m.get(cur[1]) === undefined) {
    m.set(cur[1], 1);
  } else {
    let count = m.get(cur[1]);
    m.set(cur[1], count + 1);
  }
});
```

Map.prototype.forEach를 사용하면 각 key별로 순회가 가능하다.

```javascript
m.forEach((cur) => {
  answer *= cur + 1;
});
```

## 고생한 점
