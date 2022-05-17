//
// Created by 222ro on 06-May-22.
//

#ifndef HW2_PLAYER_H
#define HW2_PLAYER_H

const int DEFAULT_MAXHP = 100;
const int DEFAULT_FORCE = 5;
const int MAX_LEVEL = 10;
const int INIT_LEVEL = 1;
const int INIT_COINS = 0;

class Player {
public:
    /**
     * Constructor of Player Class
     *
     * @param name - Player's Name, made only with english characters, without spaces.
     * @param maxHP - Player's Max Health Points.
     * @param force - Player's Force Points.
     */
    explicit Player(const char* name, const int maxHP = DEFAULT_MAXHP, const int force = DEFAULT_FORCE);

    /**
     * Copy Constructor of Player Class
     * Copies every parameter of given player object to "this" player object.
     * @param player - Player object to copy.
     */
    Player(const Player &player);

    /**
     * Destructor of Player Class
     * Deletes the dynamically allocated name of the player.
     */
    ~Player();

    /**
     * Player Class Assignment Operator
     *
     * @param player - Player other object to assign.
     * @return
     *      This Player object after assignment.
     */
    Player &operator=(const Player &player);

    /**
     * printInfo: Prints the player's parameters.
     */
    void printInfo();

    /**
     * levelUp: adds 1 to a player's m_level parameter.
     */
    void levelUp();

    /**
     * getLevel: Returns player's m_level parameter.
     */
    int getLevel() const;

    /**
     * buff: Increases the player's m_force Parameter with given amount.
     * A player is unable to buff a negative number of force points. Function regards the negative number as 0.
     *
     * @param forceToBuff - Amount of force points to add.
     */
    void buff(int forceToBuff);

    /**
     * heal: Increases the player's m_HP parameter with given amount, to a maximum of maxHP.
     * A player is unable to heal a negative number of HP. Function regards the negative number as 0.
     * @param HPToHeal - Amount of HP to add
     */
    void heal(int HPToHeal);

    /**
     * damage: Decreases the player's m_HP parameter with given amount, to a minimum of 0 HP.
     * A Player is unable to damage a negative number of HP. Function regards the negative number as 0.
     * @param HPToDamage - Amount of HP to subtract
     */
    void damage(int HPToDamage);

    /**
     * isKnockedOut: Returns true if player's m_HP parameter is 0, else false.
     */
    bool isKnockedOut() const;

    /**
     * addCoins: Adds the given amount of coins to a player's m_coins parameter.
     * A player is unable to add a negative amount of coins. Function regards the negative number as 0.
     * @param coinsToAdd - Amount of coins to add.
     */
    void addCoins(int coinsToAdd);

    /**
     * pay: Subtracts the given amount of coins from a player's m_coins parameter.
     * A player is unable to pay more coins than he currently has.
     * A player is unable to pay a negative amount of coins.
     * @param coinsToPay - Amount of coins to subtract
     * @return
     *      true - Coins successfully subtracted from player's m_coins parameter
     *      false - An illegal transaction has occurred, player's m_coins parameter hasn't changed.
     */
    bool pay(int coinsToPay);

    /**
     * getAttackStrength: Returns player's Attack Strength.
     * Attack Strength is defined as sum of player's m_level and m_force parameters.
     */
    int getAttackStrength() const;

private:
    char* m_name;
    int m_level;
    int m_force;
    int m_max_HP;
    int m_HP;
    int m_coins;

    static char* allocateNameAndCopy(const char* str);
};

#endif // HW2_PLAYER_H
