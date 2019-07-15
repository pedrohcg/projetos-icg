#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include <vector>
#include <math.h>
#include <stdio.h>

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

void putPixel(int x, int y, std::vector<int> & cor) {
    int i;

    for(i = 0; i < 4; i++){
        FBptr[x*4+i + y*4*IMAGE_WIDTH] = cor.at(i);
    }

}

void drawLine(int x0, int y0, int x, int y, std::vector<int> & cor){

    //Equacão geral da reta
    //y = mx + b

    int dx = x - x0;
    int dy = y - y0;
    int d;
    int aux1;
    int aux2;

    if((dx > 0) && (dy > 0)){
        //Primeiro quadrante
        if(abs(dx) > abs(dy)){
            d = 2*dy - dx;   printf("1");
            aux1 = 2*dy;
            aux2 = 2*(dy-dx);

            while(x0 < x){
                if(d < 0){  printf("2");
                d += aux1;
                x0++;
            }
            else{
                d += aux2;  printf("3");
                x0++;
                y0++;
            }
            putPixel(x0, y0, cor);
        }
        }
        //Segundo quadrante
        else{
            d = dy -2*dx;
            aux1 = 2*(dy-dx);
            aux2 = -2*dx;

            while(abs(y0) < abs(y)){
            if(d < 0) { printf("4");
                d += aux1;
                x0++;
                y0++;
            }
            else {
                d += aux2;  printf("5");
                y0++;
            }
            putPixel(x0, y0, cor);
            }
        }
    }

    if((dx < 0) && (dy > 0)){
        //Terceiro quadrante
        if(abs(dy) > abs(dx)){ printf("6");
           d = dy+2*dx;
           aux1 = 2*dx;
           aux2 = 2*(dy+dx);

           while(abs(y0) < abs(y)){
                if(d < 0){ printf("7");
                    d += aux2;
                    y--;
                }
                else{ printf("8");
                    d+= aux1;
                    y--;
                    x++;
                }
           putPixel(x, y, cor);
           }
        }
        else{
            //Quarto quadrante
            d = 2*dy+dx;
            aux1 = 2*(dy+dx);
            aux2 = 2*dy;

            while(abs(x) < abs(x0)){
                if(d < 0){ printf("9");
                    d += aux2;
                    x++;
                }
                else{ printf("10");
                    d += aux1;
                    x++;
                    y--;
                }
                putPixel(x, y, cor);
            }

        }
    }

        if((dx < 0) && (dy < 0)){ printf("11");
            int auxvar1;
            int auxvar2;
            auxvar1 = x0;
            auxvar2 = y0;
            x0 = y;
            y0 = x;
            x = auxvar2;
            y = auxvar1;

            drawLine(x0, y0, x, y, cor);
    }

        if((dx > 0) && (dy < 0)){ printf("12");
            int auxvar1;
            int auxvar2;
            auxvar1 = x0;
            auxvar2 = y0;
            x0 = x;
            y0 = y;
            y = auxvar2;
            x = auxvar1;


            drawLine(x0, y0, x, y, cor);
        }

        if((dx == 0) || (dy == 0)){
            if(dx == 0){

                for(int i = y0; i <= y; i++){
                    putPixel(x0, i, cor);
                }
            }
            if(dy == 0){

                for(int i = x0; i <= x; i++){
                    putPixel(i, y0, cor);
            }

        }

        }
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, std::vector<int> & cor){
    drawLine(x1,y1,x2,y2,cor);

    drawLine(x1,y1,x3,y3,cor);

    drawLine(x2,y2,x3,y3, cor);

}

#endif // _MYGL_H_

