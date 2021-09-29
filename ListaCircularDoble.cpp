#include <iostream>
#include <utility>
#include <fstream> 
using namespace std; 
template<class T>
class Nodo {
 public: 
    T m_Dato;
    Nodo<T> * m_pSig;
    Nodo<T> * m_pAnt;
    Nodo() : m_pSig(0), m_pAnt(0) {};
    Nodo(T d) {
    	m_Dato = d;
    	m_pSig = nullptr;
    	m_pAnt = nullptr;
    }
};
template<class T>
class ListD {
private: 
    Nodo<T> * m_pHead;
    Nodo<T> * m_pTail;
    int size;
public:
    ListD() : m_pHead (0), m_pTail(0), size(0) {};
    Nodo<T>* getHead() {
    	return m_pHead;	
    }
    /////////////insertar inicio 
    void push_front(T d) {
        if(!m_pHead) {
            m_pHead = new Nodo<T>(d);
            m_pTail = m_pHead;
            m_pHead -> m_pAnt = m_pHead;
            m_pTail -> m_pAnt = m_pHead;
            m_pHead -> m_pSig = m_pHead;
            m_pTail -> m_pSig = m_pHead;
            size++;
            return;
        }
        Nodo<T> * nuevo = new Nodo<T>(d);
    	nuevo -> m_pSig = m_pHead;
   		nuevo -> m_pAnt = m_pTail;
   		m_pHead -> m_pAnt = nuevo;
   		m_pTail -> m_pSig = nuevo;
   		m_pHead = nuevo;
   		size++;
	}

    //////////////////////insertar al final
	//iterativo 
   	void push_back_iterativo(T d) {
   		if(!m_pHead) {
   			m_pHead = new Nodo<T>(d);
            m_pTail = m_pHead;
            m_pHead -> m_pAnt = m_pHead;
            m_pTail -> m_pAnt = m_pHead;
            m_pHead -> m_pSig = m_pHead;
            m_pTail -> m_pSig = m_pHead;
            size++;
            return;
   		}
   		Nodo<T> * nuevo = new Nodo<T>(d);
		nuevo -> m_pAnt = m_pTail;
		nuevo -> m_pSig = m_pHead;
		m_pTail -> m_pSig = nuevo;
		m_pHead -> m_pAnt = nuevo;
		m_pTail = nuevo;
		size++;
   	}
   	//recursivo
   	void push_back_recursivo(T d, Nodo<T> * actual) {
   		if(!m_pHead) {
   			push_back_iterativo(d);
   			return;
   		}
		if(actual == m_pTail) {
   			Nodo<T> * nuevo = new Nodo<T>(d);
   			nuevo -> m_pAnt = m_pTail;
   			nuevo -> m_pSig = m_pHead;
   			m_pTail -> m_pSig = nuevo;
   			m_pHead -> m_pAnt = nuevo;
   			m_pTail = nuevo;
   			size++;
   			return;
		}else push_back_recursivo(d, actual -> m_pSig);
   	}
   	
    //////////////////////insertar en posicion p
    void insert(T d, int posicion) {
    	if(posicion > size + 1 || posicion <= 0) {
    		cout << "Posicion fuera de rango\n";
    		return;
		}
		if(posicion == 1) {
			push_front(d);
			return;	
		}
		if(posicion == size + 1) {
			push_back_iterativo(d);
			return;
		}
		Nodo<T> *tmp = m_pHead;
		Nodo<T> *nuevo = new Nodo<T>(d);
		posicion--;
		while(posicion > 0) {
			tmp = tmp -> m_pSig;
			posicion--;
		}
    	nuevo -> m_pSig = tmp -> m_pSig;
		nuevo -> m_pAnt = tmp;
		(tmp -> m_pSig) -> m_pAnt = nuevo;
		tmp -> m_pSig = nuevo;
		size++;
	}	
    //ordena la lista
    void sort() {
		if(!m_pHead) return;
		bool continuar = false;
		do {
			continuar = false;
    		Nodo<T> * aux_node = m_pHead;
    		while(true) {
    			if((aux_node -> m_pSig) -> m_Dato < (aux_node -> m_Dato)) {
					swap(aux_node -> m_pSig -> m_Dato, aux_node -> m_Dato);
					continuar = true;
				}
				aux_node = aux_node -> m_pSig;
				if(aux_node -> m_pSig == m_pHead) break;	
    		}
		}while(continuar);
    }
    ///////////////////insertar en forma alfabetica
	void insert_ordenado(T d) {
		if(!m_pHead) return;
		sort();
		Nodo<T> * tmp = m_pHead;
		int posicion = 1;
		while(true) {
			tmp = tmp -> m_pSig;
			if(tmp -> m_Dato > d || tmp == m_pHead) break;
			posicion ++; 	
		}
		cout << posicion << '\n';
		insert(d, posicion);
	}
    
