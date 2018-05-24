#pragma once

#include <cstdint>

/* Implement a generic mathematical Vector.
 * todo: * add template parameters
 *       * implement the required operators
 *       * test all functions
 *       * keep it const correct
 */

namespace Math {

    // The vector should have both a generic numeric type(T) and a number of dimensions(N).
    // The data can be stored in an array of type T and size N.
    template<typename T, std::size_t N>
    class Vector {

      public:
        Vector() = default;
        // Todo: Implement an operator[] overload for reading!
        const T& operator[](std::size_t i) const {
            return this->data[i];
        }

        // Todo: Implement an operator[] overload for read/write access!
        T& operator[](std::size_t i) {
            return this->data[i];
        }
        // Todo: Implement a unary operator- overload that negates all components
        Vector operator-() const {
            Vector _vector = Vector();
            for(std::size_t i = 0; i < N; i++)
                _vector[i] = (this->data[i])*-1;
            return _vector;
        }
        // Todo: Implement an operator+ overload that takes a vector of same type and size.
        Vector operator+(const Vector& vector) const {
            Vector _vector = Vector();
            for(std::size_t i = 0; i < N; i++)
                _vector[i] = this->data[i] + vector[i];
            return _vector;
        }
        // Todo: Implement an operator- overload that takes a vector of same type and size.
        Vector operator-(const Vector& vector) const {
          Vector _vector = Vector();
          for(std::size_t i = 0; i < N; i++)
              _vector[i] = this->data[i] - vector[i];
          return _vector;
        }

        ~Vector() = default;
      private:
        T data[N];
    };

    // Todo: Implement an operator* overload that takes a vector from the left and a scalar from the right side.
    // Returns a vector.
    template <typename T, std::size_t N>
    Vector<T, N> operator*(const Vector<T, N> vector, T a) {
        Vector<T,N> _vector = Vector<T, N>();
        for(std::size_t i = 0; i < N; i++)
            _vector[i] = vector[i] * a;
        return _vector;
    }

    // Todo: Implement a operator* overload that takes a vector from the right and a scalar from the left side.
    // Returns a vector.
    template <typename T, std::size_t N>
    Vector<T, N> operator*(T a, const Vector<T, N> vector) {
        return vector * a;
    }
}
