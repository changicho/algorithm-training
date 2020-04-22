# 42587. 프린터

[링크](https://programmers.co.kr/learn/courses/30/lessons/42587)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
|  lv2   |             |

## 설계

### 자바스크립트 queue

```javascript
arr.push(item); // enqueue
arr.shift(); // dequeue
```

### 자바스크립트 stack

```javascript
arr.push(item); // push
arr.pop(); // pop
```

### 우선순위 판단

우선순위 배열을 내림차순으로 정렬한다.

인쇄 대기열에서 현재 작업의 인쇄 여부는 우선순위 배열의 front와 비교하고, 인쇄할 경우 우선순위 배열에서 front를 삭제한다.

## 고생한 점
