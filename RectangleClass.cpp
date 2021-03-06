#include <iostream>
using namespace std;

// Rectangle has a vertical height and horizontal width
// The class below is a rectangle. It has two private
// data members: height and width.
class Rectangle {
  public:

  // Default constructor declaration
  // Sets height and width to the unit rectangle which is a square 1x1 size.
  Rectangle(int h = 1, int w = 1);

  // add - Adds the given addHeight to height and addWidth to width
  // @param int addHeight is a given value to add to an invoking object's height
  // @param int addWidth is a given value to add to an invoking object's width
  // @returns void
  void add(int addHeight, int addWidth);
  
  // set - Sets the height to new_height and width to new_width
  // @param int new_height is a given value to change an invoking object's height to 
  // @param int new_width is a given value to change an invoking object's width to 
  // @returns void
  void set(int new_height, int new_width);

  // draw - Function uses height as the vertical dimension (outer loop) and width as the 
  //  horizontal dimension (inner loop) to draw the rectangle with '#' characters.
  // @returns void
  void draw();

  // Accessor function for width
  // @returns a width value
  int getWidth() const { return width;}
  
  // Accessor function for height
  // @returns a height value
  int getHeight() const { return height;}

  // isSquare -  Function that determines if a rectangle is a square (i.e. height is equal to width)
  // @returns a bool value
  bool isSquare();
  
  private:
    int height;
    int width;
};

// Default constructor implementation
// Sets height and width to the unit rectangle which is a square 1x1 size.
Rectangle::Rectangle(int h, int w)
{
  height = 1;
  width = 1;
}

// "add" member function implementation
// Modifies invoking object by adding addHeight to height and adding addWidth to width
// precondition: an initialized object of the Rectangle class
// postcondition: an object of the Rectangle class with, potentially, a new height and/or width
void Rectangle::add(int addHeight, int addWidth)
{
  height += addHeight;
  width += addWidth;
}

// "set" member function implementation
// Changes invoking object's height to new_height and width to new_width
// precondition: an initialized object of the Rectangle class
// postcondition: an object of the Rectangle class with a new height and width
void Rectangle::set(int new_height, int new_width)
{
  height = new_height;
  width = new_width;
}

// "draw" member function implementation
// Uses the height in an outer loop and the width in an inner loop to draw the 
//  rectangle with '#' characters.
// precondition: an initialized object of the Rectangle class
// postcondition: displays the Rectangle on screen using '#' characters
void Rectangle::draw()
{
  // Outer loop for height (rows)
  for(int i = 0; i < height; i++)
  {
    // Inner loop for width (columns)
    for(int j = 0; j < width; j++)
    {
      cout << "#";
    }
    // New line after each row
    cout << endl;
  }
}

// "isSquare" member function implementation
// Determines if a given rectangle is also a square (i.e. height is equal to width)
// returns the result of a comparison between getHeight() and getWidth()
//  of the invoking object
// precondition: an initialized object of the Rectangle class
// postcondition: a value of "true" if height = width, or a "false" value if not
bool Rectangle::isSquare()
{
  return (getHeight() == getWidth());
}


int main() 
{
  // Declare 2 rectangles
  Rectangle r1, r2;
  
  // Draw the unit rectangle
  cout << "unit rectangle" << endl;
  r1.draw();
  
  // Set, print dimensions and draw
  r1.set(4, 3);
  cout << "r1 is " << r1.getHeight() << " x " << r1.getWidth() << endl;
  r1.draw();
  
  // Assign, increment, print dimensions and draw
  r2 = r1;
  r2.add(3, 4);
  cout << "r2 is " << r2.getHeight() << " x " << r2.getWidth() << endl;
  r2.draw();
  
   // Call isSquare on Rectangle r2 and print the result
   if (r2.isSquare())
     cout << "r2 is a square" << endl;
   else
     cout << "r2 is not a square" << endl;
  return 0;
}

