#include <iostream>
#include <string>

class Beverage {
protected:
    std::string name;

public:
    Beverage(const std::string& beverageName) : name(beverageName) {}

    virtual void prepare() const {
        std::cout << "Prepare the base for " << name << std::endl;
    }
};

class Tea : public Beverage {
public:
    Tea() : Beverage("Tea") {}

    void prepare() const override {
        Beverage::prepare();
        std::cout << "Boil water, steep tea leaves, and add optional ingredients like milk or sugar." << std::endl;
    }
};

class Coffee : public Beverage {
public:
    Coffee() : Beverage("Coffee") {}

    void prepare() const override {
        Beverage::prepare();
        std::cout << "Brew coffee grounds, add hot water, and customize with milk, sugar, or other additives." << std::endl;
    }
};

class Soda : public Beverage {
public:
    Soda() : Beverage("Soda") {}

    void prepare() const override {
        Beverage::prepare();
        std::cout << "Pour carbonated beverage into a glass and optionally add ice or flavoring syrups." << std::endl;
    }
};

int main() {
    int userChoice;
    std::cout << "Choose a beverage by entering the corresponding number:\n";
    std::cout << "1. Tea\n";
    std::cout << "2. Coffee\n";
    std::cout << "3. Soda\n";
    std::cout << "Enter your choice (1, 2, or 3): ";
    std::cin >> userChoice;

    Beverage* beverage;

    switch (userChoice) {
        case 1:
            beverage = new Tea();
            break;
        case 2:
            beverage = new Coffee();
            break;
        case 3:
            beverage = new Soda();
            break;
        default:
            std::cerr << "Invalid choice. Please enter 1, 2, or 3." << std::endl;
            return 1; // Exit with an error code
    }

    std::cout << "\nPreparing beverage " << userChoice << ":" << std::endl;
    std::cout << "---------------------" << std::endl;

    beverage->prepare();

    delete beverage; // Free allocated memory

 return 0;
}

