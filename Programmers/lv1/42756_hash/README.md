# 42576. 완주하지 못한 선수

[링크](https://programmers.co.kr/learn/courses/30/lessons/42576)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
|  lv1   |             |

## 설계

### Map 을 이용

key : 이름, value : number 로 구성된 Map 객체를 생성

participant를 순회하며 참가자의 이름의 수를 count 함.

completion를 순회하며 참가자의 이름으로 된 count 를 감소시킴.

최종적으로 Map에 남아있는 key가 정답

## 고생한 점
