
#include <iostream>
#include <string>
#include "Entity.h"
#include <SFML/Graphics.hpp>

#ifndef ENEMY_H
#define ENEMY_H



class Enemy : public Entity {
public:

	Enemy();
	Enemy(std::string Name, std::string info, int element, int health_point, int attack);

	int damageDealt(int attack);
	void setTexture(const sf::Texture& texture);
    const sf::Sprite& getSprite() const;
    int get_Health() ;
private:
	sf::Texture texture;
    sf::Sprite sprite;

};



#endif
