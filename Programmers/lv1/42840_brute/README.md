# 42840. 모의고사

[링크](https://programmers.co.kr/learn/courses/30/lessons/42840)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
|  lv1   |             |

## 설계

### 각 인원별 정답 처리

각 인원별로 패턴의 길이가 다르므로, index에 mod 연산을 통해 패턴을 일치시킨다.

```javascript
let index = idx % checks[student].length;
```

### 복수 최다 득점자 처리

인원이 3명밖에 되지 않으므로, 자기 자신이 최대 득점자에 포함될 수 있는지만 조건으로 처리함.

## 고생한 점
