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

float distancia(int x0, int y0, int x, int y){ //Calcula a distancia entre dois pontos.
    float r;

    r = sqrt(((x - x0)*(x - x0))+((y - y0)*(y - y0)));

    return r;
}

void colorInterpolation(std::vector<int>& RGBAi, std::vector<int>& RGBAf, std::vector<int>* corI, std::vector<int>* corF, std::vector<int>& RGBA, float distP, float distR, float p) {


    for(int i = 0; i < 4; i++){
        if(RGBAi.at(i)){
            RGBA.at(i) = corI->at(i)*p;
        }
    }

    for(int i = 0; i < 4; i++){
        if(RGBAf.at(i)){
            RGBA.at(i) = corF->at(i)*(1-p);
        }
    }


}



void drawLine(int x0, int y0, int x1, int y1, std::vector<int> & corI, std::vector<int> & corF){

    //Equacão geral da reta
    //y = mx + b

    int dx = x1 - x0;
    int dy = y1 - y0;
    float distPonto;
    float distReta = distancia(x0, y0, x1, y1);
    float p;
    int d;
    int aux1;
    int aux2;
    int inc;

    std::vector<int> RGBAi;
    RGBAi.push_back(0);
	RGBAi.push_back(0);
	RGBAi.push_back(0);
	RGBAi.push_back(0);

	std::vector<int> RGBAf;
    RGBAf.push_back(0);
	RGBAf.push_back(0);
	RGBAf.push_back(0);
	RGBAf.push_back(0);

	std::vector<int> RGBA;
    RGBA.push_back(0);
	RGBA.push_back(0);
	RGBA.push_back(0);
	RGBA.push_back(0);


    for(int i = 0; i < 4; i++){
        if(corI.at(i) == 255){
            RGBAi.at(i) = 1;
            RGBA.at(i) = 255;
        }
    }

    for(int i = 0; i < 4; i++){
        if(corF.at(i) == 255){
            RGBAf.at(i) = 1;
        }
    }


    if(dx<0) // caso ponto final < ponto inicial
    {
        drawLine(x1, y1, x0, y0,corF,corI);
        return;
    }
    if(dy<0)
        inc = -1;
    else
        inc = 1;

    int incE, incNE;



    putPixel(x0, y0,corI);
    if(dx >= inc*dy){
        if(dy < 0){
            d = 2*dy+dx;
            while(x0<x1){
                if(d<0){
                    d += 2*(dy+dx);
                    x0++;
                    y0--;
                }
                else{
                    d+=2*dy;
                    x0++;
                }
            distPonto = distancia(x0, y0, x1, y1);
            p = distPonto/distReta;
            colorInterpolation(RGBAi, RGBAf, &corI, &corF, RGBA, distPonto, distReta, p);
            putPixel(x0, y0, RGBA);

            }
        }
        else{
            d=2*dy-dx;
            while(x0 < x1){
                if(d<0){
                    d+=2*dy;
                    x0++;
                }
                else{
                    d+=2*(dy-dx);
                    x0++;
                    y0++;
                }
            distPonto = distancia(x0, y0, x1, y1);
            p = distPonto/distReta;
            colorInterpolation(RGBAi, RGBAf, &corI, &corF, RGBA, distPonto, distReta, p);
            putPixel(x0, y0, RGBA);
            }
        }
    }
    else{
        if(dy < 0){
            d=dy+2*dx;
            while(y0 > y1){
                if(d < 0){
                    d += 2*dx;
                    y0--;
                }
                else{
                    d+=2*(dy+dx);
                    x0++;
                    y0--;
                }
            distPonto = distancia(x0, y0, x1, y1);
            p = distPonto/distReta;
            colorInterpolation(RGBAi, RGBAf, &corI, &corF, RGBA, distPonto, distReta, p);
            putPixel(x0, y0, RGBA);

            }
        }
        else{
            d=dy-2*dx;
            while(y0 < y1){
                if(d < 0){
                    d+=2*(dy-dx);
                    x0++;
                    y0++;
                }
                else{
                    d+=-2*dx;
                    y0++;
                }
                distPonto = distancia(x0, y0, x1, y1);
                p = distPonto/distReta;
                colorInterpolation(RGBAi, RGBAf, &corI, &corF, RGBA, distPonto, distReta, p);
                putPixel(x0, y0, RGBA);
                }
            }
        }

}


void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, std::vector<int> & cor1, std::vector<int> & cor2,  std::vector<int> & cor3){
    drawLine(x1, y1, x2, y2, cor1, cor2);

    drawLine(x1, y1, x3, y3, cor1, cor3);

    drawLine(x3, y3, x2, y2,cor3, cor2);

}



#endif // _MYGL_H_

