#pragma once
#include <string>
using namespace std;

class Card {
 private:

    string value;
    string suit;
    bool faceUp = false;

 public:

    Card(string value, string suit, bool faceUp = false);

    string reveal() const {
      if(value == "10"){
         return value+""+suit;
      } else {
         return value+suit+" ";
      }
    
    }
    void flip() { faceUp = !faceUp; }
    bool isRed() const { return suit == "♦️" || suit == "❤️"; }
    bool isUp() const {return faceUp;}
};