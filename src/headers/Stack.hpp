/**
 * \file STACK.hpp
 * \brief Implementaci&oacute;n de una Matriz algebraica
 * \author Jesus Ernesto Carrasco Teran
 * \author Braulio Alessandro S&aacute;nchez Berm&uacute;dez
 * \date 19/02/2024
 */

#ifndef PILA_HPP
#define PILA_HPP

/**
 * \class STACK
 * \brief Clase genérica de STACK que implementa operaciones b&aacute;sicas de pila.
 *
 * Esta clase template ofrece una implementaci&oacute;n de pila con operaciones para agregar,
 * eliminar elementos, y consultar el tope de la pila, entre otras.
 * 
 * \tparam T Tipo de elementos almacenados en la pila.
 */

template <typename T = int>

class Stack
{
    public:
        /**
         * \brief Constructor por defecto que inicializa una pila vac&iacute;a.
         */
        Stack();

        /**
         * \brief Constructor de copia.
         * \param p Otra pila de la cual se copiar&aacute;n los elementos.
         */
        Stack(const Stack &p);

        /**
         * \brief Sobrecarga del operador de asignaci&oacute;n.
         * \param p Otra pila de la cual se copiar&aacute;n los elementos.
         * \return Referencia a la pila actual.
         */
        Stack & operator=(const Stack &p);

        /**
         * \brief Destructor que libera la memoria de la pila.
         */
        ~Stack();

        /**
         * \brief Agrega un nuevo elemento al tope de la pila.
         * \param valor El valor a agregar.
         */
        void push(T v);

        /**
         * \brief Elimina el elemento del tope de la pila.
         */
        void pop();

        /**
         * \brief Obtiene el valor del tope de la pila sin eliminarlo.
         * \return El valor en el tope de la pila.
         */
        T getTop() const;

        /**
         * \brief Vac&iacute;a la pila eliminando todos sus elementos.
         */
        void clear();

        /**
         * \brief Obtiene el tamaño actual de la pila, es decir, el n&uacute;mero de elementos.
         * \return El n&uacute;mero de elementos en la pila.
         */
        int size() const;

        /**
         * \brief Verifica si la pila est&aacute; vac&iacute;a.
         * \return Verdadero si la pila est&aacute; vac&iacute;a, falso de lo contrario.
         */
        bool isEmpty() const;

        /**
         * \brief Imprime todos los elementos de la pila, utilizado para pruebas.
         */
        void print() const;

private:
    int _size;
    struct Element {
        Element(T v, Element *next_ = nullptr);
        T value;
        Element *next;
    } * top; // Equivalent to Element * top;
};

#include "../templates/Stack.tpp"

#endif // PILA_HPP
