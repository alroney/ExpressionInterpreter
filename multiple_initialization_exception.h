

#include <string>
using namespace std;

class MultipleInitializationException : public exception {
public:
    MultipleInitializationException(string variable) : m_variable(variable) {
    }

    const string mie() const{
        string error_message = "Error: Multiple initialization of variable " + m_variable;
        return error_message;
    }
private:
    string m_variable;
};

