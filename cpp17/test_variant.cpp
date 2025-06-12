#include <iostream>
#include <variant>

int main() {
    // Define a variant type that can hold either an int or a double
    std::variant<int, double> myVariant;

    // Assign an int value to the variant
    myVariant = 42;

    // Check which type is currently held by the variant
    if (std::holds_alternative<int>(myVariant)) {
        std::cout << "The variant holds an int: " << std::get<double>(myVariant) << std::endl;
    } else {
        std::cout << "The variant does not hold an int." << std::endl;
    }

    // Assign a double value to the variant
    myVariant = 3.14;

    // Check again which type is currently held by the variant
    if (std::holds_alternative<double>(myVariant)) {
        std::cout << "The variant holds a double: " << std::get<double>(myVariant) << std::endl;
    } else {
        std::cout << "The variant does not hold a double." << std::endl;
    }

    return 0;
}