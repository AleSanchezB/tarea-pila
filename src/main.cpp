#include "headers/Stack.hpp"
#include <cmath>
#include <iostream>
#include <string>

bool verificarAbiertos(char caracter) {
  return caracter == '{' || caracter == '[' || caracter == '(';
}

bool verificarCerrados(char caracter) {
  return caracter == '}' || caracter == ']' || caracter == ')';
}

char regresarCierre(char abierto) {
  if (abierto == '(')
    return ')';
  if (abierto == '[')
    return ']';
  return '}';
}

char regresarAbierto(char abierto) {
    if (abierto == ')')
        return '(';
  if (abierto == ']')
      return '[';
  return '}';
}

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

void verificarJerarquia(Stack<char> &s, char c) {
    char top;
    if (s.isEmpty()) top = '\0';
    else top= s.getTop();

    if(verificarAbiertos(top)|| verificarAbiertos(c) || top == '\0') {
        s.push(c);
        return;
    }
    if (c == '^') {
        if (c == top) {
            s.push(c);
            return;
        } 
        s.pop();
        s.push(c);
        s.push(top);
    }
    else if (c == '*' || c == '/') {
        if (c == top || top == '^') {
            s.push(c);
            return;
        }
        s.pop();
        s.push(c);
        s.push(top);
    }
    else {
        if (c == top || top == '^' || top == '*' || top == '/') {
            s.push(c);
            return;
        }
        s.pop();
        s.push(c);
        s.push(top);
    }
}
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

void convertir() {
    try {
        char separador = ' ';
        Stack<char> simbolos;
        std::string op = "";
        std::string posfija ="";

        // std::string cadena = "{[(5+7)*6+4]/[(2-3)/4]}^2";
        //std::string cadena = "[(5+7)*6+4]";
        std::string cadena = "1*2+3";
        std::string str = "";
        std::string nums = "";
        
        for (int i = 0; i < cadena.size(); ++i) {

             if (cadena[i] == ' ' || (i == 0 || i == cadena.size() - 1) && (cadena[i] == '*' || cadena[i] == '/' || cadena[i] == '^') || (i == cadena.size() - 1 && (cadena[i] == '+' || cadena[i] == '-')) || cadena[0] == '.' || cadena[cadena.size() - 1] == '.' || cadena[0] == 'e' || cadena[cadena.size() - 1] == 'e' || cadena[0] == 'E' || cadena[cadena.size() - 1] == 'E')
                 throw "Expresion no valida";
            
            if (verificarAbiertos(cadena[i])) {
                simbolos.push(cadena[i]);
            } else if (verificarNum(cadena[i])) {
                str += cadena[i];
            } else if (verificarOp(cadena[i]) && cadena[i-1] != 'e' && cadena[i-1] != 'E') {
                nums += str + separador;
                str = "";
                verificarJerarquia(simbolos, cadena[i]);
                //std::cout << nums << std::endl;

            } else {
                if (cadena[i] == '.' || cadena[i] == 'e' || cadena[i] == 'E' || cadena[i] == '-' || cadena[i] == '+') {
                  if (cadena[i - 1] == '.' || cadena[i - 1] == 'e' ||
                      cadena[i - 1] == 'E')
                      throw "No valida";
                  str += cadena[i];
                } else if (verificarCerrados(cadena[i])) {
                    nums += str + separador;
                    // std::cout << nums  << std::endl;
                    simbolos.print();
                    while (!simbolos.isEmpty() && regresarAbierto(cadena[i]) != simbolos.getTop()) {
                        if (verificarOp(simbolos.getTop())) {
                            op += simbolos.getTop();
                        }
                        simbolos.pop();
                    }
                    posfija += nums + '\b' + op;
                    std::cout << posfija << std::endl;
                    op = "";
                    nums = "";
                    str = "";
                } else {
                    
                }
               
            }
        }
    } catch (const char *&msg) {
        std::cout << msg << std::endl;
    }
}
int main() {

    try {
        convertir();
        // char separador = ' ';
        // Stack<char> simbolos;
        // Stack<double> numeros;

        // std::string cadena;

        // bool cierre = true;
        // std::string str = "";
        // getline(std::cin, cadena);

        // for (char c : cadena) {
        //     if (!verificarOp(c)) {
        //         if (c != separador) {
        //             str += c;
        //             continue;
        //         }
        //         numeros.push(std::stod(str));
        //         str = "";
        //         continue;
        //     }
        //     if(str != "")
        //         numeros.push(std::stod(str));
        //     str = "";

        //     double n1 = numeros.getTop();
        //     numeros.pop();

        //     double res = realizarOperacion(numeros.getTop(), n1, c);

        //     numeros.pop();
        //     numeros.push(res);
        //     std::cout << res << std::endl;
        // }
    } catch (const char *&msg) {
        std::cout << msg << std::endl;
    }
    return 0;
}
