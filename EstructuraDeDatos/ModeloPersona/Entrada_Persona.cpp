/***********************************************************************
 * Module:  Entrada_Persona.cpp
 * Author:  alejo
 * Modified: Thursday, 15 June 2023 6:09:54 pm
 * Purpose: Implementation of the class Entrada_Persona
 ***********************************************************************/

#include "Entrada_Persona.h"

////////////////////////////////////////////////////////////////////////
// Name:       Entrada_Persona::getPersona()
// Purpose:    Implementation of Entrada_Persona::getPersona()
// Return:     Persona
////////////////////////////////////////////////////////////////////////

Persona Entrada_Persona::getPersona(void)
{
   return Persona;
}

////////////////////////////////////////////////////////////////////////
// Name:       Entrada_Persona::setPersona(Persona newPersona)
// Purpose:    Implementation of Entrada_Persona::setPersona()
// Parameters:
// - newPersona
// Return:     void
////////////////////////////////////////////////////////////////////////

void Entrada_Persona::setPersona(Persona newPersona)
{
   Persona = newPersona;
}

////////////////////////////////////////////////////////////////////////
// Name:       Entrada_Persona::getHoraEntrada()
// Purpose:    Implementation of Entrada_Persona::getHoraEntrada()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Entrada_Persona::getHoraEntrada(void)
{
   return HoraEntrada;
}

////////////////////////////////////////////////////////////////////////
// Name:       Entrada_Persona::setHoraEntrada(std::string newHoraEntrada)
// Purpose:    Implementation of Entrada_Persona::setHoraEntrada()
// Parameters:
// - newHoraEntrada
// Return:     void
////////////////////////////////////////////////////////////////////////

void Entrada_Persona::setHoraEntrada(std::string newHoraEntrada)
{
   HoraEntrada = newHoraEntrada;
}

////////////////////////////////////////////////////////////////////////
// Name:       Entrada_Persona::getHoraSalida()
// Purpose:    Implementation of Entrada_Persona::getHoraSalida()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Entrada_Persona::getHoraSalida(void)
{
   return HoraSalida;
}

////////////////////////////////////////////////////////////////////////
// Name:       Entrada_Persona::setHoraSalida(std::string newHoraSalida)
// Purpose:    Implementation of Entrada_Persona::setHoraSalida()
// Parameters:
// - newHoraSalida
// Return:     void
////////////////////////////////////////////////////////////////////////

void Entrada_Persona::setHoraSalida(std::string newHoraSalida)
{
   HoraSalida = newHoraSalida;
}

////////////////////////////////////////////////////////////////////////
// Name:       Entrada_Persona::Entrada_Persona()
// Purpose:    Implementation of Entrada_Persona::Entrada_Persona()
// Return:     
////////////////////////////////////////////////////////////////////////

Entrada_Persona::Entrada_Persona()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Entrada_Persona::~Entrada_Persona()
// Purpose:    Implementation of Entrada_Persona::~Entrada_Persona()
// Return:     
////////////////////////////////////////////////////////////////////////

Entrada_Persona::~Entrada_Persona()
{
   // TODO : implement
}