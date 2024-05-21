#include <iostream>
#include <string>
#include "Enemy.h"
#include "Entity.h"
Enemy::Enemy() : Entity() {};

Enemy::Enemy(std::string Name, std::string info, int element, int health_point, int attack) {
	this->Name = Name;
	this->info = info;
	this->element = element;
	this->health_point = health_point;
	this->attack = attack;
}

int Enemy::damageDealt(int attack) {
	//std::cout << "use basic attack" << std::endl;
	damage = attack;
	return damage;
}

void Enemy::setTexture(const sf::Texture& texture) {
    this->texture = texture;
    this->sprite.setTexture(this->texture);
}

const sf::Sprite& Enemy::getSprite() const {
    return this->sprite;
}
int Enemy::get_Health()  {
    return this->health_point;
}

