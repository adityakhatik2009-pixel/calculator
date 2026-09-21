#include <iostream>
#include <memory>
#include <stdexcept>

// Abstract Base Class (Abstraction & Polymorphism)
class Operation {
public:
    virtual double calculate(double a, double b) const = 0;
    virtual ~Operation() = default;
};

// Derived Class: Addition
class Addition : public Operation {
public:
    double calculate(double a, double b) const override {
        return a + b;
    }
};

// Derived Class: Subtraction
class Subtraction : public Operation {
public:
    double calculate(double a, double b) const override {
        return a - b;
    }
};

// Derived Class: Multiplication
class Multiplication : public Operation {
public:
    double calculate(double a, double b) const override {
        return a * b;
    }
};

// Derived Class: Division
class Division : public Operation {
public:
    double calculate(double a, double b) const override {
        if (b == 0) {
            throw std::runtime_error("Error: Division by zero is undefined.");
        }
        return a / b;
    }
};

// Calculator Controller Class (Encapsulation)
class Calculator {
public:
    double executeOperation(const Operation& op, double a, double b) const {
        return op.calculate(a, b);
    }
};

int main() {
    Calculator calc;
    double num1, num2;
    int choice;

    std::cout << "=================================\n";
    std::cout << "      C++ OOP CALCULATOR         \n";
    std::cout << "=================================\n";
    std::cout << "1. Addition (+)\n";
    std::cout << "2. Subtraction (-)\n";
    std::cout << "3. Multiplication (*)\n";
    std::cout << "4. Division (/)\n";
    std::cout << "Enter operation (1-4): ";
    std::cin >> choice;

    if (choice < 1 || choice > 4) {
        std::cout << "Invalid choice!\n";
        return 1;
    }

    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    std::unique_ptr<Operation> op;

    switch (choice) {
        case 1: op = std::make_unique<Addition>(); break;
        case 2: op = std::make_unique<Subtraction>(); break;
        case 3: op = std::make_unique<Multiplication>(); break;
        case 4: op = std::make_unique<Division>(); break;
    }

    try {
        double result = calc.executeOperation(*op, num1, num2);
        std::cout << "\nResult: " << result << "\n";
    } catch (const std::exception& e) {
        std::cout << "\n" << e.what() << "\n";
    }

    return 0;
}