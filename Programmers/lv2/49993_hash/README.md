# 49993. 스킬트리

[링크](https://programmers.co.kr/learn/courses/30/lessons/49993)

| 난이도 | 완료(명) |
| :----: | :------: |
|  lv2   |   2790   |

## 설계

### 시간복잡도

스킬은 26자 이하의 문자열이다.

스킬트리는 최대 20개의 26자 이하의 문자열이다.

각 스킬트리 별로 최대 26개의 문자를 반복하므로 시간복잡도는 O(520) 이다.

### 공간복잡도

스킬트리 중 각 스킬의 번째를 확인하기 위해 Map구조를 사용한다.

### 스킬트리 만들기

입력받은 skill의 각 스킬을 Map으로 저장한다.

이때 순서가 중요하므로 번째 (index)를 같이 저장한다.

```javascript
let m = new Map();

[...skill].forEach((c, index) => {
  m.set(c, index);
});
```

이후 각 스킬트리 별로 문자를 순회한다.

순회하며 다음을 판별한다.

- 배워야 할 스킬트리에 있는 스킬인지 아닌지
- 배워야 할 스킬트리에 있는 스킬인 경우 순서대로 배우고있는지

현재 배워야 하는 스킬의 index를 변수로 두고 이 스킬을 배운 경우 index를 증가시켜 다음 스킬을 판별한다.

```javascript
[...skill_tree].forEach((c) => {
  if (m.has(c) && flag) {
    let get_index = m.get(c);

    if (get_index === index) {
      index += 1;
    } else {
      flag = false;
    }
  }
});
```

## 고생한 점
