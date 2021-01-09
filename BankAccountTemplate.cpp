#include<iostream>
#include <cmath>
using namespace std;

template <class A, class R>
class BankAccount {
	private:
		A checkingAmt, savingAmt;
		R checkingRate = 3.3, savingRate = 4.3, time = 30;
	public:
		BankAccount(A c, A s){
			checkingAmt = c;
			savingAmt = s;
		}
		R getInterestOnChecking() {
			return (checkingAmt*(1+(checkingRate/100)*time)-checkingAmt);
		}
		R getInterestOnSaving() {
			return (savingAmt*pow(1+(savingRate/100),time) - savingAmt);;
		}
};

template class BankAccount<double,double>;
template class BankAccount<int,double>;

int main () {
	BankAccount<double,double>* b = new BankAccount<double,double>(1000,2000);
	cout << "Interest on checking - " << b->getInterestOnChecking() << '\n';
	cout << "Interest on saving - " << b->getInterestOnSaving() << '\n';
	delete b;

	return 0;
}
