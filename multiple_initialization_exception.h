
#include <exception>
#include <string>
using namespace std;

class MultipleInitializationException : public exception {
public:
    MultipleInitializationException(string variable) : m_variable(variable) {
    }

    const char* what() const throw() {
        string error_message = "Error: Multiple initialization of variable " + m_variable;
        return error_message.c_str();
    }
private:
    string m_variable;
};

