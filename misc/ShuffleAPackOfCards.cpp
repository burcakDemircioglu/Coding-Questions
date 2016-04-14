/*
Write a program to shuffle a pack of cards
The approach:-
Initialize a cards array and set the seed for rand based on time.

For each array index generate a random index and swap the elements.

Output the cards array.
*/

#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

class Card{
	private:
		string type;
		int value;
	public:
		Card(string t, int v){type=t;value=v;};
		string getType(){return type;}
		int getValue(){return value;}
};

int main(){
	srand(time(NULL));
	vector<Card*> deck;
	int deckIndex=0;

	for(int i=0;i<13;i++)
		deck.push_back(new Card("sinek", i+1));
	for(int i=0;i<13;i++)
		deck.push_back(new Card("kupa", i+1));
	for(int i=0;i<13;i++)
		deck.push_back(new Card("maca", i+1));
	for(int i=0;i<13;i++)
		deck.push_back(new Card("karo", i+1));

	for(int i=0;i<52;i++){
		int randIndex=rand()%52;
		Card *temp=deck[i];
		deck[i]=deck[randIndex];
		deck[randIndex]=temp;
	}

	for(int i=0;i<deck.size();i++)
		cout<<i+1<<") "<<deck[i]->getType()<<deck[i]->getValue()<<endl;
	
	for (int i = 0; i < deck.size(); i++)
    	delete deck[i];

	return 0;
}

