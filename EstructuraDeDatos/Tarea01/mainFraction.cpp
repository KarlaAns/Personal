#include "Fraction.h"
#include <iostream>

using namespace std;

int main() {
	/*constructor, destructor, getters, setters (pedir numeros al usuario)*/
	Fraccion f1(1, 2);
	Fraccion f2(3, 4);

	Fraccion f3 = f1.suma(f2);
	Fraccion f4 = f1.resta(f2);
	Fraccion f5 = f1.multiplicacion(f2);
	Fraccion f6 = f1.division(f2);

	f3.simplificar();
	f4.simplificar();
	f5.simplificar();
	f6.simplificar();

	f3.imprimir();
	f4.imprimir();
	f5.imprimir();
	f6.imprimir();

	return 0;
}