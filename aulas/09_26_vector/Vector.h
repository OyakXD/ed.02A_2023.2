/**
 * @file Vector.h
 * @author Atilio G. Luiz
 * @date 26-09-2023
 * Classe que implementa uma lista linear sequencial de inteiros
 */
#ifndef VECTOR_H
#define VECTOR_H
#include <stdexcept>
#include <iostream>

class Vector {
private:
    unsigned int m_size{};      // numero de elementos atual
    unsigned int m_capacity{};  // capacidade atual da lista
    int *m_vet{};               // ponteiro para array

public:
    // Construtor default: cria lista vazia
    Vector() = default;

    // Construtor que recebe a capacidade
    Vector(unsigned int cap) 
        : m_size{0}, m_capacity{cap}
    {
        m_vet = new int[m_capacity];
    }

    // Construtor de copia
    Vector(const Vector& v) {
        m_size = v.m_size;
        m_capacity = v.m_capacity;
        m_vet = new int[m_capacity];
        for(unsigned int i = 0; i < m_size; ++i) {
            m_vet[i] = v.m_vet[i];
        }
    }

    // Funcao que recebe um valor inteiro newCap 
    // que sera a nova capacidade.
    // Se m_capacity >= newCap, a funcao faz nada.
    // Caso contrario, a funcao aumenta a capacidade
    // do Vector para um valor maior ou igual a newCap
    void resize(unsigned int newCap) {
        if(m_capacity < newCap) {
            m_capacity = newCap;
            int *aux = new int[m_capacity];
            for(unsigned int i = 0; i < m_size; ++i) {
                aux[i] = m_vet[i];
            }
            delete[] m_vet;
            m_vet = aux;
        }
    }
    // Funcao que insere um elemento no final
    // da lista. Se a lista ficar cheia, ele
    // primeiro aumenta a capacidade da lista
    // e somente depois insere no final.
    void push_back(int val) {
        if(m_size == m_capacity) {  // aumenta de precisar
            resize(2 * (m_capacity + 1));
        }
        m_vet[m_size] = val; // insere
        m_size++;            // incrementa m_size
    }

    // Funcao que recebe um índice i e retorna
    // o elemento que esta no índice i.
    // Se o indice nao existir na lista, essa funcao
    // vai lancar uma excecao.
    int& at(unsigned int i) {
        if(i < m_size) {
            return m_vet[i];
        }
        else {
            throw std::out_of_range("erro no indice");
        }
    }
    // Versao const da funcao anterior
    const int& at(unsigned int i) const {
        if(i < m_size) {
            return m_vet[i];
        }
        else {
            throw std::out_of_range("erro no indice");
        }
    }

    // Destrutor: libera memoria alocada
    ~Vector() {
        delete[] m_vet;
        std::cout << "vector destruido\n";
    }

    // retorna o numero de elementos na lista
    unsigned int size() const {
        return m_size;
    }

    // sobrecarga do operador de indexacao
    // recebe um indice i e retorna o elemento no indice i
    // Se o indice não estiver dentro do intervalo, 
    // o comportamento dessa funcao é indeterminado.
    int& operator[](int i) {
        return m_vet[i];
    }
    // versao const da funcao anterior
    const int& operator[](int i) const {
        return m_vet[i];
    }
};

#endif // VECTOR_H