#include <iostream>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<(x)<<endl;
using namespace std;

struct MyDate {
  int y,m,d;
  MyDate() {}
  MyDate(int _y, int _m, int _d) {
    y = _y; m = _m; d = _d;
  };
  bool operator<(MyDate t) {
    return (y < t.y || (y == t.y && m < t.m) || (y == t.y && m == t.m && d < t.d));
  }
};

struct MyTime {
  int h,m,s;
  MyTime(int _h, int _m, int _s) {
    h = _h; m = _m; s = _s;
  }
};

MyDate currentDate() {
  tm *date;
  time_t now;
  time(&now);
  date = localtime(&now);

  MyDate d;
  d.y = date->tm_year + 1900;
  d.m = date->tm_mon + 1;
  d.d = date->tm_mday;

  return d;
}

bool isLeap(int y) {
  return (y % 4 == 0 && (y % 400 == 0 || y % 100 != 0));
}

// startからendまでの2月29日の数
int numOfLeapDay(MyDate start, MyDate end) {
  int ret = 0;
  if (isLeap(start.y) && start < MyDate(start.y,3,1))
    ret++;
  if (isLeap(end.y) && MyDate(end.y,2,29) < end)
    ret++;
  for (int i = start.y+1; i <= end.y-1; i++)
    if (isLeap(i))
      ret++;
  return ret;
}

MyTime f(int a, int b, int c, int n) {
  MyDate today = currentDate();
  MyDate born(a, b, c); // 生まれた日
  MyDate dead(a+n+1, b, c); // a+n+1 年目になった瞬間死ぬ

  int living = 365*(n+1) + numOfLeapDay(born,dead); // 生きる日数
  //DEBUG(living);
  int now = 365*(today.y-born.y) + numOfLeapDay(born,today); // 今日までの日数

  int sec = (int) (60*60*24 * (double)now / (double)living); // 1日に換算したときの今の秒
  int hour = sec / (60*60);
  sec -= hour * 60*60;
  int min = sec / 60;
  sec -= min * 60;
  return MyTime(hour,min,sec);
}

int main(int argc, char *argv[]) {
  int a, b, c, n;
  while (cin >> a >> b >> c >> n) {
    MyTime t = f(a,b,c,n);
    cout << t.h << ":" << t.m << ":" << t.s << endl;
  }
  return 0;
}
