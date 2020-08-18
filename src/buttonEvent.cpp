#include "buttonEvent.h"

ButtonEvent(boost::any s) {
  source = s;
}

boost::any ButtonEvent::getSource() {
  return source;
}
