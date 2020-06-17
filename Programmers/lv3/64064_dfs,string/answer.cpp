#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool visited_nick[8];
int ban_size = 0;
vector<string> user_id;
vector<string> banned_id;
vector<string> answers;

bool canBan(string id, string ban) {
  if (id.length() != ban.length()) {
    return false;
  }

  for (int i = 0; i < ban.length(); i++) {
    if (ban[i] == '*') {
      continue;
    }
    if (ban[i] != id[i]) {
      return false;
    }
  }
  return true;
}

void dfs(int index, vector<string> answer) {
  if (index == ban_size) {
    string temp = "";
    sort(answer.begin(), answer.end());
    for (string a : answer) {
      temp += a + ",";
    }
    answers.push_back(temp);
    return;
  }

  for (int i = 0; i < user_id.size(); i++) {
    if (visited_nick[i]) {
      continue;
    }

    if (canBan(user_id[i], banned_id[index])) {
      answer.push_back(user_id[i]);
      visited_nick[i] = true;

      dfs(index + 1, answer);

      answer.pop_back();
      visited_nick[i] = false;
    }
  }
}

int solution(vector<string> c_user_id, vector<string> c_banned_id) {
  ban_size = c_banned_id.size();
  user_id = c_user_id;
  banned_id = c_banned_id;
  vector<string> answer;
  dfs(0, answer);

  sort(answers.begin(), answers.end());

  answers.erase(unique(answers.begin(), answers.end()), answers.end());

  return answers.size();
}

struct TestCase {
  vector<string> user_id;
  vector<string> banned_id;
  int answer;
};

void clear() {
  ban_size = 0;
  memset(visited_nick, false, sizeof(visited_nick));
  user_id.resize(0);
  banned_id.resize(0);
  answers.resize(0);
}

int main() {
  vector<TestCase> TC{
      {{"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"fr*d*", "abc1**"}, 2},
      {{"frodo", "fradi", "crodo", "abc123", "frodoc"},
       {"*rodo", "*rodo", "******"},
       2},
      {{"frodo", "fradi", "crodo", "abc123", "frodoc"},
       {"fr*d*", "*rodo", "******", "******"},
       3}

  };

  for (TestCase test : TC) {
    clear();
    int s = solution(test.user_id, test.banned_id);

    cout << "MyAnswer : " << s << ", RealAnswer : " << test.answer << "\n";
  }

  return 0;
}