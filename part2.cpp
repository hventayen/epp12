#include <iostream>
#include <string>
#include "FruitPrices.h"

using std::cout;
using std::endl;
using std::string;

template <typename T>
bool testAnswer(const string &nameOfTest, const T &received, const T &expected);

int main() {
  {
	FruitPrices fp;
	testAnswer("file reading 1", fp.readPriceList("pricelist1.txt"), 6);
	testAnswer("getHighestVariety(Apple)", fp.getHighestVariety("Apple"), string("Jazz"));
	testAnswer("getHighestVariety(Cherry)", fp.getHighestVariety("Cherry"), string("Ranier"));
	testAnswer("getHighestVariety(Banana)", fp.getHighestVariety("Banana"), string(""));
  }
  {
	FruitPrices fp;
  testAnswer("file reading 1", fp.readPriceList("pricelist1.txt"), 6);
	testAnswer("getHighestVariety(Apple)", fp.getHighestVariety("Apple"), string("Jazz"));
	testAnswer("getHighestVariety(Cherry)", fp.getHighestVariety("Cherry"), string("Ranier"));
	testAnswer("getHighestVariety(Banana)", fp.getHighestVariety("Banana"), string(""));
  // reading second file
	testAnswer("file reading 2", fp.readPriceList("pricelist2.txt"), 7);
	testAnswer("getHighestVariety(Apple)", fp.getHighestVariety("Apple"), string("Braeburn"));
	testAnswer("getHighestVariety(Cherry)", fp.getHighestVariety("Cherry"), string("Ranier"));
	testAnswer("getHighestVariety(Banana)", fp.getHighestVariety("Banana"), string("Burro"));
  }
}

template <typename T>
bool testAnswer(const string &nameOfTest, const T &received, const T &expected) {
    if (received == expected) {
        cout << "\033[32m" << "PASSED "
				<< "\033[0m" << nameOfTest << ": expected and received " << received << endl;
        return true;
    }
    cout << "FAILED " << nameOfTest << ": expected " << expected << " but received " << received << endl;
    return false;
}
