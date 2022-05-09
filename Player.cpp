#include "Player.h"
#include "utilities.h"
#include <cstring>


char* Player::allocateNameAndCopy(const char* name)
{
    return strcpy(new char[strlen(name) + 1], name);
}

// TODO: Should we implement inside or outside of parentheses (using ternary operator like douchebags)?
// TODO: Check piazza for default name in case of invalid string
Player::Player(const char* name, const int maxHP, const int force)
{
    m_name = allocateNameAndCopy(name);

    // TODO: define initial level and coins?
    m_level = 1;

    if (force < 0)
    {
        m_force = DEFAULT_FORCE;
    }
    else
    {
        m_force = force;
    }

    if (maxHP < 0)
    {
        m_max_HP = DEFAULT_MAXHP;
        m_HP = DEFAULT_MAXHP;
    }
    else
    {
        m_max_HP = maxHP;
        m_HP = maxHP;
    }

    m_coins = 0;
}

Player::Player(const Player& player) :
        m_name(allocateNameAndCopy(player.m_name)),
        m_level(player.m_level),
        m_force(player.m_force),
        m_max_HP(player.m_max_HP),
        m_HP(player.m_HP),
        m_coins(player.m_coins)
{ }


Player& Player::operator=(const Player& player)
{
    if (this == &player)
    {
        return *this;
    }

    char* tempName = allocateNameAndCopy(player.m_name);
    m_level = player.m_level;
    m_force = player.m_force;
    m_max_HP = player.m_max_HP;
    m_HP = player.m_HP;
    m_coins = player.m_coins;
    delete[] m_name;
    m_name = tempName;

    return *this;
}

void Player::printInfo()
{
    printPlayerInfo(m_name, m_level, m_force, m_HP, m_coins);
}


void Player::levelUp()
{
    if (m_level == MAX_LEVEL)
    {
        return;
    }

    m_level++;
}

int Player::getLevel () const
{
    return m_level;
}

void Player::buff(int forceToBuff)
{
    if (forceToBuff < 0)
    {
        return;
    }

    m_force += forceToBuff;
}

void Player::heal(int HPToHeal)
{
    if (HPToHeal < 0)
    {
        return;
    }

    if (m_HP + HPToHeal >= m_max_HP)
    {
        m_HP = m_max_HP;
    }

    else
    {
        m_HP += HPToHeal;
    }
}

void Player::damage(int HPToDamage)
{
    if (HPToDamage < 0)
    {
        return;
    }

    if (m_HP - HPToDamage <= 0)
    {
        m_HP = 0;
    }
    else
        m_HP -= HPToDamage;
}

bool Player::isKnockedOut() const
{
    return !m_HP;
}

void Player::addCoins(int coinsToAdd)
{
    if (coinsToAdd < 0)
    {
        return;
    }

    m_coins += coinsToAdd;
}

bool Player::pay(int coinsToPay)
{
    if ((coinsToPay < 0) || (m_coins - coinsToPay < 0))
    {
        return false;
    }

    m_coins -= coinsToPay;

    return true;

}

int Player::getAttackStrength() const
{
    return m_level + m_force;
}