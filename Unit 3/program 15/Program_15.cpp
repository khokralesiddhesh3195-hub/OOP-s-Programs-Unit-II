#include <iostream>  // Includes the input/output library.
#include <string>    // Includes string support.

class Payment {  // Defines the abstract Payment class.
public:
    virtual void pay(double amount) const = 0;
    // Declares pay() as a pure virtual function.

    virtual ~Payment() = default;
    // Defines a virtual destructor.
};

class CardPayment : public Payment {
    // Defines card payment as a derived class.

public:
    void pay(double amount) const override {
        // Implements the pay() function.

        std::cout << "Paid Rs. " << amount << " using card\n";
        // Displays the card payment information.
    }
};

class UpiPayment : public Payment {
    // Defines UPI payment as a derived class.

public:
    void pay(double amount) const override {
        // Implements the pay() function.

        std::cout << "Paid Rs. " << amount << " using UPI\n";
        // Displays the UPI payment information.
    }
};

class NetBankingPayment : public Payment {
    // Defines net banking as a derived class.

public:
    void pay(double amount) const override {
        // Implements the pay() function.

        std::cout << "Paid Rs. " << amount
                  << " using net banking\n";
        // Displays the net banking payment information.
    }
};

void processPayment(const Payment& payment, double amount) {
    // Accepts any Payment-derived object by reference.

    payment.pay(amount);
    // Calls the appropriate pay() function at run time.
}

int main() {
    // Program execution begins here.

    CardPayment card;
    // Creates a card payment object.

    UpiPayment upi;
    // Creates a UPI payment object.

    NetBankingPayment netBanking;
    // Creates a net banking payment object.

    processPayment(card, 1250.0);
    // Processes a card payment.

    processPayment(upi, 750.0);
    // Processes a UPI payment.

    processPayment(netBanking, 500.0);
    // Processes a net banking payment.

    return 0;
    // Indicates successful execution.
}

🎯 Expected Output

Paid Rs. 1250 using card
Paid Rs. 750 using UPI
Paid Rs. 500 using net banking
