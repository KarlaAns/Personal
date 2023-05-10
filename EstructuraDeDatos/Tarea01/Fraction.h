#ifndef FRACCION_H
#define FRACCION_H

class Fraccion {
  private:
    int numerador;
    int denominador;
  
  public:
    Fraccion(int num, int den);
    Fraccion suma(Fraccion SegundaFraccion);
    Fraccion resta(Fraccion SegundaFraccion);
    Fraccion multiplicacion(Fraccion SegundaFraccion);
    Fraccion division(Fraccion SegundaFraccion);
    void simplificar();
    void imprimir();
    
    // Getter para el atributo numerador
    int getNumerador() const {
      return numerador;
    }
    
    // Setter para el atributo numerador
    void setNumerador(int num) {
      numerador = num;
    }
    
    // Getter para el atributo denominador
    int getDenominador() const {
      return denominador;
    }
    
    // Setter para el atributo denominador
    void setDenominador(int den) {
      denominador = den;
    }
    
  private:
    int calcularMcd(int mcdNumerador, int mcdDenominador);
};
#endif
