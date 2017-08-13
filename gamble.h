#include <ctime>
#include <iostream>
#include <vector>

int rng(int min,int max,int opt_seed = 0){
	if (opt_seed != 0){
		srand(time(0) * opt_seed);
	} else {
	srand(time(0));
	}
	int ret = rand() % max + min;
	if ((ret <= max)&&(ret >= min)){
		return ret;
	}
	return rng(min,max,opt_seed);
}

inline int sum(std::vector<int> in_vec){
	int sum,acec;
	for (int i = 0;i<in_vec.size();i++){
		if (in_vec[i] == 0){
			acec++;
		} else {
		sum += in_vec[i];
	  }
	}
	if (acec > 0){
		if (acec*10 + sum < 21){ //this is currently a cheap hack :|
				return acec*10 + sum;
		} else if (acec*1 + sum < 21){
			  return acec*1 + sum;
		} else {
		return sum;
	  }
	}
}

std::string getVal(int card){
	switch (card){
		case 1:
				return "Ace";
				break;
		case 2:
				return "2";
				break;
		case 3:
				return "3";
				break;
		case 4:
				return "4";
				break;
		case 5:
				return "5";
				break;
		case 6:
				return "6";
				break;
		case 7:
				return "7";
				break;
		case 8:
				return "8";
				break;
		case 9:
				return "9";
			  break;
		case 10:
				return "Jack";
				break;
		case 11:
				return "Queen";
				break;
		case 12:
				return "King";
		    break;
    default:
    std::cerr << "Card type value can't be determinated exiting.\n";
		exit(1);
    break;
	}
}

void showRules(){
	std::cout << "\n\
    The goal of blackjack is to beat the dealer's hand without going over 21.\n\
    Face cards are worth 10. Aces are worth 1 or 11, whichever makes a better hand.\n\
    Each player starts with two cards, one of the dealer's cards is hidden until the end.\n\
    To 'Hit' is to ask for another card. To 'Stand' is to hold your total and end your turn.\n\
    If you go over 21 you bust, and the dealer wins regardless of the dealer's hand.\n\
    If you are dealt 21 from the start (Ace & 10), you got a blackjack.\n\
    Dealer will hit until his/her cards total 17 or higher.\n\
    Doubling is like a hit, only the bet is doubled and you only get one more card.\n\
    You can double on a hand resulting from a split, tripling or quadrupling you bet.\n\n";
}
