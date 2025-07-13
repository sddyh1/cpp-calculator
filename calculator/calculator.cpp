// В этом файле определения функций.
// За основу возьмите решение предыдущей задачи.
#include <iostream>
#include <string>
#include <cmath>

using Number = double;

bool ReadNumber(Number& result) {

    if (std::cin >> result) {
        return true;
    }

    return false;
}

bool RunCalculatorCycle() {
    Number current;
    if (!ReadNumber(current)) {

        std::cerr << "Error: Numeric operand expected\n";
        return false;

    }

    bool memory_initialized = false;
    Number memory = 0.0;
    std::string command;
    bool normal_quit = false;

    while (std::cin >> command) {
        if (command == "q") {
            normal_quit = true;
            break;

        }
        else if (command == "c") {
            current = 0.0;

        }
        else if (command == ":") {
            Number new_value;

            if (ReadNumber(new_value)) {
                current = new_value;
            }

            else {
                std::cerr << "Error: Numeric operand expected\n";
                return false;

            }
        }
        else if (command == "+" || command == "-" || command == "*" || command == "/" || command == "**") {

            Number operand;

            if (ReadNumber(operand)) {
                if (command == "+") {
                    current += operand;

                }
                else if (command == "-") {
                    current -= operand;
                }

                else if (command == "*") {
                    current *= operand;
                }

                else if (command == "/") {
                    current /= operand;
                }

                else if (command == "**") {
                    current = std::pow(current, operand);
                }

            }
            else {
                std::cerr << "Error: Numeric operand expected\n";
                return false;
            }
        }
        else if (command == "=") {
            std::cout << current << '\n';

        }
        else if (command == "s") {
            memory = current;
            memory_initialized = true;

        }
        else if (command == "l") {

            if (memory_initialized) {
                current = memory;
            }
            else {
                std::cerr << "Error: Memory is empty\n";
                return false;
            }
        }
        else {
            std::cerr << "Error: Unknown token " << command << '\n';
            return false;
        }
    }

    return normal_quit;
}