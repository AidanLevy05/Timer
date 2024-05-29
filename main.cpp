#include <iostream>
#include <unistd.h>
using namespace std;

void clear();
void validNum(int &time);
void timer(int m, int s);

int main() {

  // vars
  int minutes = 0;
  int seconds = 0;

  // input
  cout << "Number minutes >> ";
  cin >> minutes;
  cout << endl;
  validNum(minutes);

  cout << "Number seconds >> ";
  cin >> seconds;
  cout << endl;
  validNum(seconds);

  // start timer
  timer(minutes, seconds);
  

  return 0;
}
void clear() {
  cout << "\033[2J\033[1;1H";
}
void validNum(int &time) {
  if (time < 0) {
    cout << "No negative numbers. Try again!" << endl;
    cin >> time;
  }
}
void timer(int m, int s) {

  if (m == 0 && s == 0) {
    clear();
    cout << "Timer over!" << endl;
  } else {
    
    clear();
    cout << "M: " << m << " | S: " << s << endl;

    // reset seconds 0 -> 59 
    if (s == 0) {
      s = 59;
      if (m >= 1) m--;
    } else {
      s--;
    }
    
    usleep(1000000);
    timer(m, s);
    
  }
  
}
