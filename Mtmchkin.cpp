#include "Mtmchkin.h"
#include "Card.h"
#include "Player.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards):
    m_player(playerName),
    m_numOfCards(numOfCards)
{
    m_cardsArray = new Card[numOfCards];
    for(int i = 0; i < numOfCards; i++) {
        m_cardsArray[i] = cardsArray[i];
    }
    
    m_status = GameStatus::MidGame;
    m_currentCard = 0;
}

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

Mtmchkin::~Mtmchkin() {
    delete[] m_cardsArray;
}
