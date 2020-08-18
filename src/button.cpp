#include "button.h"

void Button::addListener(ButtonListener listener) {
  listeners.push_back(listener);
};

void Button::removeListener(ButtonListener listener) {
  for(int i = 0; i < listeners.size(); i++) {
	if(listeners.at(i) == listener) {
	  listeners.erase(i);
	  break;
	}
  }
};

void Button::notifyAll() {
  for(ButtonListener listener : listeners) {
	listener.handleButtonEvent(new ButtonEvent(this));
  }
};
