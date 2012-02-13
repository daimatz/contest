#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cassert>
#include <cmath>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<(x)<<endl;
using namespace std;

const int REST = (INT_MAX/100-1);

const int LENGTH_VARIETY_NUM = 14;
const int LENGTH_VARIETY[] = {1,2,3,4,5,6,7,8,10,12,14,16,24,32};

typedef enum {
  NATURAL,
  SHARP,
  DSHARP,
  FLAT,
  DFLAT,
} Special;

// 1音を表す
struct Note {
  // 高さ、長さ(1/32)
  int height, length;
  Special special;
  Note() {}
  Note(int h, int l, Special s) {
    height = h; length = l; special = s;
  }
  string encode() {
    char buf[32];
    string ret;
    sprintf(buf, "%d", height);
    return ret;
  }
  string toString() {
    char buf[32];
    string ret;
    sprintf(buf, "%d", height);
    ret += "H:"; ret += (height == REST ? "R" : buf);
    if (special == SHARP) ret += "#";
    if (special == DSHARP) ret += "##";
    if (special == FLAT) ret += "b";
    if (special == DFLAT) ret += "bb";
    sprintf(buf, "%d", length);
    ret += ", L:"; ret += buf;
    return ret;
  }
};

int specialToInt(Special s) {
  if (s == NATURAL) return 0;
  if (s == SHARP) return 1;
  if (s == DSHARP) return 2;
  if (s == FLAT) return -1;
  if (s == DFLAT) return -2;
}

// H4 音から見た高さを絶対的な高さと定義し、それを求める。
// 1オクターブ上の H5 音は 12
int abs_h(Note n) {
  int oct = (n.height / 7);
  int base = 12 * oct;
  switch (n.height % 7) {
  case 0: break;
  case 1: base += 1; break;
  case 2: base += 3; break;
  case 3: base += 5; break;
  case 4: base += 6; break;
  case 5: base += 8; break;
  case 6: base += 10; break;
  case -6: base += 1  - 12;  break;
  case -5: base += 3  - 12;  break;
  case -4: base += 5  - 12;  break;
  case -3: base += 6  - 12;  break;
  case -2: base += 8  - 12;  break;
  case -1: base += 10 - 12; break;
  }
  return base + specialToInt(n.special);
}

// 特徴量
int calc(vector<Note> melody) {
  int ret = 0;

  int i = 0;

  // 休符は飛ばす
  while (true) {
    if (i >= (int)melody.size()) return ret;
    if (melody[i].height == REST) i++;
    else break;
  }

  while (true) {
    Note prev = melody[i];
    i++;

    // 休符は飛ばす
    while (true) {
      if (i >= (int)melody.size()) return ret;
      if (melody[i].height == REST) i++;
      else break;
    }

    Note next = melody[i];

    ret += abs(abs_h(prev) - abs_h(next));
    //DEBUG(ret);
  }
  return ret;
}

// 文字列 s を文字列 c で分割して vector<string> で返す
vector<string> string_split(string s, string c) {
  vector<string> ret;
  for (int i=0, n; i <= (int)s.length(); i=n+1 ){
    n = s.find_first_of( c, i );
    if (n == (int)string::npos) n = s.length();
    string tmp = s.substr( i, n-i );
    ret.push_back(tmp);
  }
  return ret;
}

// 入力の parse
vector<Note> parse(string piece) {
  vector<Note> ret;

  // 一音ずつ区切る
  vector<string> notes = string_split(piece, ",");
  // 属性ごとに区切る
  for (int i = 0; i < (int)notes.size(); i++) {
    vector<string> property = string_split(notes[i], ":");
    int height = (property[0] == "" ? REST : atoi(property[0].c_str()));

    int cnt = 0;
    for (int i = 0; i < (int)property[1].size(); i++)
      if (property[1][i] == '.')
        cnt++;
    int base_length = 32 / atoi(property[1].c_str());
    int length = base_length;
    for (int i = 0; i < cnt; i++) {
      base_length /= 2;
      length += base_length;
    }

    Special special;
    if (property[2] == "") special = NATURAL;
    else if (property[2] == "s") special = SHARP;
    else if (property[2] == "x") special = DSHARP;
    else if (property[2] == "b") special = FLAT;
    else if (property[2] == "d") special = DFLAT;
    ret.push_back(Note(height, length, special));
  }

  return ret;
}

