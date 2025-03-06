#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
    try {
        // Create bureaucrats and intern
        Bureaucrat boss("Boss", 1);
        Intern someRandomIntern;

        // Test intern making forms
        std::cout << "\n=== Testing Intern Form Creation ===\n";

        // Valid form creation
        AForm* rrf;
        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Criminal");
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        // Invalid form creation
        AForm* invalid = someRandomIntern.makeForm("invalid form", "Test");

        if (rrf && scf && ppf) {
            std::cout << "\n=== Testing Created Forms ===\n";
            std::cout << *rrf << std::endl;
            std::cout << *scf << std::endl;
            std::cout << *ppf << std::endl;

            // Test using created forms
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            boss.signForm(*scf);
            boss.executeForm(*scf);

            boss.signForm(*ppf);
            boss.executeForm(*ppf);

            // Clean up
            delete rrf;
            delete scf;
            delete invalid;
            delete ppf;
        }

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}