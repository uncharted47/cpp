#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void)
{
    try {
        // Create bureaucrats with different grades
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);
        Bureaucrat assistant("Assistant", 45);

        std::cout << "\n=== Testing Bureaucrats ===\n";
        std::cout << boss << std::endl;
        std::cout << intern << std::endl;
        std::cout << assistant << std::endl;

        // Create forms
        ShrubberyCreationForm shrub("Garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Criminal");

        std::cout << "\n=== Testing Forms ===\n";
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        // Test signing forms
        std::cout << "\n=== Testing Form Signing ===\n";
        boss.signForm(shrub);
        boss.signForm(robot);
        boss.signForm(pardon);

        // Test executing forms
        std::cout << "\n=== Testing Form Execution ===\n";
        boss.executeForm(shrub);
        boss.executeForm(robot);
        boss.executeForm(pardon);

        // Test with intern (should fail)
        std::cout << "\n=== Testing with Low-level Bureaucrat ===\n";
        ShrubberyCreationForm shrub2("Park");
        intern.signForm(shrub2);
        intern.executeForm(shrub2);

        // Test with assistant (mixed results)
        std::cout << "\n=== Testing with Mid-level Bureaucrat ===\n";
        ShrubberyCreationForm shrub3("Plaza");
        RobotomyRequestForm robot2("R2D2");
        PresidentialPardonForm pardon2("Thief");

        assistant.signForm(shrub3);    // Should succeed
        assistant.signForm(robot2);    // Should succeed
        assistant.signForm(pardon2);   // Should fail

        assistant.executeForm(shrub3); // Should succeed if signed
        assistant.executeForm(robot2); // Should succeed if signed
        assistant.executeForm(pardon2); // Should fail

        // Test executing unsigned form
        std::cout << "\n=== Testing Unsigned Form Execution ===\n";
        ShrubberyCreationForm unsignedShrub("Unsigned");
        boss.executeForm(unsignedShrub);

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}