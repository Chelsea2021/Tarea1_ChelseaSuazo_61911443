/*Cree una aplicación de calculadora del BMI que lea el peso del usuario en libras y la altura en pulgadas (0, 
si lo prefiere, el peso del usuario en kilogramos y la altura en metros), para que luego calcule y muestre el 
índice de masa corporal del usuario.
Las fórmulas para calcular el BMI (índice de masa corporal) son:
BMI =
(pesoEnLibras ∗ 703)/
(𝑎𝑙𝑡𝑢𝑟𝑎𝐸𝑛𝑃𝑢𝑙𝑔𝑎𝑑𝑎𝑠 ∗ 𝑎𝑙𝑡𝑢𝑟𝑎𝐸𝑛𝑃𝑢𝑙𝑔𝑎𝑑𝑎𝑠)
ó
BMI =
pesoEnKilogramos/
(𝑎𝑙𝑡𝑢𝑟𝑎𝐸𝑛𝑀𝑒𝑡𝑟𝑜𝑠 ∗ 𝑎𝑙𝑡𝑢𝑟𝑎𝐸𝑛𝑀𝑒𝑡𝑟𝑜s)
La aplicación debe mostrar además la siguiente informacion del Departamento de Salud y Servicios 
Humanos/Instituto Nacional de Salud para que el usuario pueda evaluar su BMI:
VALORES DE BMI
Bajo peso: menos de 18.5
Normal: entre 18.5 y 24.9
Sobrepeso entre 25 y 29.9
Obeso: 30 o mas
*/

#include <stdio.h>
#include <iostream>

using namespace std;

//BMI = peso / altura*altura
float pedirDato(string tipoDato)
{ //"peso","altura" 
float dato;

do{
    cout << "Dame el valor " << tipoDato << " :\n";
    cin >> dato;
    if(dato<=0){
        cout << "el valor " << tipoDato << " no es valido\n";
    }
} while (dato <= 0);

return dato;

}

float calculaBMI(float peso, float altura){
    //BMI = peso / altura*altura
    float bmi;
    bmi = 0;

    bmi = peso / (altura * altura);

    return bmi;
}

void clasificaBMI(float bmi){
    if(bmi<18.5){ 
        cout << "Bajo peso";
    } else {
        if(bmi>=18.5 && bmi<=24.9){
            cout << "Normal";
        } else{
            if(bmi>=25 && bmi<=29.9){
                cout << "Sobrepeso";
            } else {
                if(bmi>=30){
                    cout << "Obeso";
                }
            }
        }
    }
}

int main () {

    float peso;
    float altura;
    float bmi;
    int continuar;

    continuar = 0;

    do{
        peso = pedirDato("peso");
        altura = pedirDato("altura");
        cout << "el peso es " << peso << " y la altura es " << altura << "\n";
        bmi = calculaBMI(peso, altura);
        cout << "El BMI es de " << bmi << "\n";
            clasificaBMI(bmi);

            cout << "\nDesea repetir el programa? (1-Si, 0-No)\n ";
            cin >> continuar;
    } while (continuar != 0);

    return 0;
}