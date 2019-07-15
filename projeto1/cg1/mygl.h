#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include <vector>
#include <math.h>

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************
void putPixel(int x, int y, std::vector<int> & cor) {
    int i;

    for(i = 0; i < 4; i++){
        FBptr[x*4+i + y*4*IMAGE_WIDTH] = cor.at(i);
    }

}

void drawLine(int x0, int y0, int x, int y){
    int line;
    int b, d;

    b = y - ((y - y0)/(x - x0))*x;

   line = ((y - y0)/(x - x0))*x + b - y;


}









#endif // _MYGL_H_