int powi(int x, int y) {
  if (y == 1) {
    return x;
  } else if (y % 2 == 0) {
    int k = powi(x, y/2);
    return k*k;
  } else {
    return x*powi(x, y-1);
  }
}

int randNextLengthIdx(int current_length_idx) {
  int prob[LENGTH_VARIETY_NUM];
  int sum = 0;
  for (int i = 0; i < LENGTH_VARIETY_NUM; i++) {
    prob[i] = sum + powi(2, LENGTH_VARIETY_NUM -abs(current_length_idx - i));
    sum += powi(2, LENGTH_VARIETY_NUM-abs(current_length_idx - i));
    //DEBUG(prob[i]);
  }
  int r = rand() % sum;
  for (int i = 0; i < LENGTH_VARIETY_NUM; i++)
    if (r < prob[i])
      return i;
}

int randNextNoteHeight(int current_note_height) {
  int prob[] = {2048,2048,1024,512,256,128,64,32,16,8,4,2,1};
  int sum = 0;
  for (int i = 0; i < 13; i++)
    sum += prob[i];
  int r = rand() % sum;
  for (int i = 0; i < 13; i++) {
    r -= prob[i];
    if (r < 0) {
      if (rand() % 2) return current_note_height + i;
      else return current_note_height - i;
    }
  }
}

vector<Note> compose(Note start_note, int min_length, int max_length, int score) {

  vector<Note> ret;

  Note current = start_note;

  while (true) {
    int current_length_idx;
    //DEBUG(current.length);
    for (int i = 0; i < LENGTH_VARIETY_NUM; i++)
      if (LENGTH_VARIETY[i] > current.length) {
        current_length_idx = i-1;
        break;
      }
    int next_length_idx = randNextLengthIdx(current_length_idx);
    if (min_length - LENGTH_VARIETY[next_length_idx] < -32) {
      next_length_idx = randNextLengthIdx(current_length_idx);
    }
    min_length -= LENGTH_VARIETY[next_length_idx];
    max_length -= LENGTH_VARIETY[next_length_idx];

    int current_note_height = abs_h(current);
    int next_note_height = randNextNoteHeight(current_note_height);
    int oct = next_note_height / 12;
    int relative = next_note_height - oct * 12;
    Note next;
    if (min_length < 0) {
      ret.push_back(Note(start_note.height, max_length, start_note.special));
      break;
    }

    switch (relative) {
    case 0: next = Note(oct*7, LENGTH_VARIETY[next_length_idx], NATURAL); break;
    case 1: next = Note(oct*7+1, LENGTH_VARIETY[next_length_idx], NATURAL); break;
    case 2: next = Note(oct*7+1, LENGTH_VARIETY[next_length_idx], SHARP); break;
    case 3: next = Note(oct*7+2, LENGTH_VARIETY[next_length_idx], NATURAL); break;
    case 4: next = Note(oct*7+3, LENGTH_VARIETY[next_length_idx], FLAT); break;
    case 5: next = Note(oct*7+3, LENGTH_VARIETY[next_length_idx], NATURAL); break;
    case 6: next = Note(oct*7+4, LENGTH_VARIETY[next_length_idx], NATURAL); break;
    case 7: next = Note(oct*7+4, LENGTH_VARIETY[next_length_idx], SHARP); break;
    case 8: next = Note(oct*7+5, LENGTH_VARIETY[next_length_idx], NATURAL); break;
    case 9: next = Note(oct*7+5, LENGTH_VARIETY[next_length_idx], SHARP); break;
    case 10: next = Note(oct*7+6, LENGTH_VARIETY[next_length_idx], NATURAL); break;
    case 11: next = Note(oct*7+7, LENGTH_VARIETY[next_length_idx], FLAT); break;
    case -1: next = Note(oct*7, LENGTH_VARIETY[next_length_idx], FLAT); break;
    case -2: next = Note(oct*7-1, LENGTH_VARIETY[next_length_idx], NATURAL); break;
    case -3: next = Note(oct*7-2, LENGTH_VARIETY[next_length_idx], SHARP); break;
    case -4: next = Note(oct*7-2, LENGTH_VARIETY[next_length_idx], NATURAL); break;
    case -5: next = Note(oct*7-3, LENGTH_VARIETY[next_length_idx], SHARP); break;
    case -6: next = Note(oct*7-3, LENGTH_VARIETY[next_length_idx], NATURAL); break;
    case -7: next = Note(oct*7-4, LENGTH_VARIETY[next_length_idx], NATURAL); break;
    case -8: next = Note(oct*7-4, LENGTH_VARIETY[next_length_idx], FLAT); break;
    case -9: next = Note(oct*7-5, LENGTH_VARIETY[next_length_idx], NATURAL); break;
    case -10: next = Note(oct*7-6, LENGTH_VARIETY[next_length_idx], SHARP); break;
    case -11: next = Note(oct*7-6, LENGTH_VARIETY[next_length_idx], NATURAL); break;
    }
    ret.push_back(next);
    current = next;
  }

  return ret;
}

