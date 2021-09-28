#include <iostream>
using namespace std;

template <class T>
class Nodo
{
public:
    T m_Dato;
    Nodo<T> *m_pSig;

public:
    Nodo(T d)
    {
        m_Dato = d;
        m_pSig = nullptr;
    }
};

template <class T>
class List
{
private:
    Nodo<T> *m_pHead;
    Nodo<T> *m_ptail;
    int size;

public:
    List()
    {
        this->m_pHead = nullptr;
        this->m_ptail = nullptr;
        this->size = 0;
    }
    //insertar al inicio(recursivo e iterativo)
    void push_front_dato(T dato)
    {
        Nodo<T> *new_node = new Nodo<T>(dato);
        if (!m_pHead)
        {
            this->m_pHead = new_node;
            this->m_ptail = m_pHead;
            this->m_ptail = m_pHead;
            size++;
        }
        else
        {
            new_node->m_pSig = this->m_pHead;
            m_pHead = new_node;
            size++;
        }
    }

    void push_front(Nodo<T> *tmp, T d)
    {

        if (tmp->m_pSig == nullptr){
            tmp->m_pSig = new Nodo<T>(d);
            this->m_ptail->m_pSig = m_pHead;
        }
        else
        {
            this->push_front(tmp->m_pSig, d);
        }
    }

    void push_front_recursivo(T d)
    {
        if (m_pHead == nullptr)
            m_pHead = new Nodo<T>(d);
        else
            this->push_front(this->m_pHead, d);
    }
    
    void push_back(T dato)
    {
        Nodo<T> *new_node = new Nodo<T>(dato);
        if (!m_pHead)
        {
            this->m_pHead = new_node;
            this->m_ptail = m_pHead;
        }
        else
        {
            Nodo<T> *current_node = m_pHead;
            while (current_node != this->m_ptail)
            {
                current_node = current_node->m_pSig;
            }
            current_node->m_pSig = new_node;
            m_ptail = new_node;
            m_ptail->m_pSig = m_pHead;
        }
        size++;
    }
    void recursive_pushBack(T dato, Nodo<T> *ptr)
    {
        if (ptr == this->m_ptail)
        {
            Nodo<T> *new_node = new Nodo<T>(dato);
            this->m_ptail->m_pSig = new_node;
            this->m_ptail=new_node;
            this->m_ptail->m_pSig = this->m_pHead;
            return;
        }
        else
        {
            recursive_pushBack(dato, ptr->m_pSig);
        }
    }
    bool find_iterativo(T d)
    {
        Nodo<T> *tmp = m_pHead;
        while (tmp)
        {
            if (tmp->m_Dato == d)
                return true;
            tmp = tmp->m_pSig;
        }
        return false;
    }

    bool findRecursivo(Nodo<T> *tmp, T d)
    {

        if (tmp->m_Dato == d)
            return true;
        else if(tmp->m_Dato!=d)
        {
            return false;
        }
        return this->findRecursivo(tmp->m_pSig, d);
    }

    bool mostrarfindRecursivo(T d)
    {
        return this->findRecursivo(this->m_pHead, d);
    }

    int iterative_max()
    {
        Nodo<T> *aux = m_pHead;
        T max_val = aux->m_Dato;
        for (; aux; aux = aux->m_pSig)
        {
            if (aux->m_Dato > max_val)
            {
                max_val = aux->m_Dato;
            }
        }

        return max_val;
    }

    T recursive_max()
    {
        if(m_pHead == nullptr)
            return;
        returnrecursive_max(this->m_pHead, this->m_pHead->m_Dato);
    } 

    T recursive_max(Nodo<T> *nodo, T tmp_max)
    {
        if (!nodo)
        {
            return tmp_max;
        }
        if (nodo->m_Dato > tmp_max)
        {
            tmp_max = nodo->m_Dato;
        }
        return recursive_max(nodo->m_pSig, tmp_max);
    }
    void print_iterativo()
    {
        Nodo<T> *temp = m_pHead;
        if (!m_pHead)
            cout << "Lista vacia ";
        else
        {
            for (int i = 1; i <= size; i++)
            {
                cout << temp->m_Dato << " -> ";
                temp = temp->m_pSig;
            }
        }
            
    }

    void recursive_print(Nodo<T> *nodo)
    {
        if (nodo)
        {
            recursive_print(nodo->m_pSig);
            
            cout << nodo->m_Dato << "->";
        }
        else
        {
            cout << '\n';
        }
    }
    void recursive_print()
    {
        recursive_print(this->m_pHead);
    }

    void insertByPosition(T value, int pos) 
    { 
        Nodo<T> *newNode = new Nodo<T>(value);
        if(m_pHead==nullptr){
            m_pHead = newNode;
        } 
        else 
        {
            if(pos==0){
                push_front(value);
        }
        else{
            Nodo<T> *current_node = m_pHead;
            Nodo<T> *previous_node = nullptr;
            for (int count = 1; count < pos; count++)
            {
                previous_node=current_node;
                current_node=current_node->m_pSig;
            }
            previous_node->m_pSig=newNode;
            newNode->m_pSig = current_node;
        }
    }
    size++;
    }

    void insertar_alfabetica(T d)
    {
        Nodo<T> *new_node = new Nodo<T>(d);
        T temp_data;
        Nodo<T> *aux_node = m_pHead;
        Nodo<T> *temp = aux_node;

        while (aux_node)
        {
            temp = aux_node;

            while (temp->m_pSig)
            {
                temp = temp->m_pSig;

                if (new_node->m_Dato < temp->m_Dato)
                {
                    temp_data = aux_node->m_Dato;
                    aux_node->m_Dato = temp->m_Dato;
                    temp->m_Dato = temp_data;
                }
            }

            m_pHead= new_node;
            aux_node = aux_node->m_pSig;

        }
    }
};

int main()
{

    List<int> L1;
    //L1.insertar_alfabetica(2);
    L1.push_front_dato(4);
    L1.push_front_recursivo(2);
    L1.recursive_print();
    L1.print_iterativo();
    return 0;
}