#include "../includes/Bureaucrat.hpp"

int main (void)
{
    try {
        Bureaucrat elvis("Elvis", 0);
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat elvis("Pretzel", 178);
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    // --------------------------------------

    std::cout << std::endl;
    Bureaucrat bob("Bob", 150);
    Bureaucrat alice("Alice", 1);
    
    std::cout << bob << alice << std::endl;
    try {
        bob.decrementGrade();
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    try {
        alice.incrementGrade();
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    bob.incrementGrade();
    alice.decrementGrade();
    std::cout << bob<< alice << std::endl;


    return (0);
}