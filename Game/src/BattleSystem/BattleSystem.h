#pragma once
#include "../all_characters/hero/Hero.h"
#include "../Enemy.h"
#include "../dungeon/Dungeon.h"
#include "../Skills/Skills.h"

class BattleSystem {
public:
    BattleSystem(Hero& h, Enemy& e, Dungeon& d);
    void startBattle();
    void updateDefence();

private:
    Hero& hero;
    Enemy& enemy;
    int activeDefenceBonus = 0;
    int defenceDurationLeft = 0;
    Dungeon& dungeon;



    bool isHeroAlive() const;
    bool isEnemyAlive() const;

    void heroTurn();
    void useBasicAttack();
    void useSkill();
    void useItem();
    void useDefence();
    void enemyTurn();

};