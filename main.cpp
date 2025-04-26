#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stack>
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

void setup(vector<Card>& deck, vector<stack<Card>>& column) {
    for(int i=0;i<7;i++){
        for(int j=i;j>=0;j--){
            column[i].push(deck[0]);
            if(j==0){column[i].top().flip();}
            //cout<<column[i].top().reveal()<<endl;
            deck.erase(deck.begin());
        }
    }
}
void display(vector<Card>& deck, vector<stack<Card>>& column, vector<stack<Card>>& ends){

    
    cout<<""<<endl;
    cout<<"______________________________________"<<endl;
    cout<<""<<endl;
    for(int i=0;i<13;i++){
        for(int j=0;j<7;j++){
            if(column[i].top().)
        }
        cout<<""<<endl;
    }
}


int main() {
    system("chcp 65001 > nul");
    system("cls");

    vector<Card> deck = createDeck();
    shuffleDeck(deck);
    vector<stack<Card>> column(7);
    vector<stack<Card>> ends(4);
    int wybor;

    cout<<"Wybierz poziom trudności"<<endl;
    cout<<"1. Latwy"<<endl;
    cout<<"2. Trudny"<<endl;
    cin>>wybor;
    system("cls");
    setup(deck, column);
    display(deck,column,ends);
    

    //for (Card& card : deck) {cout << card.reveal() << endl;}


    return 0;
}
