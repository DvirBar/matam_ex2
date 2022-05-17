#include "Card.h"
#include "utilities.h"

static void handleBattle(Player &player, CardStats stats) {
    bool isWin = false;
    
    if(player.getAttackStrength() >= stats.force) {
        isWin = true;
        player.levelUp();
        player.addCoins(stats.loot);
    }
    
    else {
        player.damage(stats.hpLossOnDefeat);
    }
    
    printBattleResult(isWin);
}

Card::Card(CardType type, const CardStats &stats):
    m_effect(type),
    m_stats(stats)
{}

void Card::applyEncounter(Player &player) const {
    switch (m_effect) {
        case CardType::Battle: {
            handleBattle(player, m_stats);
            break;
        }
       
        case CardType::Heal: {
            if(player.pay(m_stats.cost)) {
                player.heal(m_stats.heal);
            }
            break;
        }
        
        case CardType::Buff: {
            if(player.pay(m_stats.cost)) {
                player.buff(m_stats.buff);
            }
            break;
        }
            
        case CardType::Treasure: {
            player.addCoins(m_stats.loot);
            break;
        }
        
        default: {
            break;
        }
    }
}

void Card::printInfo() const {
    switch (m_effect) {
        case CardType::Battle: {
            printBattleCardInfo(m_stats);
            break;
        }
        
        case CardType::Buff: {
            printBuffCardInfo(m_stats);
            break;
        }
        
        case CardType::Heal: {
            printHealCardInfo(m_stats);
            break;
        }
            
        case CardType::Treasure: {
            printTreasureCardInfo(m_stats);
            break;
        }
        
        default: break;
    }
}
