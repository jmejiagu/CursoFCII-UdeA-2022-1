/*
Tarea # 2 
Santiago Ruiz Piedrahita

El programa juega a craps y ademas permite hacer apuestas

Explicacion del juego:
Un jugador tira dos dados. Cada dado tiene seis caras, las cuales contienen 1, 2, 3, 4, 5 y 6 puntos negros. Una
vez que los dados dejan de moverse, se calcula la suma de los puntos negros en las dos caras superiores. Si la
suma es 7 u 11 en el primer tiro, el jugador gana. Si la suma es 2, 3 o 12 en el primer tiro (llamado “craps”),
el jugador pierde (es decir, la “casa” gana). Si la suma es 4, 5, 6, 8, 9 o 10 en el primer tiro, esta suma se
convierte en el “punto” del jugador. Para ganar, el jugador debe seguir tirando los dados hasta que salga otra
vez “su punto”. El jugador pierde si tira un 7 antes de llegar a su punto.
*/

#include <iostream>
#include <cstdlib> // contiene los prototipos para las funciones srand y rand
#include <ctime> // contiene el prototipo para la función time

using namespace std;

int tirarDados(); // tira los dados, calcula y muestra la suma
int JugarCraps(); // Juega a craps

// enumeración con constantes que representa el estado del juego
enum Estado { CONTINUAR, GANO, PERDIO }; // todas las constantes en mayúsculas. Enumeration Types Prior to C++11
  
Estado estadoJuego; // puede contener CONTINUAR, GANO o PERDIO

int JugarCraps()
{
   unsigned int miPunto = 0; // punto si no se gana o pierde en el primer tiro
  
  // randomiza el generador de números aleatorios, usando la hora actual
  srand( time( 0 ) );

  int sumaDeDados = tirarDados(); // primer tiro del dado
  // determina el estado del juego y el punto (si es necesario), con base en el primer tiro
  switch ( sumaDeDados )
    {
    case 7: // gana con 7 en el primer tiro
    case 11: // gana con 11 en el primer tiro
      estadoJuego = GANO;
      break;
    case 2: // pierde con 2 en el primer tiro
    case 3: // pierde con 3 en el primer tiro
    case 12: // pierde con 12 en el primer tiro
      estadoJuego = PERDIO;
      break;
    default: // no ganó ni perdió, por lo que recuerda el punto
      estadoJuego = CONTINUAR; // el juego no ha terminado
      miPunto = sumaDeDados; // recuerda el punto
      cout << "El punto es " << miPunto << endl;
      break; // opcional al final del switch
    } // fin de switch

  // mientras el juego no esté completo
  while ( estadoJuego == CONTINUAR ) // no ganó ni perdió
    {
      sumaDeDados = tirarDados(); // tira los dados de nuevo
      
      // determina el estado del juego
      if ( sumaDeDados == miPunto ) // gana al hacer un punto
	estadoJuego = GANO;
      else if ( sumaDeDados == 7 ) // pierde al tirar 7 antes del punto
	  estadoJuego = PERDIO;
    } // fin de while
  
  // muestra mensaje de que ganó o perdió
  if ( estadoJuego == GANO )
    cout << "El jugador gana" << endl;
  else
    cout << "El jugador pierde" << endl;
  return 0; // indica que terminó correctamente
} // fin de JugarCraps

// tira los dados, calcula la suma y muestra los resultados
int tirarDados()
{
  // elige valores aleatorios para el dado
  int dado1 = 1 + rand() % 6; // tiro del primer dado
  int dado2 = 1 + rand() % 6; // tiro del segundo dado
  
  int suma = dado1 + dado2; // calcula la suma de valores de los dados
  
  // muestra los resultados de este tiro
  cout << "El jugador tiro " << dado1 << " + " << dado2
       << " = " << suma << endl;
  return suma; // devuelve la suma de los dados
} // fin de la función tirarDados

int SaldoenBanco = 1000000;
int Apuesta;
int Cont = 0;
int Cont2 = 1;

int main()
{
    cout << "Bienvenido al juego de apuestas con Craps" << endl;
	
    while(Cont2==1)
    {
    while(Cont==0)
    {
    cout << "Ingrese una apuesta:" << endl; 
    cin >> Apuesta;
    
    if(Apuesta>=0 and Apuesta<=SaldoenBanco)
    Cont = 1;
    
    else
    {
    Cont = 0;
    cout << "Ingrese una apuesta correcta" << endl;
    }
        
    if (Apuesta>200000)
    {
    cout << "Apuesta muy alta, ¿Seguro que quiere continuar? (SI=1 , NO=0)" << endl; 
    cin >> Cont;
    }
    }
    
    JugarCraps();
    
    if (estadoJuego==GANO)
    {
    SaldoenBanco = SaldoenBanco+Apuesta;
    cout << "El saldo en el banco es de: " << SaldoenBanco << endl;
    }
    
    else if (estadoJuego==PERDIO)
    {
    SaldoenBanco = SaldoenBanco-Apuesta;
    cout << "El saldo en el banco es de: " << SaldoenBanco << endl;
    }    
    
    if (SaldoenBanco<=100000)
    {
    cout << "usted se esta quebrando, ¿no le parece?" << SaldoenBanco << endl;
    cout << "El saldo en el banco es de: " << SaldoenBanco << endl;
    }
    
    if (SaldoenBanco<=0)
    {
    cout << "Lo siento. Se quedo sin fondos!"  << endl;
    cout << "El saldo en el banco es de: " << SaldoenBanco << endl;
    Cont2 = 0;
    }
    
    if (SaldoenBanco>=2000000)
    {
    cout << "La sacaste del estadio. Ahora es tiempo de cambiar sus fichas por  la plata!" << endl;
    cout << "El saldo en el banco es de: " << SaldoenBanco << endl;
    }
    
    if (Cont2==1)
    {
    cout << "¿Quieres jugar de nuevo? (SI=1 , NO=0)" << endl; 
    cin >> Cont2;
    if (Cont2==1)
    Cont =0;
    }
    }
    
    cout << "Juego terminado, usted termino con " << SaldoenBanco<<" pesos en el banco"<< endl;
    
} // Fin de main
