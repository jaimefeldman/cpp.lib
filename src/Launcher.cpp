/******************************************************************************
* File:             Launcher.cpp
*
* Author:           Jaime Andrés Feldman B.  
* Created:          03/15/21 
* Description:      Probando las funciones de las clases de librería
*****************************************************************************/
    
#include <iostream>

#include "clases/AnsiColors.h"
#include "clases/StringUtils.h"
#include "clases/NumberUtils.h"

#include <array>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "[ Probando AnsiColors.h ]" << endl;
    cout <<  dark_gray     << "dark_gray "     << endl;
    cout <<  red           << "red       "     << endl;
    cout <<  green         << "green     "     << endl;
    cout <<  yellow        << "yellow    "     << endl;
    cout <<  bold_red      << "blod_red  "     << endl;
    cout <<  blod_green    << "blod_green"     << endl;
    cout <<  blod_yellow   << "blod_yellow"    << endl;
    cout <<  blue          << "blue      "     << endl;
    cout <<  bold_blue     << "bold_blue "     << endl;
    cout <<  magenta       << "magenta   "     << endl;
    cout <<  bold_magenta  << "bold_magenta"   << endl;
    cout <<  cyan          << "cyan      "     << endl;
    cout <<  bold_cyana    << "bold_cyana"     << endl;
    cout <<  gray          << "gray      "     << endl;
    cout <<  no_color      << "no_color"       << endl;

    cout << endl << "[ Probando StringUtils.h ] " << endl;

    StringUtils strUtil;
    array<string, 5> nombres = {"JaIME", "RiCarDO", "ToMaCiTo", "MarTINitA", "CuCAtO"};
    cout << endl << "- Elementos originales del arreglo - " << endl;
    for (auto const& nombre : nombres) {
        cout << nombre << endl;
    }
    cout << endl << "- StringUtils lower_case - " << endl;
    for (auto const &nombre : nombres) {
        cout << strUtil.to_lower(nombre) << endl;
    }
    cout << endl << "- StringUtils upper_case - " << endl;
    for (auto const &nombre : nombres) {
        cout << strUtil.to_upper(nombre) << endl;
    }
    cout << endl << "- Capitalizando - " << endl;
    for (auto const &nombre : nombres) {
       cout << strUtil.capitalize(nombre) << endl; 
    }
    
    cout << endl << "[ Probando la función isNumber ]" << endl;
    // Progando funcion si es numero o no.
    string entrada;
    cout << "Detectando si la entrada es número:";
    cin  >> entrada;
    cout << "es numero: " << (strUtil.isNumber(entrada) ? "Si" : "No") << endl;
    
    // Dividiendo un string por espacios dentro de un vector.
    vector<string> splitedVector = strUtil.split("hola, esto es una prueba de divicion de strings", ' ');
    cout << "vector size: " << splitedVector.size() << endl; 
    for (auto i : splitedVector) {
        cout << i << endl;
    }
    
    cout << endl << "[ iniciando NumberUtils ]" << endl;
    NumberUtils numUtil;
    numUtil.setThousandSeparator('-');
    numUtil.activeNumberFormat(true);

    cout << "probando una salida formateada:" << 100000000 << endl;
    numUtil.setThousandSeparator('.');
    cout << "cambiando el formato..." << endl;
    cout << "nuevo formato: " << 1000.45 << endl;
    cout << "dienro: $" << 34525234324 << endl;
    cout << "volviendo al formato original de cout... " << endl;
    numUtil.setThousandSeparator(false); 
    cout << "numero: " << 9393933<< endl;





return 0;
}
