//
// Created by 222ro on 21-May-22.
//

#ifndef MATAM_EX2_HEALTHPOINTS_H
#define MATAM_EX2_HEALTHPOINTS_H

class HealthPoints {
public:
    explicit HealthPoints(const int maxHP = 100) :
        m_maxHP(maxHP),
        m_currentHP(maxHP)
    { }

    HealthPoints(const HealthPoints& healthPoints) :
        m_maxHP(healthPoints.m_maxHP),
        m_currentHP(healthPoints.m_currentHP)
    { }

    HealthPoints& operator=(const HealthPoints& healthPoints) {
        if(this == &healthPoints) {
            return *this;
        }
        m_maxHP = healthPoints.m_maxHP;
        m_currentHP = healthPoints.m_currentHP;
        return *this;
    }

    HealthPoints& operator+=(const int pointsToAdd) {
        if((m_currentHP + pointsToAdd) > m_maxHP) {
            m_currentHP = m_maxHP;
        }
        m_currentHP += pointsToAdd;
        return *this;
    }

private:
    int m_maxHP;
    int m_currentHP;

    friend bool operator==(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2) {
        return healthPoints1.m_currentHP == healthPoints2.m_currentHP;
    }

    friend bool operator!=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2) {
        return healthPoints1.m_currentHP != healthPoints2.m_currentHP;
    }
};

// TODO: need to deal with symmetry
HealthPoints operator+(const int pointsToAdd, const HealthPoints& healthPoints1) {
    HealthPoints result(healthPoints1);
    return (result += pointsToAdd);
}

HealthPoints operator+(const HealthPoints& healthPoints1, const int pointsToAdd) {
    HealthPoints result(healthPoints1);
    return (result += pointsToAdd);
}


#endif //MATAM_EX2_HEALTHPOINTS_H
