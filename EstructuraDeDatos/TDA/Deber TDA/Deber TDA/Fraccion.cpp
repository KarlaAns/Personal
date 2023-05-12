/*UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Nombre del archivo: Fraccion.cpp
 * Fecha de creación: 10/05/2023
 * Fecha de modificación: 11/05/2023
 * Autores:  Karla Ansatuña, Alexis Chimba, Matias Suárez
 * Descripción: Implementacion de la clase Fraccion
 */


#include "Fraccion.h"
#include "Proceso.h"
#include <iostream>
////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::getNumerador()
// Purpose:    Implementation of Fraccion::getNumerador()
// Return:     float
////////////////////////////////////////////////////////////////////////

float Fraccion::getNumerador(void)
{
   return numerador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::setNumerador(float newNumerador)
// Purpose:    Implementation of Fraccion::setNumerador()
// Parameters:
// - newNumerador
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fraccion::setNumerador(float newNumerador)
{
   numerador = newNumerador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::getDenominador()
// Purpose:    Implementation of Fraccion::getDenominador()
// Return:     float
////////////////////////////////////////////////////////////////////////

float Fraccion::getDenominador(void)
{
   return denominador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::setDenominador(float newDenominador)
// Purpose:    Implementation of Fraccion::setDenominador()
// Parameters:
// - newDenominador
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fraccion::setDenominador(float newDenominador)
{
   denominador = newDenominador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::Fraccion(float num, float den)
// Purpose:    Implementation of Fraccion::Fraccion()
// Parameters:
// - num
// - den
// Return:
////////////////////////////////////////////////////////////////////////

Fraccion::Fraccion(float num, float den)
{
   // TODO : implement
   this->numerador=num;
   this->denominador=den;
}

Fraccion::Fraccion(){
	this->numerador=0;
	this->denominador=0;
}
////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::~Fraccion()
// Purpose:    Implementation of Fraccion::~Fraccion()
// Return:
////////////////////////////////////////////////////////////////////////

Fraccion::~Fraccion()
{
   // TODO : implement
}

Fraccion Fraccion::calculo(Fraccion obj1, Fraccion obj2){
	Fraccion obj3;
	obj3.setDenominador(obj1.getDenominador()*obj2.getDenominador());
	obj3.setNumerador((obj1.getNumerador()*obj2.getDenominador())+(obj2.getNumerador()*obj1.getDenominador()));
	return obj3;
}

void Fraccion::imprimir(Fraccion obj){
	std::cout<<obj.getNumerador()<<"/"<<obj.getDenominador();
}

float Fraccion::calculo(float obj1, float obj2){
	return (obj1/obj2);
}
