#include "main.h"
#include <vector>




//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************

    std::vector<int> color1, color2, color3, color4;

    //Vetores que guardam as componentes RGBA de cada cor.
    //Cor vermelha
    color1.push_back(255);
	color1.push_back(0);
	color1.push_back(0);
	color1.push_back(1);
    //Cor verde
	color2.push_back(0);
	color2.push_back(255);
	color2.push_back(0);
	color2.push_back(1);
    //Cor azul
	color3.push_back(0);
	color3.push_back(0);
	color3.push_back(255);
	color3.push_back(1);
    //Cor branca
	color4.push_back(255);
	color4.push_back(255);
	color4.push_back(255);
	color4.push_back(255);







//    int a, b, c, d;
//    int x, y, z, t;
//
//    for(a = 0; a < 100; a++){
//       for(x = 0; x < 100; x++){
//            putPixel(a, x, color1);
//            x++;
//       }
//    a++;
//    }
//
//    for(b = 101; b < 200; b++){
//       for(y = 0; y < 100; y++){
//            putPixel(b, y, color2);
//            y++;
//       }
//    b++;
//    }
//
//    for(c = 201; c < 300; c++){
//       for(z = 0; z < 100; z++){
//            putPixel(c, z, color3);
//            z++;
//       }
//    c++;
//    }
//
//
//
//    for(d = 301; d < 400; d++){
//       for(t = 0; t < 100; t++){
//            putPixel(d, t, color4);
//            t++;
//       }
//    d++;
//   }

//    putPixel(50, 50, color1);
//    putPixel(60, 50, color1);
//    putPixel(70, 50, color1);
//    putPixel(80, 50, color1);
//    putPixel(90, 50, color1);
//    putPixel(250, 50, color2);
//    putPixel(260, 50, color2);
//    putPixel(270, 50, color2);
//    putPixel(280, 50, color2);
//    putPixel(290, 50, color2);
//    putPixel(50, 250, color3);
//    putPixel(60, 250, color3);
//    putPixel(70, 250, color3);
//    putPixel(80, 250, color3);
//    putPixel(90, 250, color3);
//    putPixel(250, 250, color4);
//    putPixel(260, 250, color4);
//    putPixel(270, 250, color4);
//    putPixel(280, 250, color4);
//    putPixel(290, 250, color4);


//    drawLine(0,0,500,500, color1, color3);
//
//    drawLine(500,0,0,500, color2, color3);
//
//    drawLine(250,0,251,500, color1, color3);
//
//    drawLine(0,250,500,251, color1, color3);
//
//    drawLine(0, 400, 150, 0, color1, color2);
//
//    drawLine(400, 0, 0, 150, color1, color2);
////
//    putPixel(0, 400, color3);
//    putPixel(150, 0, color3);

//    putPixel(180, 400, color3);



//
//    drawTriangle(50,50,300,300,200,400,color1, color2, color3);
}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}


