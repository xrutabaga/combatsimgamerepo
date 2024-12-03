#include "Creature.h"
#include <random>

Creature::Creature(std::string name, int health, int armor, int versatility, int baseDamage)
{
    Name = name;
    Health = health;
    Armor = armor;
    Versatility = versatility;  // Initialize versatility stat
    BaseDamage = baseDamage;
}

Creature::~Creature() {}

void Creature::DisplayStats()
{
    std::cout << "Name: " << Name << std::endl;
    std::cout << "Health: " << Health << std::endl;
    std::cout << "Armor: " << Armor << std::endl;
    std::cout << "Versatility: " << Versatility << std::endl;
    std::cout << "Base Damage: " << BaseDamage << std::endl;
}

void Creature::Attack(Creature& target)
{
    // Calculate the attack damage with base damage + random d20 roll
    int attackDamage = BaseDamage + RollDamage();
    target.TakeDamage(attackDamage);
    std::cout << Name << " attacks " << target.GetName() << " for " << attackDamage << " damage!" << std::endl;
}

void Creature::TakeDamage(int damage)
{
    int finalDamage = damage - Armor;
    if (finalDamage < 0) finalDamage = 0; // No negative damage
    Health -= finalDamage;

    std::cout << Name << " takes " << finalDamage << " damage!" << std::endl;
}

int Creature::RollInitiative()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 20);

    int roll = dis(gen) + Versatility; // Add versatility to the roll
    std::cout << Name << " rolls initiative: " << roll << std::endl;
    return roll;
}

    // Roll a random d20 for attack damage
int Creature::RollDamage()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 20);  // Rolls a number between 1 and 20

    int roll = dis(gen);  // Get the d20 roll
    int damage = BaseDamage + roll;  // Add the base damage to the roll

    std::cout << Name << " rolls " << roll << " for damage!" << std::endl;

    return damage;
}
