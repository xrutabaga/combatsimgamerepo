// CreatureCombatSim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Creature.h"

int main()
{
    // Create two creatures with different versatility values
    Creature shoak("Shoak", 100, 50, 5, 10);  // Versatility 5 Base Damage 10
    Creature taoi("Taoi", 80, 40, 3, 7);     // Versatility 3 Base Damage 7

    // Display initial stats
    shoak.DisplayStats();
    taoi.DisplayStats();

    // Roll initiative
    int shoakInitiative = shoak.RollInitiative();
    int taoiInitiative = taoi.RollInitiative();

    // Compare and determine the order of combat based on initiative
    if (shoakInitiative > taoiInitiative)
    {
        std::cout << shoak.GetName() << " goes first!" << std::endl;

        // First attack - Winner (Shoak) attacks
        shoak.Attack(taoi);

        // Second attack - Loser (Taoi) attacks
        taoi.Attack(shoak);

        // Third attack - Winner (Shoak) attacks again
        shoak.Attack(taoi);

        // Fourth attack - Loser (Taoi) attacks again
        taoi.Attack(shoak);
    }
    else
    {
        std::cout << taoi.GetName() << " goes first!" << std::endl;

        // First attack - Winner (Taoi) attacks
        taoi.Attack(shoak);

        // Second attack - Loser (Shoak) attacks
        shoak.Attack(taoi);

        // Third attack - Winner (Taoi) attacks again
        taoi.Attack(shoak);

        // Fourth attack - Loser (Shoak) attacks again
        shoak.Attack(taoi);
    }

    // Display final stats
    shoak.DisplayStats();
    taoi.DisplayStats();

    return 0;
}
