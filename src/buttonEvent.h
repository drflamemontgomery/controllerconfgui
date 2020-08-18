#ifndef BUTTONEVENT_H
#define BUTTONEVENT_H

#include <string>
#include <boost/any.hpp>

class ButtonEvent {
 private:
  boost::any source;
 public:
  ButtonEvent(boost::any s);
  boost::any getSource();
};

#endif
