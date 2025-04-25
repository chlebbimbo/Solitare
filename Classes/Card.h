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
    return value+" "+suit+"  "+(faceUp ? "odwrocona" : "zakryta");
    }
    void flip() { faceUp = !faceUp; }
    bool isRed() const { return suit == "♦️" || suit == "❤️"; }
};