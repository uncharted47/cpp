#include "ShrubberyCreationForm.hpp"
#include <sstream>
ShrubberyCreationForm::ShrubberyCreationForm(void) {
	_target = "Unknown";
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target,145,137),_target(target) {
}



ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
{
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm const	&ShrubberyCreationForm::operator = (ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
		_target = rhs._target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw AForm::FormNotSigned();
	else if (getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::ofstream myFile((_target + "_shrubbery").c_str());
std::stringstream Tree;

myFile <<"               _{\\ _{\\{\\/}/}/}__ "<< std::endl
<<"              {/{/\\}{/{/\\}(\\}{/\\} _ "<< std::endl
<<"             {/{/\\}{/{/\\}(_)\\}{/{/\\}  _"<< std::endl
<<"          {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}"<< std::endl
<<"         {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}"<< std::endl
<<"        _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}"<< std::endl
<<"       {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}"<< std::endl
<<"       _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}"<< std::endl
<<"      {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}"<< std::endl
<<"       {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}"<< std::endl
<<"        {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)"<< std::endl
<<"       {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}"<< std::endl
<<"        {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}"<< std::endl
<<"          {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}"<< std::endl
<<"           (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)"<< std::endl
<<"             {/{/{\\{\\/}{/{\\{\\{\\(_)/}"<< std::endl
<<"              {/{\\{\\{\\/}/}{\\{\\}/}"<< std::endl
<<"               {){/ {\\/}{\\/} \\}\\}"<< std::endl
<<"               (_)  \\.-'.-/"<< std::endl
<<"           __...--- |'-.-'| --...__"<< std::endl
<<"    _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__"<< std::endl
<<"  -\"    ' .  . '    |.'-._| '  . .  '"<< std::endl
<<"  .  '-  '    .--'  | '-.'|    .  '  . '"<< std::endl
<<"           ' ..     |'-_.-|"<< std::endl
<<"   .  '  .       _.-|-._ -|-._  .  '  ."<< std::endl
<<"               .'   |'- .-|   '."<< std::endl
<<"   ..-'   ' .  '.   `-._.-�   .'  '  - ."<< std::endl
<<"    .-' '        '-._______.-'     '  ."<< std::endl
<<"         .      ~,"<< std::endl<< std::endl
<<"     .       .   |\\   .    ' '-."<< std::endl
<<"     ___________/  \\____________"<< std::endl
<<"    /  Why is it, when you want \\"<< std::endl
<<"   |  something, it is so damn   |"<< std::endl
<<"   |    much work to get it?     |"<< std::endl
<<"    \\___________________________/ "<< std::endl;
   myFile.close();
}
