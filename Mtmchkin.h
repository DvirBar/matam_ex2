#ifndef EX2_GAME_H
#define EX2_GAME_H
#include "Card.h"
#include <iostream>
#include <string>

/*
 * GameStatus:
 * MidGame - The game is still active and the player continues to encounter cards.
 * Win - The player reached level 10.
 * Loss - The player's HP is 0.
 */
enum class GameStatus {
    Win,
    Loss,
    MidGame
};

class Mtmchkin {
public:
    /*
     * C'tor of the game:
     *
     * @param playerName - The name of the player.
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     * @result
     *      An instance of Mtmchkin
     */
    Mtmchkin(const std::string playerName, const Card *cardsArray, int numOfCards);

    /*
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
     */
    void playNextCard();

    /*
     *  Check if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isOver() const;

    /*
     *  Get the status of the game:
     *
     *  @return
     *          GameStatus - the current status of the running game
     */
    GameStatus getGameStatus() const;

    /**
     * Destructor of Mtmchkin Class
     * Deletes the dynamically allocated cards array.
     */
    ~Mtmchkin();
    // TODO: Add default declaration of copy c'tor and overloading
private:
    Player m_player;
    GameStatus m_status;
    Card* m_cardsArray;
    const int m_numOfCards;
    int m_currentCard;
};

#endif // EX2_GAME_H
