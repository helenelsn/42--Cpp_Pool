#include "../includes/Bureaucrat.hpp"

int main (void)
{
    try {
        Form rsa("Le RSA", 0, 30);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form ret("La retraite a 30 ans", 5, 180);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl; 
    }
    std::cout << std::endl;


    Form fff("Aller planter des courgettes", 80, 40);
    Form joel("Cramer des mcdos", 100, 20);
    Bureaucrat bobob("Le bobob", 140);
    Bureaucrat hippie("Hipipou", 10);
    
    // grade too low to sign
    try {
        fff.beSigned(bobob);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        fff.beSigned(hippie);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        bobob.signForm(joel);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        hippie.signForm(joel);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << fff << std::endl;
    std::cout << std::endl << joel << std::endl;

    return (0);
}