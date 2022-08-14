/**
*
* @author Alberto Estirado López
*
* Distributed under the Boost Software License, version  1.0
* See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
*
* @date 26/01/2022
*
* estiradoalberto@gmail.com
*/


#include "LevelEditorQt.hpp"
#include <QtWidgets/QApplication>

#undef main			// ESTO ES PORQUE SDL2 DEFINE EN SU CABECERA UNA MACRO LLAMADA main QUE CONVIERTE EL NOMBRE DE LA FUNCIÓN EN SDL_main...

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LevelEditorQt w;
    w.show();
    return a.exec();
}
