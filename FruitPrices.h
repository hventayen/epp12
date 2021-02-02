#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
/*
Fruit struct: a Fruit type who has attributes such as name, variety,
and price.
Class FruitPrices: reads in fruit information from price list into obj which is
of type Fruit, then stores it into a vector.
*/
struct Fruit
{
  // fruit name
  std::string name;
  // fruit variety
  std::string variety;
  // fruit price
  double price;
};

class FruitPrices
{
private:
  // holds fruit objects that have been made
  std::vector<Fruit> fruitDatabase;
  // fruit object
  Fruit obj;

public:
  FruitPrices();
  // takes in the filename of the pricelist and reads in the data to its
  // member variables, returning the number of fruits read in that file
  int readPriceList (std::string filename);
  // return its variety with the highest price
  std::string getHighestVariety (std::string fruit);
};
// the default constructor
FruitPrices::FruitPrices()
{

}
// method which takes in the filename of the pricelist and reads in the data to
// its member variables. It should return the number of fruits that were read
// from the file
int FruitPrices::readPriceList (std::string filename)
{
  int count = 0;
  std::ifstream fruitList;
  // open file
  fruitList.open(filename);
  // make sure file is open
  if (!fruitList.is_open())
  {
    std::cout << "Could not open." << std::endl;
  }
  // read data in
  while(!fruitList.eof())
  {
    fruitList >> obj.name >> obj.variety >> obj.price;
    // push values into vector
    fruitDatabase.push_back(obj);
    // count when an object is recorded
    count++;
  }
  // close file
  fruitList.close();
  // while loop counts an extra loop through the while loop, fixes that
  count--;
  return count;
}
// given a fruit name, return its variety with the highest price. If the fruit
// does not exist, return the empty string (“”). E.g.,
// getHighestVariety(“Apple”) should return Jazz
std::string FruitPrices::getHighestVariety (std::string fruit)
{
  int fruitfound = 0;
  double highestPrice = 0.0;
  std::string highestVariety;
  std::vector<Fruit>::iterator it;
  // iterates through the vectors
  for (it = fruitDatabase.begin(); it != fruitDatabase.end(); it++)
  {
    // looks only for fruit with the same name as the one we are looking for
    if (it->name == fruit)
    {
      // shows everytime we find the fruit needed
      fruitfound++;
      // once we have a bunch of the same fruit, we find one with highest price
      if (it->price > highestPrice)
      {
        // keep the variety with the highest price
        highestPrice = it->price;
        highestVariety = it->variety;
      }
    }
    // check
    // std::cout << it->name << " " << it->variety << " " << it->price << std::endl;
  }
  // returns an empty string if the fruit does not exist
  if (fruitfound == 0)
  {
    return "";
  }
  return highestVariety;
}
