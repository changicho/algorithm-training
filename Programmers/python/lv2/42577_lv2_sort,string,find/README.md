# 전화번호 목록
[링크](https://programmers.co.kr/learn/courses/30/lessons/42577)

### 난이도 2

## 정리 내용
- 정렬
- 문자열
- find

list를 정렬하고 싶을땐 sorted(list) 를 사용한다.

```python
sorted(list, key=key)
# key 옵션으로 len 옵션을 주면 길이로 비교
# 문자열의 경우 기본은 사전순
```

사전순으로 정렬하면 n번째 문자열은 n+1번째 보다 사전순으로 앞이므로, n번째 이후부터는 접두어가 될 수 없다.

문자열의 startswith(target) 메소드를 사용하면 접두어 여부를 판단 가능하다
문자열의 find(target) 메소드를 사용하면 찾을경우 index, 못찾을경우 -1을 반환한다.

zip을 이용해 다차원 list를 만들 수 있다.