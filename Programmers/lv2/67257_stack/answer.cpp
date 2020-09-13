#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string prioritys[6] = {"+*-", "+-*", "*+-", "*-+", "-+*", "-*+"};
vector<long long> numbers;
vector<char> operators;

void parsing(string expression) {
  long long temp;
  string num_s = "";

  for (char c : expression) {
    // 숫자인 경우
    if (c != '*' && c != '-' && c != '+') {
      num_s += c;
    } else {
      numbers.push_back(stoll(num_s));
      operators.push_back(c);
      num_s = "";
    }
  }

  if (num_s != "") {
    numbers.push_back(stoll(num_s));
  }
}

long long oper(long long a, long long b, char oper_c) {
  if (oper_c == '*') {
    return a * b;
  }
  if (oper_c == '+') {
    return a + b;
  }
  return a - b;
}

long long calcul(string priority) {
  long long ans = 0;

  vector<long long> nums_cur = numbers;
  vector<char> opers_cur = operators;

  for (int p = 0; p < 3; p++) {
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

    // 다음 iteration을 위해 초기화
    nums_cur.resize(0);
    opers_cur.resize(0);
    while (!nums_s.empty()) {
      nums_cur.push_back(nums_s.top());
      nums_s.pop();
    }
    reverse(nums_cur.begin(), nums_cur.end());
    while (!opers_s.empty()) {
      opers_cur.push_back(opers_s.top());
      opers_s.pop();
    }
    reverse(opers_cur.begin(), opers_cur.end());
  }

  return nums_cur.front();
}

long long solution(string expression) {
  long long answer = 0;

  parsing(expression);

  for (string priority : prioritys) {
    long long cur_answer;

    cur_answer = calcul(priority);
    answer = max(answer, abs(cur_answer));
  }

  return answer;
}

struct TestCase {
  string expression;
  long long result;
};

int main() {
  vector<TestCase> tcs = {
      {"100-200*300-500+20", 60420}, {"50*6-3*2", 300}, {"100+10", 110}};

  for (TestCase tc : tcs) {
    int answer = solution(tc.expression);

    cout << "answer : " << tc.result << ", myAnswer : " << answer << "\n";
  }

  return 0;
}