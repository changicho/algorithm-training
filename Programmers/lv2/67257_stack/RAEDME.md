# 67257. [카카오 인턴] 수식 최대화

[링크](https://programmers.co.kr/learn/courses/30/lessons/67257)

| 난이도 | 완료 (명) |
| :----: | :-------: |
|  lv2   |   1121    |

## 설계

### 시간 복잡도

문자의 길이는 최대 100 이다.

최악의 경우의 숫자의 갯수는 100개를 넘지 않는다.

또한 연산의 경우 각 우선순위의 모든 경우의 수의 총 개수는 6개 이다.

최악의 경우 시간 복잡도는 O(N) 이므로 제한시간 내에 충분하다.

### 공간 복잡도

문자에서 숫자는 999 이하이다. 따라서 int형으로 선언해도 충분하다.

그러나 정답은 long long 형태이므로 (곱 연산이 존재하므로) 전부 long long 형태로 선언한다.

### 스택 계산기

연산자는 총 3개이다.

숫자와 연산자를 순회하며, 현재 연산자가 연산을 수행해야 하는 연산자인 경우 계산을 실행하고 숫자 stack에 집어넣는다.

이를 연산자 우선순위 순으로 계산하는 경우 연산자 우선순위에 따른 답이 나온다.

```cpp
stack<long long> nums_s;
stack<char> opers_s;

nums_s.push(nums_cur.front());

for (int i = 0; i < opers_cur.size(); i++) {
  opers_s.push(opers_cur[i]);

  char cur_oper = opers_s.top();

  // 우선순위 제일높을때
  if (cur_oper == priority[p]) {
    long long temp = oper(nums_s.top(), nums_cur[i + 1], cur_oper);
    nums_s.pop();
    opers_s.pop();
    nums_s.push(temp);
  } else {
   nums_s.push(nums_cur[i + 1]);
  }
}
```

### 우선순위

우선순위 경우의 수는 총 6개 이므로, 각 우선순위 모든 경우의 수를 나열한다.

```cpp
string prioritys[6] = {"+*-", "+-*", "*+-", "*-+", "-+*", "-*+"};
```

## 고생한 점
