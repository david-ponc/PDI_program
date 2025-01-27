#include <stdio.h>
#include <fstream>
#include <string>
#include <math.h>
#include "Imagen.h"
using namespace std;

#ifndef IMAGEN_H
#define IMAGEN_H
class Funciones
{
    public:
        void Imprimir(Imagen img);
        Imagen Cargar(string nombre);
        Imagen Copiar(Imagen img);
        void Guardar(Imagen img, string nombre);

        Imagen DegradadoID(Imagen img);
        Imagen DegradadoDI(Imagen img);
        Imagen DegradadoArAb(Imagen img);
        Imagen DegradadoAbAr(Imagen img);
        Imagen Negativo(Imagen img);
        Imagen EscalaGrises(Imagen img);
        Imagen Potencia(Imagen img, double alpha);
        Imagen AclaradoLogaritmico(Imagen img, double alpha);
        Imagen Seno(Imagen img);
        Imagen Exponencial(Imagen img, double alpha);
        Imagen Cosenoidal(Imagen img);
        Imagen Exponencial2(Imagen img, double alpha);
};

void Funciones::Imprimir(Imagen img)
{
    int c = 0;
    for (int i = 0; i < img.alto; i++)
    {
        for (int j = 0; j < img.ancho; j++)
        {
            cout << img.pixel[c].R << " " << img.pixel[c].G << " " << img.pixel[c].B << " ";
            c++;
        }
        cout << endl;
    }
}

Imagen Funciones::Cargar(string nombre)
{
    if(nombre.find(".ppm"))
    {
        ifstream archivo(nombre);
        string data;
        Imagen img;

        string header;
        getline(archivo, header);

        string comentario;
        getline(archivo, comentario);

        getline(archivo, data, ' ');
        img.ancho = atoi(data.c_str());

        getline(archivo, data);
        img.alto = atoi(data.c_str());
        
        getline(archivo, data);
        img.bpp = atoi(data.c_str());

        img.Crear(img.ancho, img.alto, img.bpp);

        for (int i = 0; i < img.alto*img.ancho; i++)
        {
            getline(archivo, data);
            img.pixel[i].R = atoi(data.c_str());
            getline(archivo, data);
            img.pixel[i].G = atoi(data.c_str());
            getline(archivo, data);
            img.pixel[i].B = atoi(data.c_str());
        }
        return img;
    }
    else
    {
        cout << "La extension del archivo debe ser .ppm, intente de nuevo" << endl;
        Imagen error;
        return error;
    }
    
}

Imagen Funciones::Copiar(Imagen img)
{
    Imagen copia;
    copia.alto = img.alto;
    copia.ancho = img.ancho;
    copia.bpp = img.bpp;
    copia.Crear(copia.ancho, copia.alto, copia.bpp);

    int c = 0;
    for (int i = 0; i < img.alto; i++)
    {
        for (int j = 0; j < img.ancho; j++)
        {
            copia.pixel[c].R = img.pixel[c].R;
            copia.pixel[c].G = img.pixel[c].G;
            copia.pixel[c].B = img.pixel[c].B;
            c++;
        }
    }
    return copia;
}

void Funciones::Guardar(Imagen img, string nombre)
{
    if(nombre.find(".ppm"))
    {
        ofstream archivo(nombre);
        archivo << "P3" << endl;
        archivo << "#" << endl;
        archivo << img.ancho << " " << img.alto << endl;
        archivo << img.bpp << endl;

        int c = 0;
        for (int i = 0; i < img.alto; i++)
        {
            for (int j = 0; j < img.ancho; j++)
            {   
                archivo << img.pixel[c].R << endl;
                archivo << img.pixel[c].G << endl;
                archivo << img.pixel[c].B << endl;
                c++;
            }
            // c = 0;
        }
    }else
    {
        cout << "extension invalida para guardar la imagen" << endl;
    }
    
}

