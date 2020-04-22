# 42588. 탑

[링크](https://programmers.co.kr/learn/courses/30/lessons/42588)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
|  lv2   |             |

## 설계

### 배열 채우기

초기 answer 배열의 크기를 설정할 때 다음과 같은 방법을 사용한다.

```javascript
let size = heights.length;
let answer = Array(size);
answer.fill(0);
```

정답 배열을 Array를 통해 배열 객체로 만든 뒤, 크기를 선언.

이후 초기값으로 채운다.

## 고생한 점
