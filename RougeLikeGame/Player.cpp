//Player.cpp

//Shannon Simpson
//Shannon.Simpson@uky.edu
//PA3

#include "Player.h"

using namespace std;

Player::Player()
{
    string name;
    cout << "What shall we call you here? ";
    cin >> name;
	cout << endl;
	if (name == "God")
	{
		Entity::setName(name);
		character = 'G';
		startHP = 10000000000000000;
	}
	else
	{
		character = '@';
		Entity::setName(name);
		startHP = 100;
	}
		Entity::setDisplayChar(character);
		Creature::setMaxHP(startHP);
}
Player::~Player()
{

}

int Player::getScore()
{
    return m_score;
}
void Player::setScore(int score)
{
    m_score = score;
}

int Player::getExperience()
{
    return m_xp;
}
void Player::setExperience(int xp)
{
    m_xp = xp;
}




