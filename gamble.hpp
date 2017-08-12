/* 52 cards total 1 means ace, 2 means 2, 3 means 3... 11 means jack,12 means queen and 13 means king
  kings, queens and jacks are 10 points, ace is special it can be 1 or 11 depending on the hand*/
#include "gamble.h"
#include <iostream>
#include <unistd.h>
#include <vector>
#include <cmath>
using std::vector;
using std::cin;
using std::cout;
#define dsplyVal cout << "Your card's value: " << sum(player_cards) << "\nDealer's card's value: " << sum(dealer_cards) << '\n'; cout << "You have "<< player_cards.size() << " cards : "; for (i=0;i<player_cards.size() - 1;i++){ cout << getVal(player_cards[i]) << ", "; } cout << "\n"; cout << "Dealer has "<< dealer_cards.size() << " cards : "; for (i=0;i<dealer_cards.size() - 1;i++) { cout << getVal(dealer_cards[i]) << ", "; } cout << "\n"

int slots(const int all_cash){ //This is seriously bad just don't play it
	long long int bet;
	/*1 = apple 2 = cherry 3 = peach 4 = banana 5 = orange 6 = BAR 7 = GOLDBAR
	Slot machine has a total of 3 slots and each slot can be in one of the states listed above
	The price will be determinated if 2 out of 2 slots have the same state
	PRICE DETERMINATION : Take the value of the slot and multiply it by the same slot TODO improve this*/
	unsigned int slots[3],sum;
	bool dw = false;
	cout << "You are sitting in front of a slot machine that accepts a maximum of 500 dollars on one go.\n";
while (1){
	while (1){
		unsigned int temp;
		cout << "How much you like to bet: ";
		cin >> temp;
		if (cin.fail()){
			cin.clear();
			cin.ignore(99999,'\n');
			std::cerr << "Invalid bet.\n";
			continue;
		}
		if (temp == 0){
			cout << "You can't bet nothing, try again.\n";
			continue;
		}
		if (temp > all_cash){
			cout << "You are attempting to bet an amount you can't afford, try again.\n";
			continue;
		}
		if (temp > 500){
			cout << "You can't bet nothing, try again.\n";
			continue;
		}
		bet = temp;
		cout << "You have bet " << bet << '\n';
		break;
	}
	cout << "Press any key to pull the lever.";
  getchar();

	for (int i=0;i<3;i++){
		slots[i] = rng(1,7,bet%51*2491+3);
	}

	 cout << "\n______\n" << slots[0] << "|" << slots[1] << "|" << slots[2] << "|\n______\n";


	 //TODO compare the states TODO fix this shit function


   cout << "The current state of the slot machine\n______\n" << slots[0] << "|" << slots[1] << "|" << slots[2] << "|\n______\n";
	 char yn = 'n';
	 if (all_cash + sum >= 1){
	 cout << "Bet again? (y/n)";
	 yn = getchar();
	 if (yn == 'y'){
			continue;
	 } else if (yn == 'n'){
		return sum;
	 }
 } else {
	return sum;
 }
 //when user wants out or when he is done return
}
	std::cerr << "An error occurred.\n";
	return 0;
	//execution should not get to this point
}

int dealer(const long long int all_cash){
	long long int bet;
	while (1){
		unsigned int temp;
		cout << "How much you like to bet: ";
		cin >> temp;
		if (cin.fail()){
			cin.clear();
			cin.ignore(99999,'\n');
			std::cerr << "Invalid bet.\n";
			continue;
		}
		if (temp == 0){
			cout << "You can't bet nothing, try again.\n";
			continue;
		}
		if (temp > all_cash){
			cout << "You are attempting to bet an amount you can't afford, try again.\n";
			continue;
		}
		bet = temp;
		cout << "You have bet " << bet << '\n';
		break;
	}

	int cards[52],deck_it = 4;
  vector<int> dealer_cards,player_cards;
	int cursor = 0;
	for (int i=1;i < 14;i++){
		for (int j=0;j < 4;j++){
				if (i == 11 || i == 12 || i == 13){
					cards[cursor] = 10;
 		      cursor++;
					continue;
				}
		     cards[cursor] = i;
		     cursor++;
	    }
	}
	for (int i = 0;i<52;i++){
		cout << cards[i] << ", ";
	}

	cursor = 0;
	cout <<"The deck is prepared, shuffling the cards...\n";
	for (int i = 0;i < 104;i++){
		int a,b,tmp;
		a = rng(0,52,time(0)*i+1);
		usleep(5);
		b = rng(0,52,897);
		if (a == b){
			 i--;
			 continue;
		}
        tmp = cards[a];
        cards[a] = cards[b];
        cards[b] = tmp;
  }

	cout << "Dealer stops shuffling and starts dealing cards.\n";
	player_cards.push_back(cards[0]);
  dealer_cards.push_back(cards[1]);
	player_cards.push_back(cards[2]);
  dealer_cards.push_back(cards[3]);

  while (true){
		int i = 0;
		if(sum(player_cards) == 21){
			cout << "You are lucky you have a blackjack!\n";
			return bet;
		} else if (sum(dealer_cards) == 21){
			cout << "Bad luck dealer has a blackjack!\n";
			return -bet;
		}
    cout << "You have "<< player_cards.size() << " cards : ";
          for (i=0;i<player_cards.size() - 1;i++){
              cout << getVal(player_cards[i]) << ", ";
          }

					cout << getVal(player_cards[i]) << "\nThe dealer has " << dealer_cards.size() << " cards, first one being " << getVal(dealer_cards[0]) << "\n";
					cout << "You can 1 Stand, 2 Hit, 3 Double Down\n: ";

					while (1){
						i = 0;
						cin >> i;
						if (!cin.fail()){
							break;
						}
						cin.clear();
						cin.ignore(99999,'\n');
					}
					switch (i) {
						case 1:
						while (1){
						dealer_cards.push_back(cards[deck_it]);
						++deck_it;
						if (sum(dealer_cards) > 18){
							break;
						}
					  }
						dsplyVal;
						if (sum(dealer_cards) > sum(player_cards) && sum(dealer_cards) <= 21){
							std::cout << "Dealer wins.\n";
							return -bet;
						} else {
							std::cout << "Players wins.\n";
							return +bet;
						}
						break;
						case 2:
						player_cards.push_back(cards[deck_it]);
						++deck_it;
						if (sum(player_cards) > sum(dealer_cards) && sum(player_cards) <= 21){
							dsplyVal;
							cout << "Player wins.\n";
							return +bet;
						} else if (sum(player_cards) > 21){
							dsplyVal;
							cout << "Player is bust, dealer wins.\n";
						}
						continue;
						break;
						case 3:
						if (all_cash >= bet*2){
							bet *= 2;
						}
						player_cards.push_back(cards[deck_it]);
						++deck_it;
						std::cout << "You have doubled down on your previous bet.\n";
						if (sum(dealer_cards) > sum(player_cards) && sum(dealer_cards) <= 21){
							dsplyVal;
							std::cout << "Player wins.\n";
							return +bet;
						}
						break;
						default:
						cout << "Invalid option.\n";
						continue;
						break;
					}
  }
	std::cerr << "An error occurred.\n";
	return 0;
 	//program should not get to this point
}
