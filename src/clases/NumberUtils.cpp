/**********************************************************************
*               NumberUtils implementación                            *
*               viernes, 19 de marzo de 2021 a las 17:33 hrs.         * 
*               by Jaime Andrés Feldman B.                            *
**********************************************************************/

#include "NumberUtils.h"

using namespace std;

NumberUtils::NumberUtils() {
    cout << "initializae number utils" << endl;
    cout_number_format_ptr = new custom_locale;
    cout_normal_ptr        = new no_separator;
}

NumberUtils::~NumberUtils() {
    delete cout_number_format_ptr;
    delete cout_normal_ptr;
}

void NumberUtils::setThousandSeparator(char xch) {
    cout_number_format_ptr->thous_sep = xch;
}

void NumberUtils::setDecimalSeparator(char xch) {
    cout_number_format_ptr->decimal_point = xch;
}

void NumberUtils::activeNumberFormat(bool activeFormat) {
    if(activeFormat) {
        cout.imbue(locale(cout.getloc(), cout_number_format_ptr));
        this->isFormatActivated = true;
    } else {
        cout.imbue(locale(cout.getloc(), cout_normal_ptr));
        this->isFormatActivated = false;
    }
}

