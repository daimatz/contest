#include <iostream>
#include <string>
using namespace std;

int speed(int w) {
  if (w < 2 * 6 + 3) return 0;
  if (w < 15 * 6 + 3) return 1;
  if (w < 33 * 6 + 3) return 2;
  if (w < 54 * 6 + 3) return 3;
  if (w < 79 * 6 + 3) return 4;
  if (w < 107 * 6 + 3) return 5;
  if (w < 138 * 6 + 3) return 6;
  if (w < 171 * 6 + 3) return 7;
  if (w < 207 * 6 + 3) return 8;
  if (w < 244 * 6 + 3) return 9;
  if (w < 284 * 6 + 3) return 10;
  if (w < 326 * 6 + 3) return 11;
  return 12;
}

string direction(int dir, int w) {
  if (speed(w) == 0) return "C";
  int d = dir * 10;
  if (d < 1125)  return "N";
  if (d < 3375)  return "NNE" ;
  if (d < 5625)  return "NE"  ;
  if (d < 7875)  return "ENE" ;
  if (d < 10125) return "E"   ;
  if (d < 12375) return "ESE" ;
  if (d < 14625) return "SE"  ;
  if (d < 16875) return "SSE" ;
  if (d < 19125) return "S"   ;
  if (d < 21375) return "SSW" ;
  if (d < 23625) return "SW"  ;
  if (d < 25875) return "WSW" ;
  if (d < 28125) return "W"   ;
  if (d < 30375) return "WNW" ;
  if (d < 32625) return "NW"  ;
  if (d < 34875) return "NNW" ;
  return "N"   ;
}

int main() {
  int dir, w;
  cin >> dir >> w;
  cout << direction(dir, w) << ' ' << speed(w) << endl;
}
