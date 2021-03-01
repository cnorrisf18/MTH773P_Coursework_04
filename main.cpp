//delta x = (b - a)/N where N is a user input
#include <iostream>
#include "EurCall.h"
#include "EurPut.h"

using namespace std;

void NegativeMessage(double& x, string x_name)
{
	cout << endl << x_name << " should not be negative, please enter a new value. ";
	cin >> x;
}

int main()
{
	//get initial inputs
	double time_to_expiry; double strike_price;
	cout << "Please enter expiry time (in years): ";
	cin >> time_to_expiry;
	cout << endl << "Please enter strike price: ";
	cin >> strike_price;
	//get function inputs
	double spot_price; double volatility; double interest_rate;
	cout << endl << "Please enter the price of the stock: ";
	cin >> spot_price;
	cout << endl << "Please enter volatility: ";
	cin >> volatility;
	cout << endl << "Please enter the continuously-compounded interest rate (as a decimal): ";
	cin >> interest_rate;
	//check inputs
	bool done = false;
	while (not done)
	{
		if (time_to_expiry <= 0)
		{
			NegativeMessage(time_to_expiry, "Time to expiry");
		}
		else if (strike_price < 0)
		{
			NegativeMessage(strike_price, "Strike price");
		}
		else if (spot_price < 0)
		{
			NegativeMessage(spot_price, "Stock price");
		}
		else if (volatility < 0)
		{
			NegativeMessage(volatility, "Volatility");
		}
		else if (interest_rate < 0)
		{
			NegativeMessage(interest_rate, "Interest rate");
		}
		else if (interest_rate > 1)
		{
			string Confirmation;
			cout << endl << "The entered interest rate is higher than 1 (100%), are you sure this is correct? type YES or NO ";
			cin >> Confirmation;
			if (Confirmation == "NO")
			{
				cout << endl << "Please enter a new value for the interest rate. ";
				cin >> interest_rate;
			}
			else if (Confirmation == "YES")
			{
				done = true;
			}
		}
		else
		{
			done = true;
		}
	}
	//check what kind of option should be priced
	string option_type;
	cout << endl << "What kind of option would you like priced? Type CALL or PUT: ";
	cin >> option_type;
	//price the option
	//create possible option values
	EurCall* CallOption = new EurCall(time_to_expiry, strike_price, "CALL");
	EurPut* PutOption = new EurPut(time_to_expiry, strike_price, "PUT");
	EurOption* OptionPointer = nullptr;
	bool done2 = false;
	while (not done2)
	{
		if (option_type == "CALL")
		{
			OptionPointer = CallOption;
			cout << "Calculating values for a call option." << endl;
			done2 = true;
		}
		else if (option_type == "PUT")
		{
			OptionPointer = PutOption;
			cout << "Calculating values for a put option." << endl;
			done2 = true;
		}
		else
		{
			cout << "Invalid input, please try again. Options are CALL or PUT: ";
			cin >> option_type;
		}
	}
	OptionPointer->PrintValues(spot_price, volatility, interest_rate);
	double integral_price = OptionPointer->PriceByIntegral(spot_price, volatility, interest_rate);
	cout << "Calculated Integral price is " << integral_price << endl;
}

