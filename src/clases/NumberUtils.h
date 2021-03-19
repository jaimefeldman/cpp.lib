/************************************************************************************************\

        NOMBRE: NumberUtils

        AUTOR:  Jaime Andrés Feldman B., (jimix)

        FECHA:  viernes, 19 de marzo de 2021 a las 17:21 hrs.

        DESCRIPCIÓN:
            Formatea la salida del cout en caso de ser numerica, le pone separador de miles 
            y en caso de usarla una coma decimal.
            es configurable con:
            - setThousandSeparator(char)
            - setDecimalSeparator(char)
            se activa o se desactiva el formato con: activeNumberFormat(bool)
            y se verifica si esta activado con : isFormatActivated() 

        LICENCIA:
        
            Copyright © 2021 Jaime Andrés Feldman B.
            
            Permission is hereby granted, free of charge, to any person obtaining
            a copy of this software and associated documentation files (the "Software"),
            to deal in the Software without restriction, including without limitation
            the rights to use, copy, modify, merge, publish, distribute, sublicense,
            and/or sell copies of the Software, and to permit persons to whom the
            Software is furnished to do so, subject to the following conditions:
            
            The above copyright notice and this permission notice shall be included
            in all copies or substantial portions of the Software.
            
            THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
            EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
            OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
            IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
            DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
            TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
            OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
            

\************************************************************************************************/

#include <locale>
#include <iostream>

using namespace std;

// Estructura para personalizar la salida de separador de miles. usa el header locale
struct custom_locale : numpunct<char> {
    char thous_sep     = '.';
    char decimal_point = ',';

    char_type do_thousands_sep() const override { return thous_sep; } // Separador de miles
    char_type do_decimal_point() const override { return ','; } // Separador decimal
    string_type do_grouping()    const override { return "\3"; }   // Dígitos entre cada separador de miles
};

struct no_separator : std::numpunct<char> {
protected:
    virtual string_type do_grouping() const
        { return "\000"; } // groups of 0 (disable)
};

class NumberUtils {
public:
    NumberUtils  ();
    ~NumberUtils (); 
    void setThousandSeparator(char);
    void setDecimalSeparator(char);
    void activeNumberFormat(bool);
private:
    custom_locale *cout_number_format_ptr;
    no_separator  *cout_normal_ptr;
    bool isFormatActivated {false};
};

