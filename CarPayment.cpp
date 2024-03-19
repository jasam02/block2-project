#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

int main()
{
    double carPrice, salesTax, registrationFees, loanAmount;
    double interestRate = 0.07 / 12;
    std::string state;
    int months;

    //get car price
    std::cout << "How much does your car cost?\n";
    std::cin >> carPrice;

    std::cout << "-------------------------------\n";

    //get payment time
    std::cout << "How many months would you want\nto pay it off in?\n";
    std::cin >> months;

    std::cout << "-------------------------------\n";

    //get sales tax and registration fees
    std::cout << "What state do you live in?\n";
    std::cin >> state;
    
    std::cout << "-------------------------------\n";

    //make sure state is in upper case letters
    std::transform(state.begin(), state.end(), state.begin(), [](unsigned char c) -> unsigned char {return std::toupper(c);});
    
    //set tax and registration fees for state
    if(state == "UT")
    {
        salesTax = 0.065;
        registrationFees = 300;
    }
    else if (state == "CA")
    {
        salesTax = 0.0725;
        registrationFees = carPrice * 0.065;
    }
    else if (state == "TX")
    {
        salesTax = 0.0625;
        registrationFees = 57;
    }
    //use a default for other states
    else
    {
        salesTax = 0.07;
        registrationFees = 500;
    }

    loanAmount = (carPrice * (salesTax + 1) + registrationFees);
    double monthlyPayment =  loanAmount * (interestRate * pow(1 + interestRate, months)) / (pow(interestRate + 1, months) - 1);
    double interestPaid = loanAmount - carPrice;

    std::cout << "Your total loan cost is: " << std::fixed << std::setprecision(2) << loanAmount << "\n";

    std::cout << "Your monthly payment will be: " << monthlyPayment << "\n";
    
    std::cout << "The total amount of interest you will pay is: " << interestPaid << std::endl;
}
