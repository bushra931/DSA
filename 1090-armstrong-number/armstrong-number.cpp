class Solution {
public:
    bool isArmstrong(int n) {
        int num=n;
        int originalNum = n;
    int sum = 0;
    int numDigits = 0;

    // Step 1: Count the number of digits in n
    int temp = n;
    while (temp > 0) {
        numDigits++;
        temp /= 10;
    }

    // Step 2: Compute the sum of each digit raised to numDigits
    temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        sum += std::pow(digit, numDigits);  // Raise to power and sum
        temp /= 10;
    }

    return sum == originalNum;  // Return true if Armstrong condition is met
}

    
};