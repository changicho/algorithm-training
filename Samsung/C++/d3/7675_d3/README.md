# 7675. 통역사 성경이

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWqPvqoqSLQDFAT_&categoryId=AWqPvqoqSLQDFAT_&categoryType=CODE)

난이도_d3_47%

## 정리

실행시간 6ms
제일 빠른 실행시간 C++ 5ms

문자열 문제는 이론은 쉬우나 구현이 생각보다 복잡하다.
첫 글자만 미리 비교한 뒤, 두 번째 글짜부터 탐색을 이어나가면서 이름 여부를 판단.
단어를 입력 받고 탐색을 끝낸 뒤, 단어 여부에 따라 count 를 증가.

. ! ? 가 나오는 경우 단어의 갯수를 출력한다. 이전에 이전까지 단어였으면 count 증가하는 옵션을 추가한다.
