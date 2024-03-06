#include "headers/Stack.hpp"
#include <cmath>
#include <iostream>
#include <string>

// bool verificarAbiertos(char caracter) {
//   return caracter == '{' || caracter == '[' || caracter == '(';
// }

// bool verificarCerrados(char caracter) {
//   return caracter == '}' || caracter == ']' || caracter == ')';
// }

// char regresarCierre(char abierto) {
//   if (abierto == '(')
//     return ')';
//   if (abierto == '[')
//     return ']';
//   return '}';
// }
// int main() {
//   Stack<char> simbolos;

//   std::string cadena;

//   bool cierre = true;
//   getline(std::cin, cadena);

//   for (int i = 0; i < cadena.size(); ++i) {
//     char caracter = cadena[i];
//     if (verificarAbiertos(caracter))
//       simbolos.push(caracter);
//     else if (verificarCerrados(caracter) && !simbolos.isEmpty()) {
//       if (regresarCierre(simbolos.getTop()) == caracter)
//         simbolos.pop();
//       else {
//         cierre = false;
//         break;
//       }
//     }
//   }
//   if (!cierre)
//     std::cout << "No tiene cierre" << std::endl;
//   else if (!simbolos.isEmpty())
//     std::cout << "Faltan llaves" << std::endl;
//   else
//     std::cout << "Expresion valida" << std::endl;

//   return 0;
// }

bool verificarOp(char c) {
    return c == '+' || c == '-' || c == '/' || c == '*' || c == '^';
}

bool verificarNum(char c) {
    return c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9';
}

double realizarOperacion(double n1, double n2, char op) {
    double res = 0;
    switch (op) {
    case '+':
        res = n1 + n2;
        break;
    case '-':
        res = n1 - n2;
        break;
    case '/':
        res = n1 / n2;
        break;
    case '*':
        res = n1 * n2;
        break;
    case '^':
        res = std::pow(n1, n2);
        break;
  }
  return res;
}
int main() {

    try {
        Stack<char> simbolos;
        Stack<double> numeros;

        std::string cadena;

        bool cierre = true;
        std::string str = "";
        getline(std::cin, cadena);

        for (char c : cadena) {
            if (!verificarOp(c)) {
                if (c != ' ') {
                    str += c;
                    continue;
                }
                numeros.push(std::stod(str));
                str = "";
                continue;
            }
            numeros.push(std::stod(str));
            str = "";

            double n1 = numeros.getTop();
            numeros.pop();

            double res = realizarOperacion(numeros.getTop(), n1, c);

            numeros.pop();
            numeros.push(res);
            std::cout << res << std::endl;
        }
    } catch (const char *&msg) {
        std::cout << msg << std::endl;
    }
    return 0;
}
