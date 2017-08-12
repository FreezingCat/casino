#include <iostream>
#include <unistd.h>
#include "gamble.hpp"

bool is_bankrupt(long long int cash){
	if (cash <= 0){
	std::cout << "Looks like you are out of cash, well it is time for a goodbye!\n";
	return true;
  }
	return false;
}

//*cash = accessing the variable
bool menu(long long int * cash){
	std::cout << "You have " << *cash << " dollars on you.\n1 : Blackjack, 2 : Slots, 3 : Reserved, 4 : Reserved\n5 : Show rules, 6 : Leave the casino\n:";
  unsigned char choice;
	std::cin >> choice;


	if (choice == '1'){
	  *cash += dealer(*cash);
	} else if (choice == '2'){
		*cash += slots(*cash);
	} else if (choice == '3') {

	} else if (choice == '4'){

	} else if (choice == '5'){
		showRules();
	} else if (choice == '6'){
		std::cout << "You have decided to leave the casino.\n";
		return false;
	} else {
		std::cerr << "\nSomething went wrong exiting.\n";
		return false;
	}


  if (is_bankrupt(*cash)){
		return false;
	}
	return true;
}

int main() {
	long long int cash = 1000,*cashptr = &cash;
	while (1){
		if(menu(cashptr)){
			continue;
		} else {
			break;
		}
	}
  return 0;
}
