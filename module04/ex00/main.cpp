#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void) {
  std::cout << "╔══════════════════════════════╗" << std::endl;
  std::cout << "║ Polymorphism with Virtual    ║" << std::endl;
  std::cout << "╚══════════════════════════════╝" << std::endl;

  // Animal instances demonstrating polymorphism
  const Animal *genericAnimal = new Animal();
  const Animal *cat = new Cat();
  const Animal *dog = new Dog();

  // Display types and make sounds using polymorphism
  std::cout << "╔══════════════════════════════╗" << std::endl;
  std::cout << "║           Get Types          ║" << std::endl;
  std::cout << "╚══════════════════════════════╝" << std::endl;

  std::cout << cat->getType() << std::endl; // Type is part of sound output
  std::cout << dog->getType() << std::endl; // Type is part of sound output

  std::cout << "╔══════════════════════════════╗" << std::endl;
  std::cout << "║         Make Sound           ║" << std::endl;
  std::cout << "╚══════════════════════════════╝" << std::endl;

  genericAnimal->makeSound();
  cat->makeSound();
  dog->makeSound();

  // Clean up
  delete genericAnimal;
  delete cat;
  delete dog;

  // ASCII art for section division
  std::cout << "\n╔══════════════════════════════╗" << std::endl;
  std::cout << "║ Non-Polymorphic Behavior     ║" << std::endl;
  std::cout << "╚══════════════════════════════╝" << std::endl;

  // WrongAnimal instances demonstrating static binding
  const WrongAnimal *wrongGenericAnimal = new WrongAnimal();
  const WrongAnimal *wrongCat = new WrongCat();

  // Display types and make sounds without polymorphism
  std::cout << "╔══════════════════════════════╗" << std::endl;
  std::cout << "║           Get Types          ║" << std::endl;
  std::cout << "╚══════════════════════════════╝" << std::endl;
  std::cout << wrongCat->getType() << std::endl;
  std::cout << "╔══════════════════════════════╗" << std::endl;
  std::cout << "║         Make Sound           ║" << std::endl;
  std::cout << "╚══════════════════════════════╝" << std::endl;

  wrongGenericAnimal->makeSound();
  wrongCat->makeSound();

  // Clean up
  delete wrongGenericAnimal;
  delete wrongCat;

  return 0;
}
