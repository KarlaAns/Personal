/***********************************************************************
 * Module:  Entrada_Persona.h
 * Author:  alejo
 * Modified: Thursday, 15 June 2023 6:09:54 pm
 * Purpose: Declaration of the class Entrada_Persona
 ***********************************************************************/

#if !defined(__Proyecto_Entrada_Persona_h)
#define __Proyecto_Entrada_Persona_h

#include <Persona.h>

class Entrada_Persona
{
public:
   Persona getPersona(void);
   void setPersona(Persona newPersona);
   std::string getHoraEntrada(void);
   void setHoraEntrada(std::string newHoraEntrada);
   std::string getHoraSalida(void);
   void setHoraSalida(std::string newHoraSalida);
   Entrada_Persona();
   ~Entrada_Persona();

protected:
private:
   Persona Persona;
   std::string HoraEntrada;
   std::string HoraSalida;


};

#endif