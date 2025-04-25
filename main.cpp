#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Classes/Card.h"
using namespace std;
vector<Card> createDeck() {
    vector<Card> deck;
    string suits[] = {"♦️", "♣️", "❤️", "♠️"};
    string values[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

    for(int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck.emplace_back(values[j], suits[i]);
        }
    }

    return deck;
}

void shuffleDeck(vector<Card>& deck) {
    srand(time(0));
    for(int i=deck.size()-1; i>0; i--){
        int j = rand() % deck.size();
        swap(deck[i], deck[j]);
    }
}
int main() {
    system("chcp 65001 > nul");
    system("cls");

    vector<Card> deck = createDeck();
    int wybor;
    cout<<"Wybierz poziom trudności"<<endl;
    cout<<"1. Latwy"<<endl;
    cout<<"2. Trudny"<<endl;
    cin>>wybor;

    shuffleDeck(deck);
    for (Card& card : deck) {cout << card.reveal() << endl;}


    return 0;
}
