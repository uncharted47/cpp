#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void printSeparator(const std::string &message) {
    std::cout << "\n===== " << message << " =====\n" << std::endl;
}

int main() {
    printSeparator("TESTING MATERIA SOURCE");

    // Test MateriaSource creation and basic functionality
    MateriaSource* src = new MateriaSource();

    // Create materias for learning
    AMateria* ice1 = new Ice();
    AMateria* ice2 = new Ice();
    AMateria* ice3 = new Ice();
    AMateria* cure1 = new Cure();
    AMateria* cure2 = new Cure();
    AMateria* cure3 = new Cure();

    // Learn materias (up to 4)
    src->learnMateria(ice1);
    src->learnMateria(cure1);
    src->learnMateria(ice2);
    src->learnMateria(cure2);

    // Try to learn more than 4 (should fail and print message)
    src->learnMateria(ice3);
    src->learnMateria(cure3);

    // Must manually free these since MateriaSource didn't take ownership
    delete ice3;
    delete cure3;

    // Test creating materias
    printSeparator("TESTING CREATE MATERIA");
    AMateria* ice_clone = src->createMateria("ice");
    AMateria* cure_clone = src->createMateria("cure");
    AMateria* unknown = src->createMateria("unknown");

    std::cout << "Created ice materia of type: " << ice_clone->getType() << std::endl;
    std::cout << "Created cure materia of type: " << cure_clone->getType() << std::endl;
    std::cout << "Unknown type materia: " << (unknown ? "created (ERROR)" : "NULL (correct)") << std::endl;

    // Test MateriaSource copy constructor and assignment operator
    printSeparator("TESTING MATERIASOURCE COPY");

    MateriaSource* src_copy = new MateriaSource(*src);
    std::cout << "Testing copied MateriaSource:" << std::endl;
    AMateria* ice_from_copy = src_copy->createMateria("ice");
    AMateria* cure_from_copy = src_copy->createMateria("cure");

    std::cout << "Created from copy - ice materia of type: " << ice_from_copy->getType() << std::endl;
    std::cout << "Created from copy - cure materia of type: " << cure_from_copy->getType() << std::endl;

    // Test Character functionality
    printSeparator("TESTING CHARACTER");

    Character* me = new Character("me");
    Character* bob = new Character("bob");

    // Equip materias to character
    me->equip(ice_clone);
    me->equip(cure_clone);
    me->equip(ice_from_copy);
    me->equip(cure_from_copy);

    // Try to equip more than 4 (should fail)
    AMateria* extra_ice = src->createMateria("ice");
    me->equip(extra_ice); // This should print "No more space for materia"

    // Use materias
    std::cout << "Using materias:" << std::endl;
    me->use(0, *bob); // Use ice
    me->use(1, *bob); // Use cure
    me->use(-1, *bob); // Invalid index
    me->use(4, *bob); // Invalid index

    // Unequip and re-equip
    printSeparator("TESTING UNEQUIP");
    me->unequip(0); // Unequipping ice_clone
    me->use(0, *bob); // Should do nothing since slot is now empty

    // Now we can equip extra_ice
    me->equip(extra_ice);
    me->use(0, *bob); // Should use ice

    // Character copy constructor test
    printSeparator("TESTING CHARACTER COPY");
    Character* clone = new Character(*me);
    std::cout << "Clone name: " << clone->getName() << std::endl;
    std::cout << "Original using materia:" << std::endl;
    me->use(0, *bob);
    std::cout << "Clone using materia:" << std::endl;
    clone->use(0, *bob);

    // Test using after freeing original
    printSeparator("TESTING MEMORY MANAGEMENT");

    // Create a new materia and immediately delete its source
    AMateria* temp_materia = src->createMateria("ice");
    Character* temp_char = new Character("temporary");
    temp_char->equip(temp_materia);
    delete src; // Delete the source, but materia still exists

    std::cout << "Using materia after source deleted:" << std::endl;
    temp_char->use(0, *bob); // Should still work

    // Cleanup all memory
    printSeparator("CLEANUP");
    delete src_copy;
    delete me;
    delete bob;
    delete temp_char;

    // Any unequipped materias must be manually freed
    // For real projects, we'd need better tracking of these

    return 0;
}