Imagen Funciones::DegradadoID(Imagen img)
{
    float proporcion = float(img.bpp) / (float)img.ancho;
    int c = 0, in = 0;
    for (int i = 0; i < img.alto; i++)
    {
        for (int j = 0; j < img.ancho; j++)
        {   
            if((c+img.pixel[in].R) * proporcion > 255)
                img.pixel[in].R = 255;
            else
                img.pixel[in].R = (c+img.pixel[in].R) * proporcion;
            
            if((c+img.pixel[in].G) * proporcion > 255)
                img.pixel[in].G = 255;
            else
                img.pixel[in].G = (c+img.pixel[in].G) * proporcion;
            
            if((c+img.pixel[in].B) * proporcion > 255)
                img.pixel[in].B = 255;
            else
                img.pixel[in].B = (c+img.pixel[in].B) * proporcion;
            c++;
            in++;
        }
        c = 0;
    }
    return img;
}

Imagen Funciones::DegradadoDI(Imagen img)
{
    float proporcion = float(img.bpp) / (float)img.ancho;
    int c = img.ancho, in = 0;
    for (int i = 0; i < img.alto; i++)
    {
        for (int j = 0; j < img.ancho; j++)
        {
            if((c+img.pixel[in].R)*proporcion > 255)
                img.pixel[in].R = 255;
            else
                img.pixel[in].R = (c+img.pixel[in].R)*proporcion;
            
            if((c+img.pixel[in].G)*proporcion > 255)
                img.pixel[in].G = 255;
            else
                img.pixel[in].G = (c+img.pixel[in].G)*proporcion;
            
            if((c+img.pixel[in].B)*proporcion > 255)
                img.pixel[in].B = 255;
            else
                img.pixel[in].B = (c+img.pixel[in].B)*proporcion;
            in++;
            c--;
        }
        c = img.ancho;
    }
    return img;
}

Imagen Funciones::DegradadoArAb(Imagen img)
{
    float proporcion = float(img.bpp) / (float)img.alto;
    int c = 0, in = 0;
    for (int i = 0; i < img.alto; i++)
    {
        for (int j = 0; j < img.ancho; j++)
        {
            if((c+img.pixel[in].R)*proporcion > 255)
                img.pixel[in].R = 255;
            else
                img.pixel[in].R = (c+img.pixel[in].R)*proporcion;
            if((c+img.pixel[in].G)*proporcion > 255)
                img.pixel[in].G = 255;
            else
                img.pixel[in].G = (c+img.pixel[in].G)*proporcion;
            if((c+img.pixel[in].B)*proporcion > 255)
                img.pixel[in].B = 255;
            else
                img.pixel[in].B = (c+img.pixel[in].B)*proporcion;
            in++;
        }
        c++;
    }
    return img;
}

Imagen Funciones::DegradadoAbAr(Imagen img)
{
    float proporcion = float(img.bpp) / (float)img.alto;
    int c = img.alto, in = 0;
    for (int i = 0; i < img.alto; i++)
    {
        c--;
        for (int j = 0; j < img.ancho; j++)
        {
            if((c+img.pixel[in].R)*proporcion > 255)
                img.pixel[in].R = 255;
            else
                img.pixel[in].R = (c+img.pixel[in].R)*proporcion;
            
            if((c+img.pixel[in].G)*proporcion > 255)
                img.pixel[in].G = 255;
            else
                img.pixel[in].G = (c+img.pixel[in].G)*proporcion;
            
            if((c+img.pixel[in].B)*proporcion > 255)
                img.pixel[in].B = 255;
            else
                img.pixel[in].B = (c+img.pixel[in].B)*proporcion;
            in++;
        }
    }
    return img;
}

Imagen Funciones::Negativo(Imagen img)
{
    float proporcion = float(img.bpp) / (float)img.ancho;
    int in = 0;
    for (int i = 0; i < img.alto; i++)
    {
        for (int j = 0; j < img.ancho; j++)
        {
            img.pixel[in].R = img.bpp - img.pixel[in].R;
            img.pixel[in].G = img.bpp - img.pixel[in].G;
            img.pixel[in].B = img.bpp - img.pixel[in].B;
            in++;
        }
    }
    return img;
}

Imagen Funciones::EscalaGrises(Imagen img)
{
    float proporcion = float(img.bpp) / (float)img.ancho;
    int in = 0, gris;
    for (int i = 0; i < img.alto; i++)
    {
        for (int j = 0; j < img.ancho; j++)
        {
            gris = (img.pixel[in].R + img.pixel[in].G + img.pixel[in].B) / 3;
            img.pixel[in].R = gris;
            img.pixel[in].G = gris;
            img.pixel[in].B = gris;
            in++;
        }
    }
    return img;
}

