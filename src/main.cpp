#include <iostream>
#include <string.h>
#include <SFML/Graphics.hpp>
    
int main(void) {
	
  sf::RenderWindow window(sf::VideoMode(400, 400), "Controller Config");

  sf::Texture gamepadskin;
  if(!gamepadskin.loadFromFile("src/assets/controller.png")) {
	return 2;
  }
  sf::Sprite gamepad;
  gamepad.setTexture(gamepadskin);
  gamepad.setPosition(0,0);
  //sf::Sprite layer[];
  
  while(window.isOpen()) {
	sf::Event event;
	while(window.pollEvent(event)) {
	  if(event.type == sf::Event::Closed) {
		window.close();
	  }
	}

	window.clear();
	window.draw(gamepad);
	window.display();
  }
  
  return 0;
}
