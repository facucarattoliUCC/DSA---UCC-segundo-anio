#ifndef NODO_H
#define NODO_H

template <class T> class Nodo {
private:
  T m_dato;
  Nodo<T> *m_siguiente;

public:
  Nodo(T dato = 0, Nodo<T> *siguiente = nullptr)
      : m_dato{dato}, m_siguiente{siguiente} {}

  T getDato() { return m_dato; }

  void setDato(T d) { m_dato = d; }

  Nodo<T> *getSiguiente() { return m_siguiente; }

  void setSiguiente(Nodo<T> *siguiente) { m_siguiente = siguiente; }
};

#endif // NODO_H
