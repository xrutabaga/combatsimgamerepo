#pragma once
#include <string>
#include <iostream>

class Creature
{
public:
    // Constructor
    Creature(std::string name, int health, int armor, int versatility, int baseDamage);  // Constructor declaration

    // Destructor
    ~Creature();

    // Display creature stats
    void DisplayStats();

    // Combat Methods
    void Attack(Creature& target);
    void TakeDamage(int damage);

    // Getter for Name
    std::string GetName() const { return Name; }

    // Initiative Roll Method
    int RollInitiative();

    int RollDamage();  // Declare RollDamage function

   

private:
    std::string Name;
    int Health;
    int Armor;
    int Versatility;  // New stat for initiative calculation
    int BaseDamage;   // New stat for attack damage calculation
};


