#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Classes/Card.h"

using namespace std;

//Check the print length
int findLargest(const vector<vector<Card>> columns){
    int res = columns[0].size();
    for(int i=0;i<7;i++){
        if(res < columns[i].size()) {
            res = columns[i].size();
        }
    }
    return res-1;
}
// Function to create a deck of cards
vector<Card> createDeck() {
    vector<Card> deck;
    string suits[] = {"♦️", "♣️", "❤️", "♠️"};
    string values[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck.emplace_back(values[j], suits[i]);
        }
    }
    return deck;
}

// Function to shuffle the deck
void shuffleDeck(vector<Card>& deck) {
    srand(time(0));
    for (int i = deck.size() - 1; i > 0; i--) {
        int j = rand() % deck.size();
        swap(deck[i], deck[j]);
    }
}


void setup(vector<Card>& deck, vector<vector<Card>>& columns) {
    for (int i = 0; i < 7; i++) { 
        for (int j = 0; j <= i; j++) { 
            columns[i].push_back(deck.front()); 
            if (j == i) { // Flip the last card in the column
                columns[i].back().flip();
            }
            deck.erase(deck.begin()); // Remove the card from the deck
        }
    }
}

// Function to display Solitare
void display(const vector<Card>& deck, const vector<vector<Card>>& columns, const vector<vector<Card>>& ends, int deckTop) {

    cout<<deck[deckTop].reveal()+"               ";
    cout<<""<<endl;
    cout << "_______________________________________" << endl;

    // Display the columns row by row
    for (int i = 0; i < findLargest(columns); i++) { 
        for (int j = 0; j < 7; j++) { // Loop through each column
            if (i < columns[j].size()) { 
                if (columns[j][i].isUp()) {
                    cout << columns[j][i].reveal() + "   ";
                } else {
                    cout << "xxx   ";
                }
            } else {
                cout << "      "; // Empty space
            }
        }
        cout << endl;
    }
}

void execute(int difficulty, string move, vector<Card>& deck, const vector<vector<Card>>& columns, const vector<vector<Card>>& ends, int& deckTop){
    if(move == "draw"){ //If input is draw
        if(deck.size() == 0){cout<<"Nie ma z czego dobierać!"<<endl; return;}//Check if deck is empty
        if(deckTop>=difficulty){
        deckTop-=difficulty;
        return;
        } else {
            shuffleDeck(deck);
            deckTop = deck.size()-1;
            return;
        }
    }
}

int main() {
    system("chcp 65001 > nul");
    system("cls");

    vector<Card> deck = createDeck();
    shuffleDeck(deck);


    vector<vector<Card>> columns(7); 
    vector<vector<Card>> ends(4); 

    string move;
    int difficulty = 1;

    system("cls");

    setup(deck, columns);
    int deckTop = deck.size()-1;
    display(deck, columns, ends, deckTop);

    while(move != "stop"){
        cin>>move;
        system("cls");
        execute(difficulty, move, deck, columns, ends, deckTop);
        display(deck, columns, ends, deckTop);
    }
    

    return 0;
}