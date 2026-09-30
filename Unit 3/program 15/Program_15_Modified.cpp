#include <iostream>   // Provides input/output functionality.
#include <string>     // Provides string-related functionality.

using namespace std;  // Allows direct use of cout and other standard features.

// Abstract base class representing a general payment method.
class Payment {
public:

    // Pure virtual function for processing a payment.
    // MODIFICATION: Kept as pure virtual to support runtime polymorphism.
    virtual void pay(double amount) const = 0;

    // Virtual destructor ensures proper cleanup of derived objects.
    virtual ~Payment() = default;
};


// Derived class for card payments.
class CardPayment : public Payment {
public:

    // Overrides the pay() function for card payment.
    void pay(double amount) const override {
        cout << "Paid Rs. " << amount << " using card\n";
    }
};


// Derived class for UPI payments.
class UpiPayment : public Payment {
public:

    // Overrides the pay() function for UPI payment.
    void pay(double amount) const override {
        cout << "Paid Rs. " << amount << " using UPI\n";
    }
};


// Derived class for net banking payments.
class NetBankingPayment : public Payment {
public:

    // Overrides the pay() function for net banking payment.
    void pay(double amount) const override {
        cout << "Paid Rs. " << amount << " using net banking\n";
    }
};


// ==========================================================
// MODIFICATION ADDED: New WalletPayment class.
// ==========================================================

// New derived class representing wallet-based payments.
class WalletPayment : public Payment {
public:

    // MODIFICATION: Overrides pay() to process wallet payment.
    void pay(double amount) const override {
        cout << "Paid Rs. " << amount << " using wallet\n";
    }
};


// Function to process any type of payment.
// It accepts a base-class reference, enabling runtime polymorphism.
void processPayment(const Payment& payment, double amount) {

    // Calls the appropriate derived-class pay() function at runtime.
    payment.pay(amount);
}


int main() {

    // Creates an object for card payment.
    CardPayment card;

    // Creates an object for UPI payment.
    UpiPayment upi;

    // Creates an object for net banking payment.
    NetBankingPayment netBanking;

    // ======================================================
    // MODIFICATION ADDED: Creates WalletPayment object.
    // ======================================================
    WalletPayment wallet;

    // Processes card payment.
    processPayment(card, 1250.0);

    // Processes UPI payment.
    processPayment(upi, 750.0);

    // Processes net banking payment.
    processPayment(netBanking, 500.0);

    // ======================================================
    // MODIFICATION ADDED: Processes wallet payment using
    // the same processPayment() function.
    // ======================================================
    processPayment(wallet, 900.0);

    // Indicates successful program termination.
    return 0;
}
