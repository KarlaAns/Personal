#include "Fraction.h"
#include <iostream>

using namespace std;

Fraccion::Fraccion(int num, int den) {
  numerador = num;
  denominador = den;
}

Fraccion Fraccion::suma(Fraccion segundaFraccion) {
  int nuevoNumerador = numerador * segundaFraccion.denominador + denominador * segundaFraccion.numerador;
  int nuevoDenominador = denominador * segundaFraccion.denominador;
  return Fraccion(nuevoNumerador, nuevoDenominador);
}

Fraccion Fraccion::resta(Fraccion segundaFraccion) {
  int nuevoNumerador = numerador * segundaFraccion.denominador - denominador * segundaFraccion.numerador;
  int nuevoDenominador = denominador * segundaFraccion.denominador;
  return Fraccion(nuevoNumerador, nuevoDenominador);
}

Fraccion Fraccion::multiplicacion(Fraccion segundaFraccion) {
  int nuevoNumerador = numerador * segundaFraccion.numerador;
  int nuevoDenominador = denominador * segundaFraccion.denominador;
  return Fraccion(nuevoNumerador, nuevoDenominador);
}

Fraccion Fraccion::division(Fraccion segundaFraccion) {
  int nuevoNumerador = numerador * segundaFraccion.denominador;
  int nuevoDenominador = denominador * segundaFraccion.numerador;
  return Fraccion(nuevoNumerador, nuevoDenominador);
}

void Fraccion::simplificar() {
  int mcd = calcularMcd(numerador, denominador);
  numerador /= mcd;
  denominador /= mcd;
}

void Fraccion::imprimir() {
  cout << numerador << "/" << denominador << endl;
}

int Fraccion::calcularMcd(int mcdNumerador, int mcdDenominador) {
  if (mcdDenominador == 0) {
    return mcdNumerador;
  } else {
    return calcularMcd(mcdDenominador, mcdNumerador % mcdDenominador);
  }
}