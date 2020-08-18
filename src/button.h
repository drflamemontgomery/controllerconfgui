#ifndef BUTTON_H
#define BUTTON_H

#include <stdio.h>

using namespace std;

class Button {
private:
  vector<ButtonListener> listeners;
public:
  void addListener(ButtonListener listener);
  void removeListener(ButtonListener listener);
  void notifyAll();
};

#endif
