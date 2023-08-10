/* Ejemplo 3LED_bliny para cusos universitarios
 */

#include "mbed.h"
#include <iostream>


// Periodo de parpadeo máximo común divisor - MCD - para los LEDs del LED RGB  
#define BLINKING_PERIOD     20
#define BLINKING_UNITS      "ms"
#define BLINKING_RATE       20ms    // Falta concatenación de BLINKING_PERIOD y BLINKING_UNITS 
// Periodos de parpadeo adimensionalizados de los LEDs: Tx = LEDx_PERIOD*BLINKING_RATE 
#define LEDR_PERIOD         5       
#define LEDG_PERIOD         7       
#define LEDB_PERIOD         11      
// Objeto para establecer la comunicación serial con el Pc
UnbufferedSerial serial(USBTX, USBRX, 9600);
using namespace std;


int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut ledR(LED1, 1);
    DigitalOut ledG(LED2, 1);
    DigitalOut ledB(LED3, 1);
    // Variable contador - periodos del mcm de los LEDs
    int count = 0;

    while (true) {
        if(count % 5 == 0) {
            ledR = !ledR;
            cout << "LedR = " << count*BLINKING_PERIOD << BLINKING_UNITS << endl;
        }
        if(count % 7 == 0) {
            ledG = !ledG;
            cout << "LedG = " << count*BLINKING_PERIOD << BLINKING_UNITS << endl;
        }
        if(count % 11 == 0) {
            ledB = !ledB;
            cout << "LedB = " << count*BLINKING_PERIOD << BLINKING_UNITS << endl;
        }

        ThisThread::sleep_for(BLINKING_RATE);
        count += 1;
    }
}