int main(int argc, char *argv[]) {
  string sA, sB, sC, sD, sE, sF, sG;
  sA = "-3:4:,-2:4:,-1:4:,0:4:b,-1:4:,-2:4:,-3:4:,:4:,-1:4:,0:4:b,1:4:,2:4:,1:4:,0:4:b,-1:4:,:4:";
  sB = "3:4:,2:4:,1:4:,0:4:b,1:4:,2:4:,3:4:,:4:,1:4:,0:4:b,-1:4:,-2:4:,-1:4:,0:4:b,1:4:,:4:";
  sC = "3:4:,2:4:,1:4:,0:4:,1:4:,2:4:,3:4:,:4:,1:8:,0:4.:,-1:4:,-2:4:,:8:,-1:4.:,0:8:,1:8:";
  sD = "-6:8:,-6:8:,-6:8:,-4:8:,-2:8:,-2:8:,-2:8:,:8:,-5:8:,-5:8:,-5:8:,-3:8:,-2:8:,-2:8:,-2:8:,:8:,:8:,-2:8:,-2:8:,-1:8:b,-1:8:,-1:8:,-1:8:,-1:8:b,-2:4:,0:4:,1:4:,:4:";
  sE = "-6:8.:,-7:16:,-6:8:,-5:8:,-4:8:,-4:8:,-4:4:,-3:8.:,-4:16:,-5:8:,-6:8:,-5:4:,:4:,-3:8:,-5:4:,-5:8:,-4:8:,-4:8:,-3:8:,-3:8:,-4:8:,-4:8:,-5:8:,-5:8:,-6:4:,:4:";
  sF = "-6:2:,-5:4:,-6:8:,-5:8:,-4:4:,-2:4:,-4:4:,:4:,-5:4:,-5:4:,-6:4:,-5:4:,-4:2.:,:4:";
  sG = "-2:8.:,-1:16:,-2:8.:,-1:16:,-2:4:,-4:4:,-4:8.:,-3:16:,-4:8.:,-3:16:,-4:4:,-6:4:,-4:8:,:8:,-6:8.:,-5:16:,-4:8:,:8:,-6:8.:,-5:16:,-4:8.:,-4:16:,-2:8.:,-2:16:,-5:8.:,-4:16:,-5:4:";

  vector<Note> A = parse(sA), B = parse(sB), C = parse(sC), D = parse(sD), E = parse(sE), F = parse(sF), G = parse(sG);

  assert(calc(A) != calc(B));
  assert(calc(A) == calc(C));

  int scoreB = calc(B);
  if (scoreB == calc(D)) cout << "D has same score as B" << endl;
  if (scoreB == calc(E)) cout << "E has same score as B" << endl;
  if (scoreB == calc(F)) cout << "F has same score as B" << endl;

  srand((unsigned)time(NULL));
  vector<Note> H;
  while (true) {
    H = compose(G[0], 32*3, 32*4, calc(G));
    if (calc(H) == calc(G) && H[0].height == G[0].height) break;
  }
  for (int i = 0; i < (int)H.size(); i++) {
    cout << H[i].toString() << endl;
    //if (i != (int)H.size() - 1) cout << ",";
  }
  cout << endl;

  return 0;
}
