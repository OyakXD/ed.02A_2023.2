/************************************************************************
 * Arquivo de implementacao da classe ForwardList
 * Voce deve implementar as funcoes que faltam ao final deste arquivo
 ************************************************************************/
#include "ForwardList.h"

#include <iostream>

#include "Node.h"

// *********************************************************
// Implementacao das funcoes-membro da classe ForwardList
// *********************************************************

ForwardList::ForwardList() {
    m_head = new Node(0, nullptr);
    m_size = 0;
}

ForwardList::ForwardList(const ForwardList &lst) {
    m_head = new Node(0, nullptr);
    m_size = lst.m_size;
    Node *lstCurrent = lst.m_head->next;
    Node *thisLast = m_head;
    while (lstCurrent != nullptr) {
        thisLast->next = new Node(lstCurrent->data, nullptr);
        lstCurrent = lstCurrent->next;
        thisLast = thisLast->next;
    }
}

bool ForwardList::empty() const { return m_head->next == nullptr; }

int ForwardList::size() const { return m_size; }

void ForwardList::clear() {
    while (m_head->next != nullptr) {
        Node *aux = m_head->next;
        m_head->next = aux->next;
        delete aux;
    }
    m_size = 0;
}

ForwardList::~ForwardList() {
    clear();
    delete m_head;
}

void ForwardList::print() const {
    Node *temp = m_head->next;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << '\n';
}

void ForwardList::concat(ForwardList &lst) {
    Node *temp = m_head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = lst.m_head->next;
    m_size += lst.m_size;
    lst.m_head->next = nullptr;
    lst.m_size = 0;
}

void ForwardList::remove(const int &val) {
    if (m_size == 0) {
        return;
    }

    Node *aux = m_head;
    while (aux->next != nullptr) {
        if (aux->next->data == val) {
            Node *temp = aux->next;
            aux->next = temp->next;
            delete temp;
            m_size--;
        } else {
            aux = aux->next;
        }
    }
}

ForwardList *ForwardList::clone() {
    ForwardList *lst = new ForwardList();

    Node *temp = m_head->next;
    Node *aux = lst->m_head;

    while (temp != nullptr) {
        aux->next = new Node(temp->data, nullptr);
        temp = temp->next;
        aux = aux->next;
        lst->m_size++;
    }
    return lst;
}

void ForwardList::appendVector(const std::vector<int> &vec) {
    Node *aux = m_head;

    while (aux->next != nullptr) {
        aux = aux->next;
    }

    for (int i = 0; i < vec.size(); i++) {
        aux->next = new Node(vec[i], nullptr);
        aux = aux->next;
    }
    m_size += vec.size();
}

void ForwardList::swap(ForwardList &lst) {
    Node *aux = m_head->next;
    m_head = lst.m_head->next;
    lst.m_head = aux->next;
    unsigned int lst_size = lst.size();
    lst.m_size = m_size;
    m_size = lst_size;
}

bool ForwardList::operator==(const ForwardList &lst) const {
    if (m_size != lst.size()) {
        return false;
    }

    Node *lst_aux = lst.m_head->next;
    Node *aux = m_head->next;
    while (aux != nullptr) {
        if (aux->data != lst_aux->data) {
            return false;
        }
        aux = aux->next;
        lst_aux = lst_aux->next;
    }
    return true;
}
bool ForwardList::operator!=(const ForwardList &lst) const {
    if (m_size == lst.size()) {
        return false;
    }

    Node *lst_aux = lst.m_head->next;
    Node *aux = m_head->next;
    while (aux != nullptr) {
        if (aux->data != lst_aux->data) {
            return true;
        }
        aux = aux->next;
        lst_aux = lst_aux->next;
    }
    return true;
}

void ForwardList::reverse() {
    Node *aux = m_head->next;
    Node *previous = nullptr;
    Node *next = nullptr;

    while (aux != nullptr) {
        next = aux->next;
        aux->next = previous;
        previous = aux;
        aux = next;
    }
    m_head->next = previous;
}