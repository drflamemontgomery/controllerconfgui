#include <SFML/Graphics.hpp>

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

std::string exec(const char* cmd) {
  std::array<char, 128> buffer;
  std::string result;
  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
  if (!pipe) {
	throw std::runtime_error("popen() failed!");
  }
  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
	result += buffer.data();
  }
  return result;
}

bool getInput(void) {
  std::string list = exec("ls /dev/input");
  int lines = 0;
  for(int i = 0; i < list.length(); i++) {
	if(list[i] == '\n')
	  lines++;
  }

  std::string inputs[lines] = {""};
  int input_pointer = 0;
  for(int i = 0; i < list.length(); i++) {
	if(list[i] == '\n')
	  input_pointer += 1;
	else
	  inputs[input_pointer] += list[i];
  }

  lines = 0;
  
  
  return true;
}


int main(void) {
	
  sf::RenderWindow window(sf::VideoMode(600, 600), "Controller Config");
  
  sf::Texture gamepadskin;
  if(!gamepadskin.loadFromFile("src/assets/controller.png")) {
	return 2;
  }
  sf::Sprite gamepad;
  gamepad.setTexture(gamepadskin);
  gamepad.setPosition((window.getSize().x-gamepadskin.getSize().x)/2,
					  (window.getSize().y-gamepadskin.getSize().y)/2);
   
  while(window.isOpen()) {
	sf::Event event;
	
	while(window.pollEvent(event)) {
	  if(event.type == sf::Event::Closed) {
		window.close();
	  }
	}
	
	window.clear(sf::Color(255, 255, 255, 255));
	window.draw(gamepad);
	window.display();
  }
  
  return 0;
}
