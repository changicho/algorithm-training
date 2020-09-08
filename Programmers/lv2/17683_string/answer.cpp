#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, char target) {
  vector<string> result;
  string temp = "";

  for (char c : str) {
    if (c == target) {
      result.push_back(temp);
      temp = "";
    } else {
      temp += c;
    }
  }
  if (temp != "") {
    result.push_back(temp);
  }
  return result;
}

struct Music {
  int length;
  string played;
  string name;
};

string transform(string melody) {
  string result = "";

  for (int i = 0; i < melody.length(); i++) {
    if (i + 1 < melody.length() && melody[i + 1] == '#') {
      result += tolower(melody[i]);
      i++;
    } else {
      result += melody[i];
    }
  }

  return result;
}

int parseTime(string time) {
  string temp = "";
  vector<string> times = split(time, ':');

  return stoi(times[0]) * 60 + stoi(times[1]);
}

Music parsing(string musicinfo) {
  Music result;
  string temp = "";
  vector<string> temps = split(musicinfo, ',');

  result.length = abs(parseTime(temps[0]) - parseTime(temps[1]));
  result.name = temps[2];

  temps[3] = transform(temps[3]);

  result.played = "";
  for (int i = 0; i < result.length; i++) {
    result.played += temps[3][i % temps[3].length()];
  }

  return result;
}

string solution(string m, vector<string> musicinfos) {
  m = transform(m);
  string answer = "(None)";
  int answerLength = 0;

  vector<Music> musics;

  for (string musicinfo : musicinfos) {
    Music cur = parsing(musicinfo);

    musics.push_back(cur);
  }

  for (Music music : musics) {
    if (music.played.find(m) != string::npos) {
      if (answerLength < music.length) {
        answer = music.name;
        answerLength = music.length;
      }
    }
  }

  return answer;
}

struct TestCase {
  string m;
  vector<string> musicinfos;
  string answer;
};

int main() {
  vector<TestCase> tcs = {
      {"ABCDEFG",
       {"12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"},
       "HELLO"},
      {"CC#BCC#BCC#BCC#B",
       {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"},
       "FOO"},
      {"ABC",
       {"12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"},
       "WORLD"},
  };

  for (TestCase tc : tcs) {
    string answer = solution(tc.m, tc.musicinfos);

    cout << "answer : " << tc.answer << ", myAnswer : " << answer << "\n";
  }

  return 0;
}