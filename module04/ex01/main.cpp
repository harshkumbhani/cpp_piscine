#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "╔══════════════════════════════╗" << std::endl;
    std::cout << "║ Polymorphism with Virtual    ║" << std::endl;
    std::cout << "╚══════════════════════════════╝" << std::endl;

    Animal* dog = new Dog();
    Animal* cat = new Cat();

    dog->makeSound(); // Expected: Dog-specific sound
    cat->makeSound(); // Expected: Cat-specific sound

    delete dog;
    delete cat;

    std::cout << "╔══════════════════════════════╗" << std::endl;
    std::cout << "║   Brain Idea Manipulation    ║" << std::endl;
    std::cout << "╚══════════════════════════════╝" << std::endl;

    Dog *originalDog = new Dog();
    originalDog->setIdea(1, "Chase squirrels");
    std::cout << "Original Dog's first idea: " << originalDog->getIdea(1) << std::endl;

    Dog *copiedDog = new Dog(*originalDog); // Deep copy
    std::cout << "Copied Dog's first idea before change: " << copiedDog->getIdea(1) << std::endl;
    copiedDog->setIdea(90, "Sleep in the sun");
    std::cout << "Original Dog's first idea remains: " << originalDog->getIdea(90) << std::endl;

    delete originalDog;
    delete copiedDog;

    std::cout << "╔══════════════════════════════╗" << std::endl;
    std::cout << "║  Assignment Operator Check   ║" << std::endl;
    std::cout << "╚══════════════════════════════╝" << std::endl;

    Cat *cat1 = new Cat();
    cat1->setIdea(1, "Watch birds");
    Cat *cat2 = new Cat();
    *cat2 = *cat1; // Using assignment operator for deep copy
    cat2->setIdea(1, "Knock over plants");

    std::cout << "Cat1's first idea after Cat2 changed: " << cat1->getIdea(1) << std::endl;
    std::cout << "Cat2's first idea: " << cat2->getIdea(1) << std::endl;

    delete cat1;
    delete cat2;

    return 1;
}
