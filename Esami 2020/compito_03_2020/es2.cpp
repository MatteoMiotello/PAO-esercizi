#include <iostream>

using namespace std;

// Siano A, B, C e D distinte classi polimorfe e si considerino le seguenti definizioni.

class A { public: virtual ~A(){} };

class B: public A{};

class C: public A{};

class D: public B{};

template<class X>
X* fun(X& ref) { return &ref; }             // ritorna tipo dinamico !

int main() {
    B b;
    fun<A>(b);
    B* p = new D();
    C c;
    if (dynamic_cast<B*>(fun<A>(c))) cout << "bianco ";
    else cout << "nero ";
    if( !(dynamic_cast<D*>(new B()))) cout << "rosso ";
}

// Si supponga che:
// 1. il main() compili correttamente ed esegua senza provocare errori a run-time;
// 2. l’esecuzione del main() provochi in output su cout la stampa nero rosso.

// B <= A
// C <= A
// D <= A
// D <= B

