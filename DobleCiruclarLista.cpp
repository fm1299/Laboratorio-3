//JULIO ENRIQUE YAURI ITUCCAYASI
//FABRIZIO MIGUEL MATTOS CAHUI
//RONALD ROMARIO GUTIERREZ ARRATIA
#include <iostream>
using namespace std;
template <class T>
class Nodo
{
public:
    T m_Dato;
    Nodo<T> *m_pSig;
    Nodo<T> *m_pAnt;
    Nodo(T d)
    {
        m_Dato = d;
        m_pSig = nullptr;
        m_pAnt = nullptr;
    }
};
template <class T>
class ListD
{
private:
    Nodo<T> *m_pHead;
    Nodo<T> *m_pTail;
    int size;

public:
    ListD() : m_pHead(0), m_pTail(0), size(0){};
    //insertar inicio
    void push_front(T d)
    {
        if (!m_pHead)
        {
            m_pHead = new Nodo<T>(d);
            m_pTail = m_pHead;
            m_pHead->m_pAnt = m_pHead;
            m_pTail->m_pAnt = m_pHead;
            m_pHead->m_pSig = m_pHead;
            m_pTail->m_pSig = m_pHead;
            size++;
            return;
        }
        Nodo<T> *nuevo = new Nodo<T>(d);
        nuevo->m_pSig = m_pHead;
        nuevo->m_pAnt = m_pTail;
        m_pHead->m_pAnt = nuevo;
        m_pTail->m_pSig = nuevo;
        m_pHead = nuevo;
    }

    //insertar final (iter y recur)
    void push_back_iterativo(T d)
    {
        if (!m_pHead)
        {
            m_pHead = new Nodo<T>(d);
            m_pTail = m_pHead;
            m_pHead->m_pAnt = m_pHead;
            m_pTail->m_pAnt = m_pHead;
            m_pHead->m_pSig = m_pHead;
            m_pTail->m_pSig = m_pHead;
            size++;
            return;
        }
        Nodo<T> *nuevo = new Nodo<T>(d);
        nuevo->m_pAnt = m_pTail;
        m_pTail->m_pSig = nuevo;
        m_pTail = nuevo;
        m_pTail->m_pSig = m_pHead;
        m_pHead->m_pAnt = m_pTail;
        size++;
    }
    //insertar en posicion p
    void insert(T d, int posicion)
    {
        if (posicion > size + 1 || posicion <= 0)
        {
            cout << "Posicion fuera de rango\n";
            return;
        }
        posicion--;
        Nodo<T> *tmp = m_pHead;
        Nodo<T> *nuevo = new Nodo<T>(d);
        while (--posicion)
        {
            tmp = tmp->m_pSig;
        }
        nuevo->m_pSig = tmp->m_pSig;
        nuevo->m_pAnt = tmp;
        (tmp->m_pSig)->m_pAnt = nuevo;
        tmp->m_pSig = nuevo;
        size++;
    }
    //ordenar lista
    void sort() {
		if(!m_pHead) return;
		bool continuar = false;
		do {
			continuar = false;
    		Nodo<T> * aux_node = m_pHead;
    		cout << "entra\n";
    		while(true) {
    			if(aux_node -> m_pSig -> m_Dato < aux_node -> m_Dato) {
					swap(aux_node -> m_pSig -> m_Dato, aux_node -> m_Dato);
					continuar = true;	
				}
				if(aux_node == m_pHead) break;	
    		}
		}while(continuar);
    }
    //insertar en forma alfabetica

    //buscar un elemento (iter y recur)
    bool find_iterativo(T d) {
        if(!m_pHead) return false;
        Nodo<T> **l = &m_pHead;
        Nodo<T> **r = &m_pLast;
        while(l != r) {
            if((*l) -> m_Dato == d || (*r) -> m_Dato == d) return true;
            if(*l == *r) return false;
            l = &((*l) -> m_pSig);
            if(*l == *r) return false;
            r = &((*r) -> m_pAnt);
        }
        return false;
    }
    //hallar maximo (iter y recur)
    T iterative_max() {
		try {
			if(!m_pHead) {
				T nulo;
				throw (nulo);		
			}else{
				Nodo<T> * tmp = m_pHead;
				T max_val = tmp -> m_Dato;
				tmp = tmp -> m_pSig;
				for(; tmp != m_pHead; tmp = tmp -> m_pSig) {
					if( tmp -> m_Dato > max_val) max_val = tmp -> m_Dato;
				}
				return max_val;
			}
		}catch(T nulo_) {
			cout << "Lista vacia, no existe maximo\n";	
			return nulo_;
		}
    }
    T recursive_max(Nodo<T> * actual) {
		try {
    		if(!m_pHead) {
    			T nulo;
    			throw (nulo);
    		}else{
    			Nodo<T> * tmp = actual;
    			T max_val = tmp -> m_Dato;
    			max_val = max(max_val, tmp-> m_Dato);
    			if(tmp -> m_pSig == m_pHead) return max_val;	
    			else return recursive_max(tmp -> m_pSig);
    		}
    	}catch(T nulo_) {
    		cout << "Lista vacía, no existe maximo\n";
			return nulo_;
		}
    }
    //imprimir (iter y recur)
    void print_iterativo()
    {
        Nodo<T> *tmp = m_pHead;
        while (true)
        {
            cout << tmp->m_Dato << " -> ";
            tmp = tmp->m_pSig;
            if (tmp == m_pHead)
            {
                cout << '\n';
                return;
            }
        }
    }
    void print_recursivo(Nodo<T> *aux)
    {
        cout << aux->m_Dato << " <-> ";
        if (aux->m_pSig == m_pHead)
            return;
        else
            print_recursivo(aux->m_pSig);
    }
};
//leer archivo txt, almacenar palabra y numero de ocurrencias
int main()
{

    ListD<int> L1;
    L1.push_front(5);
    L1.push_front(21);
    L1.push_front(23);
    L1.push_front(234234);
    L1.push_front(123);
    L1.print_iterativo();
}