Imagen Funciones::Potencia(Imagen img, double alpha)
{
    float proporcion = float(img.bpp) / (float)img.ancho;
    int in = 0, gris;
    for (int i = 0; i < img.alto; i++)
    {
        for (int j = 0; j < img.ancho; j++)
        {
            img.pixel[in].R = img.bpp * (pow(((double)img.pixel[in].R/img.bpp ), alpha));
            img.pixel[in].G = img.bpp * (pow(((double)img.pixel[in].G/img.bpp ), alpha));
            img.pixel[in].B = img.bpp * (pow(((double)img.pixel[in].B/img.bpp ), alpha));
            in++;
        }
    }
    return img;
}

// lampda / log(Alfa*Lampda + 1) * log(alfa*z+1)
Imagen Funciones::AclaradoLogaritmico(Imagen img,double alpha) {
    int in = 0;
    for (int i = 0; i < img.alto; i++)
    {
        for (int j = 0; j < img.ancho; j++)
        {
            img.pixel[in].R = log(alpha * (img.pixel[in].R + 1)) * (img.bpp / log(alpha*(img.bpp + 1)));
            img.pixel[in].G = log(alpha * (img.pixel[in].G + 1)) * (img.bpp / log(alpha*(img.bpp + 1)));
            img.pixel[in].B = log(alpha * (img.pixel[in].B + 1)) * (img.bpp / log(alpha*(img.bpp + 1)));
            in++;
        }
    }
    return img;
}

// lampda * sin((pi*x)/(2*lampda))
Imagen Funciones::Seno(Imagen img) {
    int in = 0;
    for (int i = 0; i < img.alto; i++)
    {
        for (int j = 0; j < img.ancho; j++)
        {
            img.pixel[in].R = img.bpp*sin((3.141592*img.pixel[in].R)/(2*img.bpp));
            img.pixel[in].G = img.bpp*sin((3.141592*img.pixel[in].G)/(2*img.bpp));
            img.pixel[in].B = img.bpp*sin((3.141592*img.pixel[in].B)/(2*img.bpp));
            in++;
        }
    }
    return img;
}
// Aclarado exponencial
Imagen Funciones::Exponencial(Imagen img, double alpha) {
    int in = 0;
    for (int i = 0; i < img.alto; i++)
    {
        for (int j = 0; j < img.ancho; j++)
        {
            img.pixel[in].R = ((img.bpp)/(1 - exp(-1 * alpha))) * (1 - exp((-1 * alpha * img.pixel[in].R)/img.bpp));
            img.pixel[in].G = ((img.bpp)/(1 - exp(-1 * alpha))) * (1 - exp((-1 * alpha * img.pixel[in].G)/img.bpp));
            img.pixel[in].B = ((img.bpp)/(1 - exp(-1 * alpha))) * (1 - exp((-1 * alpha * img.pixel[in].B)/img.bpp));
            in++;
        }
    }
    return img;
}
// Oscurecimiento cosenoidal
Imagen Funciones::Cosenoidal(Imagen img) {
    int in = 0;
    for (int i = 0; i < img.alto; i++)
    {
        for (int j = 0; j < img.ancho; j++)
        {
            img.pixel[in].R = img.bpp*(1-cos((3.141592*img.pixel[in].R)/(2*img.bpp)));
            img.pixel[in].G = img.bpp*(1-cos((3.141592*img.pixel[in].G)/(2*img.bpp)));
            img.pixel[in].B = img.bpp*(1-cos((3.141592*img.pixel[in].B)/(2*img.bpp)));
            in++;
        }
    }
    return img;

}
// Oscurencimiento exponencial
Imagen Funciones::Exponencial2(Imagen img, double alpha) {
    int in = 0;
    for (int i = 0; i < img.alto; i++)
    {
        for (int j = 0; j < img.ancho; j++)
        {
            img.pixel[in].R = (img.bpp/(exp(alpha)-1))*(exp((alpha*img.pixel[in].R)/img.bpp)-1);
            img.pixel[in].G = (img.bpp/(exp(alpha)-1))*(exp((alpha*img.pixel[in].G)/img.bpp)-1);
            img.pixel[in].B = (img.bpp/(exp(alpha)-1))*(exp((alpha*img.pixel[in].B)/img.bpp)-1);
            in++;
        }
    }
    return img;
}
#endif