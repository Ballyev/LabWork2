#include <gtest/gtest.h>
#include "../src/include/Character/Character.h"
#include "../src/include/Enemy/Enemy.h"
#include "../src/include/EnemyBoss.h"
#include "../src/include/Hero/Hero.h"
#include "../src/include/Warrior/Warrior.h"
#include "../include/Rogue/Rogue.h"
#include "../include/Mage/Mage.h"
#include "../src/include/obj/Item.h"
#include "../src/include/obj/Potion.h"
#include "../src/include/obj/Scroll.h"
#include "../src/include/obj/Armor.h"
#include "../src/include/obj/Weapon.h"
#include "../src/include/Skills/Skills.h"
#include "../src/include/Skills/Attack.h"
#include "../src/include/Skills/Magic.h"
#include "../src/include/Skills/Defence.h"
#include "../src/include/Dungeon/Dungeon.h"

TEST(CharacterTest, TakeDamage) {
    Enemy enemy("Гоблин", 50, 10, 10, 10);
    enemy.takeDamage(20);
    EXPECT_EQ(enemy.health, 30);

    enemy.takeDamage(40);
    EXPECT_EQ(enemy.health, 0);
}

TEST(HeroTest, Defend) {
    Hero hero(1, 0, 10, 5, "Рыцарь", 100);
    hero.defend(hero.currentDefendCooldown, hero.originalDefence);
    EXPECT_GT(hero.defence, 5);
}

TEST(CharacterTest, AttackTarget) {
    Hero hero(1, 0, 15, 5, "Рыцарь", 100);
    Enemy enemy("Гоблин", 50, 10, 10, 10);
    hero.attackTarget(enemy);
    EXPECT_EQ(enemy.health, 35);
}

TEST(HeroTest, LevelUp) {
    Warrior warrior("Артур", 1, 40, 10, 5, 100, 0);
    EXPECT_EQ(warrior.level, 1);
    EXPECT_EQ(warrior.experience, 40);

    warrior.gainExperience(60);
    warrior.levelUp();
    EXPECT_EQ(warrior.level, 2);
    EXPECT_EQ(warrior.experience, 0);
    EXPECT_EQ(warrior.attack, 13);
    EXPECT_EQ(warrior.defence, 7);
}

TEST(WarriorTest, PowerStrike) {
    Warrior warrior("Воин", 2, 0, 10, 5, 100, 10);
    unsigned int baseDamage = 10;
    warrior.powerStrike(baseDamage);
    EXPECT_EQ(warrior.rage, 0);
}


TEST(RogueTest, SneakAttack) {
    Rogue rogue(1, 0, 10, 5, "Тень", 100, 80, 30);
    unsigned int damage = rogue.sneakAttack(10);
    EXPECT_GT(damage, 10);
}

TEST(RogueTest, UseScroll) {
    Rogue rogue(1, 0, 10, 5, "Тень", 100, 80, 30);
    auto scroll = std::make_unique<Scroll>("Свиток скрытности", "Увеличивает скрытность", true, 3, 20);
    rogue.useScroll(std::move(scroll));
    EXPECT_GT(rogue.stealth, 80);
}


TEST(MageTest, Heal) {
    Mage mage(1, 0, 10, 5, "Маг", 50, 5, 10);
    mage.heal();
    EXPECT_GT(mage.health, 50);
}

TEST(MageTest, UsePotion) {
    Mage mage(1, 0, 10, 5, "Маг", 100, 5, 10);
    Potion potion("Зелье огня", "Наносит урон", true, 0, 0, 20);
    Enemy enemy("Гоблин", 50, 10, 10, 10);
    mage.usePotion(&potion, enemy);
    EXPECT_EQ(enemy.health, 30);
}


TEST(EnemyTest, IsAlive) {
    Enemy enemy("Гоблин", 50, 10, 10, 10);
    EXPECT_TRUE(enemy.isAlive());
    enemy.takeDamage(50);
    EXPECT_FALSE(enemy.isAlive());
}


TEST(BossTest, UltimateAbility) {
    Hero hero(1, 0, 20, 10, "Рыцарь", 100);
    Boss boss("Дракон", 100, 20, 10, 20, 1, false);

    boss.ultimateAbility(hero);
    EXPECT_LT(hero.health, 100);
}


TEST(ItemTest, Use) {
    Item item("Ключ", "Открывает дверь", false);
    testing::internal::CaptureStdout();
    item.use();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("cannot be used directly"), std::string::npos);
}


TEST(PotionTest, RestoreHealth) {
    Potion potion("Зелье здоровья", "", true, 20, 3, 0);
    testing::internal::CaptureStdout();
    potion.restoreHealth();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("restores 20 health points"), std::string::npos);
}


TEST(ArmorTest, AbsorbDamage) {
    Armor armor("Платяная броня", "", false, 10, 3);
    testing::internal::CaptureStdout();
    armor.absorbDamage(5);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("поглотила урон"), std::string::npos);
}


TEST(WeaponTest, Upgrade) {
    Weapon weapon("Меч", "", false, 10, 5);
    weapon.upgrade();
    EXPECT_EQ(weapon.damage, 20);
}


TEST(SkillsTest, UpdateCooldown) {
    Attack attack(2, "Удар", "", 3, true, 10);
    attack.currentCooldown = 2;
    attack.updateCooldown();
    EXPECT_EQ(attack.currentCooldown, 1);
}

TEST(AttackTest, ComboAttack) {
    Enemy enemy("Гоблин", 50, 10, 10, 10);
    Attack attack(2, "Удар клинком", "Базовая комбо-атака", 3, true, 10);
    attack.comboAttack(enemy);
    EXPECT_EQ(enemy.health, 30);
}



TEST(DefenceTest, ShieldBlock) {
    Defence defence(5, 2, "Щит", "", 3, true);
    defence.shieldBlock();
    EXPECT_EQ(defence.defenceBoost, 5);
}


TEST(DungeonTest, GenerateRooms) {
    Dungeon dungeon(1);
    dungeon.generate(5);
    EXPECT_EQ(dungeon.rooms.size(), 5);
}

TEST(RoomTest, HasAliveEnemies) {
    Room room;
    auto enemy = std::make_unique<Enemy>("Гоблин", 50, 10, 10, 10);
    room.addEnemy(std::move(enemy));
    EXPECT_TRUE(room.hasAliveEnemies());

    room.enemies[0]->health = 0;
    EXPECT_FALSE(room.hasAliveEnemies());
}
