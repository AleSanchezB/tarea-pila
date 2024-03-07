#ifndef EXPRESION_HPP
#define EXPRESION_HPP
#include <string>
class Expression {

    friend std::istream & operator>>(std::istream &in, Expression &e);
    friend std::ostream & operator<<(std::ostream &out, const Expression &e);

    public:
    Expression(); //Constructor
    Expression(const std::string &expression);
    void CaptureExpression(const std::string &expression);
    bool isCorrect(const std::string &expression);
    std::string ConvertExpression(std::string expIn);
    double EvaluateExpression();
    void Print();
    bool IsValid();

    private:
    std::string infixExp; // Expresion Infija
    std::string postfixExp; // Expresion postfija
    bool isValidExp;


};




















#endif