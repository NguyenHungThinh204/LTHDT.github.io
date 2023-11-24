#include <iostream>

class Calculator {
private:
    int a;
    int b;

public:
    Calculator() {
        a = 0;
        b = 0;
    }

    void inputNumbers() {
        std::cin >> a >> b;
    }

    int calculateSum() {
        return a + b;
    }

    void displayResult(int result) {
        std::cout << result << std::endl;
    }
};

int main() {
    Calculator calculator;
    calculator.inputNumbers();
    int result = calculator.calculateSum();
    calculator.displayResult(result);

    return 0;
}
