#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Class definition for Pet
class Pet
{
   public:
     // Constructor, no default
     Pet(string nm, string kind);

     // return the name
     string getName() const;

     // return the type
     string getType() const;

     // return the string when pet speaks
     string speak() const;

     // return the string when pet comes
     string come() const;

     // return the string when pet does tricks
     string do_tricks() const;

   private:
     string name;
     char type;

     static const char DOG = 'D';
     static const char CAT = 'C';
     static const char BIRD = 'B';
     static const char SNAKE= 'S';
};

// This program includes child classes for 4 kinds of Pets: Dog, Cat, Bird and Snake.
class Dog : public Pet
{
  public:
    // Constructor for a Dog
    Dog(string name);
  private:
};

class Cat : public Pet
{
  public:
    // Constructor for a Cat
    Cat(string name);
  private:
};

class Bird : public Pet
{
  public:
    // Constructor for a Bird
    Bird(string name);
  private:
};
class Snake : public Pet
{
  public:
    // Constructor for a Snake
    Snake(string name); 
  private:
};

int main()
{
	// Done: the type will no longer be needed once you modify the code
	// to have classes for all 4 kinds of Pets.
    Dog dog("Padfoot");
    Cat cat("Cruickshanks");
    Bird bird("Hedwig");
    Snake snake("Nagini");

	// The code below should not have to change to use the new classes.
    cout << "When " << dog.getName() << " the " << dog.getType() << " speaks he says " << dog.speak() << endl; 
    cout << "When I tell him to come, he " << dog.come() << endl;
    cout << "His tricks are " << dog.do_tricks() << endl;
    cout << "********\n" << endl;

    cout << "When " << cat.getName() << " the " << cat.getType() << " speaks he says " << cat.speak() << endl; 
    cout << "When I tell him to come, he " << cat.come() << endl; 
    cout << "His tricks are " << cat.do_tricks() << endl;
    cout << "********\n" << endl;

    cout << "When " << bird.getName() << " the " << bird.getType() << " speaks he says " << bird.speak() << endl; 
    cout << "When I tell him to come, he " << bird.come() << endl; 
    cout << "His tricks are " << bird.do_tricks() << endl;
    cout << "********\n" << endl;

    cout << "When " << snake.getName() << " the " << snake.getType() << " speaks he says " << snake.speak() << endl; 
    cout << "When I tell him to come, he " << snake.come() << endl; 
    cout << "His tricks are " << snake.do_tricks() << endl;
    cout << "********\n" << endl;

    return 0;
}

// Constructor for a Pet
Pet::Pet(string nm, string kind) : name(nm), type(toupper(kind[0]))
{ 
    if (type != DOG && type != CAT && type != BIRD && type != SNAKE)
    {
       cout << "Illegal pet, you can't keep a " << kind << " as a Pet!";
       exit(1);
    }
}

// Constructor for a Dog
Dog::Dog(string name):Pet(name, "DOG")
{
  // deliberately empty
}
// Constructor for a Cat
Cat::Cat(string name):Pet(name, "CAT")
{
  // deliberately empty
}
// Constructor for a Bird
Bird::Bird(string name):Pet(name, "BIRD")
{
  // deliberately empty
}
// Constructor for a Snake
Snake::Snake(string name):Pet(name, "SNAKE")
{
  // deliberately empty
}

// return the pet's name
string Pet::getName() const
{ 
    return name;
}

// return the pet's type
string Pet::getType()  const
{
    switch(type) {
       case DOG:
         return "dog";
       case CAT:
         return "cat";
       case BIRD:
         return "bird";
       case SNAKE:
         return "snake";
     }
     return "";
}

// return the string when pet does speaks
string Pet::speak() const
{
    switch(type) {
       case DOG:
         return "woof, woof!";
       case CAT:
         return "meow, meow!";
       case BIRD:
         return "tweet, tweet.";
       case SNAKE:
         return "hiss, hiss.";
     }
     return "";
 }

 // return the string when pet does comes
 string Pet::come() const
 {
    switch(type) {
      case DOG:
        return "runs over!";
      case CAT:
        return "walks away!";
      case BIRD:
        return "flies over!";
      case SNAKE:
        return "slithers around!";
     }
     return "";
 }

// return the string when pet does tricks
string Pet::do_tricks() const
{
    if (type == DOG)
      return "begs, sits, rolls over.";
    else if (type == CAT)
      return "purrs, licks my hand.";
    else if (type == BIRD)
      return "screeches, lands on my finger.";
    else if (type == SNAKE)
      return "eats his prey whole.";
    return "";
}

