# B. Dictionary

[link](https://codeforces.com/contest/1674/problem/B)

time : 13 min

## 풀이

> 브루트 포스로 풀이

'ab'에서부터 'zy'까지 총 650개의 문자 종류가 있고 각 쿼리마다 문자를 입력받을 때 index를 반환해야 한다.

갯수가 크지 않으므로 brute force방법으로 모두 미리 만들고 쿼리마다 값을 반환한다.

이 때 겹치는 경우에 대한 부분을 수학적 규칙으로 찾는 방법도 있지만, 'aa'부터 하나하나 생성해가면서 만들어도 제한시간에 크게 제약을 받지않는다.