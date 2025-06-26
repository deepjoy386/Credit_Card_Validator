#include <iostream>
#include <string>

int main() {
    long long creditNumber;
    std::cout << "Enter Credit Card Number: ";
    std::cin >> creditNumber;

    // Validate credit card using Luhn algorithm
    long long processedCreditCard = creditNumber;
    int sumDigits = 0;
    int digitCount = 0;
    long long divisor = 10;

    // Calculate sum of digits based on Luhn algorithm
    while (processedCreditCard > 0) {
        int lastDigit = processedCreditCard % 10;
        sumDigits += lastDigit;
        processedCreditCard = processedCreditCard / 100;
    }

    processedCreditCard = creditNumber / 10;
    while (processedCreditCard > 0) {
        int secondLastDigit = processedCreditCard % 10;
        int doubledDigit = secondLastDigit * 2;
        sumDigits += (doubledDigit % 10) + (doubledDigit / 10);
        processedCreditCard = processedCreditCard / 100;
    }

    // Count the number of digits in the credit card number
    processedCreditCard = creditNumber;
    while (processedCreditCard != 0) {
        processedCreditCard = processedCreditCard / 10;
        digitCount++;
    }

    // Determine the type of card based on first digits and length
    processedCreditCard = creditNumber;
    int firstDigit = processedCreditCard / divisor;
    int firstTwoDigits = creditNumber / (divisor / 10);

    std::string cardType;

    if (sumDigits % 10 == 0) {
        if (firstDigit == 4 && (digitCount == 13 || digitCount == 16)) {
            cardType = "VISA";
        } else if ((firstTwoDigits == 34 || firstTwoDigits == 37) && digitCount == 15) {
            cardType = "AMERICAN EXPRESS";
        } else if (50 < firstTwoDigits && firstTwoDigits < 56 && digitCount == 16) {
            cardType = "MASTERCARD";
        } else {
            cardType = "OTHER CARD TYPE";
        }
        std::cout << "VALID" << std::endl;
        std::cout << "CARD TYPE: " << cardType << std::endl;
    } else {
        cardType = "INVALID";
        std::cout << cardType << std::endl;
    }

    return 0;
}
