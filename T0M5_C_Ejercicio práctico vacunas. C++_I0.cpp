/*
 * Programa C++
 * Calcular la edad de una persona a partir de su fecha de nacimiento y la fecha actual                           
 */
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <cstdlib>
using namespace std;


int main(void)
{

     // current date/time based on current system
   time_t now = time(0);
    // Nùmero de segundos desde el 1 de enero de 1970
   //cout << "Number of sec since January 1,1970 is:: " << now << endl;

   tm *ltm = localtime(&now);

    //declaración de variables
    int dn, mn, an, da, ma, aa,edad;
    system("cls");
	
    //Lectura de las fechas
    //Supondremos que las fechas introducidas son correctas

    //Introducir por teclado la fecha de nacimiento
    cout << "\nFecha de nacimiento:\n";
    cout << "\nDia: ";
    cin >> dn;
    cout << "\nMes: ";
    cin >> mn;
    cout << "\nAnio: ";
    cin >> an;

 // print various components of tm structure.
 //  cout << "Year:" << 1900 + ltm->tm_year<<endl;
 //  cout << "Month: "<< 1 + ltm->tm_mon<< endl;
 //  cout << "Day: "<< ltm->tm_mday << endl;
  // cout << "Time: "<< 5+ltm->tm_hour << ":";
  // cout << 30+ltm->tm_min << ":";
 //  cout << ltm->tm_sec << endl;

    da= ltm->tm_mday;
    ma= 1 + ltm->tm_mon;
    aa=1900 + ltm->tm_year;

    //restar años actual menos año de nacimiento para obtener la edad                                             
    edad = aa - an;

    //comparar mes y día de nacimiento con mes y día actual
    //por si la persona aún no ha cumplido los años
    if(mn > ma){
       edad--;
   } else if(ma == mn){
            if(dn > da){
               edad--;
            }else if(da == dn){
                    cout << "\nFelicidades!!! Hoy es tu cumpleaños" << endl;
            } 
   }
    
    //se muestra la edad
    cout << "\nTiene " << edad << " anios de edad"<<endl;

    if(edad > 65){
        cout << "\nUsted es candidato para la vacuna. "<<endl;
    }else if(edad == 64 && ma-mn){
        cout << "\nUsted estará en lista de espera. "<<endl;
    }else{
        cout << "\nUsted no es candidato para la vacuna. "<<endl;
    }

     cout << "\n "<<endl;
    
   // system("pause");
}