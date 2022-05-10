#include "Mtmchkin.h"
#include "Card.h"
#include "Player.h"

// TODO: Validations?
Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards):
    m_player(playerName),
    m_status(GameStatus::MidGame),
    m_cardsArray(cardsArray),
    m_numOfCards(numOfCards),
    m_currentCard(0)
{}

GameStatus Mtmchkin::getGameStatus() const {
    return m_status;
}

void Mtmchkin::playNextCard() {
    if(m_currentCard == m_numOfCards) {
        m_currentCard = 0;
    }
    
    Card card = m_cardsArray[m_currentCard];
    card.printInfo();
    card.applyEncounter(m_player);
    
    if(m_player.isKnockedOut()) {
        m_status = GameStatus::Loss;
    }
    
    if(m_player.getLevel() == MAX_LEVEL) {
        m_status = GameStatus::Win;
    }
    
    m_currentCard++;
    m_player.printInfo();
}

bool Mtmchkin::isOver() const {
    return m_status != GameStatus::MidGame;
}