	//////////////////buscar un elemento
    //iterativo
	bool find_iterativo(T d) {
		if(!m_pHead) return false;
		Nodo<T> **l = &m_pHead;
		Nodo<T> **r = &m_pTail;
		while(true) {
			if((*l) -> m_Dato == d || (*r) -> m_Dato == d) return true;
			if(*l == *r) return false;
			l = &((*l) -> m_pSig);
			if(*l == *r) return false;
			r = &((*r) -> m_pAnt);
		}
		return false;
	}
	//recursivo 
	bool find_recursivo(T d, Nodo<T> * actual) {
		if(!m_pHead) return false;
		if(actual == m_pTail) return d == actual -> m_Dato;
		if(d == actual -> m_Dato) return true;
		else return find_recursivo(d, actual -> m_pSig);		
	}
	
    ///////////////////////////hallar maximo 
    //iterativo 
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
			cout << "Lista vacia, no existe maximo, retornando basura\n";	
			return nulo_;
		}
    }
    //recursivo
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
    		cout << "Lista vacia, no existe maximo, retornando basura\n";
			return nulo_;
		}
    }
    ///////////////////contar pares iterativo y recursivo
    //iterativo 
	int contar_pares_iter() {
		int cnt = 0;
		Nodo<T> * aux = m_pHead;
		if(!m_pHead) return 0;
		while(true) {
			cnt += ((aux -> m_Dato) % 2 == 0);
			aux = aux -> m_pSig;
			if(aux == m_pHead) return cnt;
		}
	}
    //recursivo
    int contar_pares_recur(Nodo<T> * actual) {
    	if(!m_pHead) return 0;
		if(actual == m_pTail) return (m_pTail -> m_Dato) % 2 == 0;
		else return (actual -> m_Dato % 2 == 0) + contar_pares_recur(actual -> m_pSig);	
    }
    ////////////////////imprimir iterativo y recursivo
    //iterativo
    void print_iterativo() {
		Nodo<T> *tmp = m_pHead;
		while(true) {
			cout << tmp -> m_Dato << " <-> ";	
			tmp = tmp -> m_pSig;
			if(tmp == m_pHead) {
				cout << '\n';
				return;
			}
		}
	}
	void print_reverse() {
		Nodo<T> * tmp = m_pTail;
		while(true) {
			cout << tmp -> m_Dato << " <-> ";
			tmp = tmp -> m_pAnt;
			if(tmp == m_pTail) {
				cout << '\n';
				return;
			}
		}
	}
	//recursivo
	void print_recursivo(Nodo<T> * aux) {
		cout << aux -> m_Dato << " <-> ";
		if(aux -> m_pSig == m_pHead) {
			cout << '\n';
			return;
		}
		else print_recursivo(aux -> m_pSig);
	}
};
//leer archivo txt, almacenar palabra y numero de ocurrencias

void procesar_dato(ListD<pair<string, int> > &l, string s) {
	if(!l.getHead()) {
		pair<string, int> p = {s, 1};
		l.push_front(p);
		return;
	}
	Nodo<pair<string, int> > * aux = l.getHead();	
	while(true) {
		///si encuentra la palabra, aumenta uno al contador y termina
		if((aux->m_Dato).first == s) {
			(aux->m_Dato).second++;
			return;	
		}
		aux = aux -> m_pSig;
		if(aux == l.getHead()) break;	
	}
	pair<string, int> p = {s, 1};
	l.push_back_iterativo(p);
}

int main() {
	//lista para guardar palabras y numero de ocurrencias
	ListD<pair<string, int> > A;	
	//archivo de entrada
	ifstream input("input.txt");
	while(!input.eof()) {
		string s;
		input >> s; 			
		procesar_dato(A, s);
	}
	pair<string, int> a, b;
	Nodo<pair<string, int> > * nodo = A.getHead();
	cout << "Palabra \t numero de ocurrencias\n";
	while(true) {
		cout << nodo->m_Dato.first << "\t\t\t" << nodo->m_Dato.second << '\n';
		nodo = nodo->m_pSig;
		if(nodo == A.getHead()) break; 
	}	
}
