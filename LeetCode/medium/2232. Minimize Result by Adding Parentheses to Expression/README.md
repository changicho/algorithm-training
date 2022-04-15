# 2232. Minimize Result by Adding Parentheses to Expression

[링크](https://leetcode.com/contest/weekly-contest-288/problems/minimize-result-by-adding-parentheses-to-expression/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

expression의 길이를 L이라 하자.

괄호를 넣을 수 있는 경우의 수는 약 (L/2)^2개 이다. 모든 경우를 탐색할 경우 탐색에 O(L^2)의 시간 복잡도를 사용한다.

중간에 괄호를 넣는데 걸리는 시간 복잡도는 O(L)이므로 모든 경우를 탐색하며 정답을 생성할 때의 시간 복잡도는 O(L^3)이다.

### 공간 복잡도

숫자를 구분하는데 들어가는 공간 복잡도는 O(L)이다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(L^3)    |    O(L)     |

입력받은 식에서 숫자2개를 각각 숫자1, 숫자2라고 하자.

각각의 숫자에는 괄호가 하나만 들어갈 수 있다.

따라서 불가능한 경우를 제외하고 모든 경우를 탐색해 정답을 구한다.

index단위로 관리하며 정답을 구하기 위해 2중 for문을 사용한다.

이는 아래와 같이 구현한다.

```cpp
string minimizeResult(string expression) {
  int target = expression.find('+');
  string num1 = expression.substr(0, target),
          num2 = expression.substr(target + 1);

  int len1 = num1.length(), len2 = num2.length();
  // O(L)
  string answer = "(" + expression + ")";
  int answerVal = stoi(num1) + stoi(num2);

  // O(L^2)
  for (int left = 0; left < len1; left++) {
    for (int right = 1; right <= len2; right++) {
      // O(L)
      string firstNum = num1.substr(0, left);
      string secondNum = num1.substr(left);
      string thirdNum = num2.substr(0, right);
      string fourthNum = num2.substr(right);

      int cur = 0;
      cur += stoi(secondNum) + stoi(thirdNum);
      if (firstNum != "") cur *= stoi(firstNum);
      if (fourthNum != "") cur *= stoi(fourthNum);

      if (cur < answerVal) {
        answerVal = cur;
        answer =
            firstNum + "(" + secondNum + "+" + thirdNum + ")" + fourthNum;
      }
    }
  }

  return answer;
}
```

## 고생한 점
