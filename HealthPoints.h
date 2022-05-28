//
// Created by 222ro on 21-May-22.
//

#ifndef MATAM_EX2_HEALTHPOINTS_H
#define MATAM_EX2_HEALTHPOINTS_H
#include <iostream>

class HealthPoints {
public:
    // TODO: Should we use init list for maxHP? Since we're validating it
    explicit HealthPoints(const int maxHP = 100) :
        m_maxHP(maxHP),
        m_currentHP(maxHP)
    {
        if(maxHP <= 0) {
            throw InvalidArgument();
        }
    }

    HealthPoints(const HealthPoints& healthPoints) = default;

    HealthPoints& operator=(const HealthPoints& healthPoints) {
        if(this == &healthPoints) {
            return *this;
        }
        
        m_maxHP = healthPoints.m_maxHP;
        m_currentHP = healthPoints.m_currentHP;
        return *this;
    }

    HealthPoints& operator+=(const int pointsToAdd) {
        if(m_currentHP + pointsToAdd > m_maxHP) {
            m_currentHP = m_maxHP;
        }

        if(m_currentHP + pointsToAdd < 0) {
            m_currentHP = 0;
        }
        
        m_currentHP += pointsToAdd;
        return *this;
    }
    
    HealthPoints& operator-=(const int pointsToSubtract) {
        if(m_currentHP - pointsToSubtract < 0) {
            m_currentHP = 0;
        }
        
        if(m_currentHP - pointsToSubtract > m_maxHP) {
            m_currentHP = m_maxHP;
        }
        
        m_currentHP -= pointsToSubtract;
        return *this;
    }

    class InvalidArgument {};

private:
    int m_maxHP;
    int m_currentHP;

    friend bool operator==(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2) {
        return healthPoints1.m_currentHP == healthPoints2.m_currentHP;
    }

    friend bool operator!=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2) {
        return healthPoints1.m_currentHP != healthPoints2.m_currentHP;
    }
    
    friend bool operator>=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2) {
        return healthPoints1.m_currentHP >= healthPoints2.m_currentHP;
    }
    
    friend bool operator>(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2) {
        return healthPoints1.m_currentHP > healthPoints2.m_currentHP;
    }
    
    friend bool operator<=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2) {
        return healthPoints1.m_currentHP <= healthPoints2.m_currentHP;
    }
    
    friend bool operator<(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2) {
        return healthPoints1.m_currentHP < healthPoints2.m_currentHP;
    }

    friend std::ostream& operator<<(std::ostream& output, const HealthPoints& healthPoints) {
        output << healthPoints.m_currentHP << "(" << healthPoints.m_maxHP << ")";
        return output;
    }
};

// TODO: need to deal with symmetry
HealthPoints operator+(const int pointsToAdd, const HealthPoints& healthPoints) {
    HealthPoints result = healthPoints;
    return result += pointsToAdd;
}

HealthPoints operator+(const HealthPoints& healthPoints, const int pointsToAdd) {
    HealthPoints result = healthPoints;
    return result += pointsToAdd;
}

// TODO: Should minus operator be symmetric?
HealthPoints operator-(const HealthPoints& healthPoints, const int pointToSubtract) {
    HealthPoints result = healthPoints;
    return result -= pointToSubtract;
}


#endif //MATAM_EX2_HEALTHPOINTS_H
