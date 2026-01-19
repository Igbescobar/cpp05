#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : name("Default"), hasBeenSigned(false), signGrade(150), execGrade(150) {}

AForm::AForm(const std::string name, unsigned int signGrade,
             unsigned int execGrade)
    : name(name), signGrade(signGrade), execGrade(execGrade) {
  if (signGrade < 1 || execGrade < 1)
    throw GradeTooLowException();
  if (signGrade > 150 || execGrade > 150)
    throw GradeTooHighException();
}

AForm::AForm(const AForm &source)
    : name(source.name), hasBeenSigned(source.hasBeenSigned),
      signGrade(source.signGrade), execGrade(source.execGrade) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &source) {
  if (this != &source)
    this->hasBeenSigned = source.hasBeenSigned;
  return *this;
}

const std::string AForm::getName() const { return this->name; }

unsigned int AForm::getSignGrade() const { return this->signGrade; }

unsigned int AForm::getExecGrade() const { return this->execGrade; }

bool AForm::getHasBeenSigned() const { return this->hasBeenSigned; }

void AForm::beSigned(const Bureaucrat &obj) {
  if (this->hasBeenSigned)
    return;
  else if (obj.getGrade() < this->signGrade) {
    this->hasBeenSigned = true;
    std::cout << obj.getName() << " has signed " << this->name << " form"
              << std::endl;
  }
}
