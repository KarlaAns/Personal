/***********************************************************************
 * Module:  Persona.h
 * Author:  alejo
 * Modified: Thursday, 15 June 2023 6:09:54 pm
 * Purpose: Declaration of the class Persona
 ***********************************************************************/

#if !defined(__Proyecto_Persona_h)
#define __Proyecto_Persona_h

class Entrada_Persona;

class Persona
{
public:
   std::string getCedula(void);
   void setCedula(std::string newCedula);
   std::string getNombre(void);
   void setNombre(std::string newNombre);
   std::string getApellido(void);
   void setApellido(std::string newApellido);
   Persona();
   ~Persona();

   Entrada_Persona** entrada_Persona;

protected:
private:
   std::string Cedula;
   std::string Nombre;
   std::string Apellido;


};

#endif