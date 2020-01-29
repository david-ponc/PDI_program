#include <string>
#include "Pixel.h"
using namespace std;

class Imagen: public Pixel
{
    private:
        int ancho;
        int alto;
        int bpp;
        Pixel* pixel;
        string nombre;
    public:
        Imagen() { ancho = 0; alto = 0; bpp = 0;};
        ~Imagen() {};
        void Crear(int an, int al, int bp);
    friend class Funciones;
};

void Imagen::Crear(int an, int al, int bp)
{
    ancho = an;
    alto = al;
    bpp = bp;
    pixel = new Pixel[ancho*alto];
}

// void Imagen::Imprimir()
// {
//     int c = 0;
//     for (int i = 0; i < alto; i++)
//     {
//         for (int j = 0; j < ancho; j++)
//         {
//             pixel[j].R = c;
//             pixel[j].G = c;
//             pixel[j].B = c;
//             cout << pixel[j].R << " " << pixel[j].G << " " << pixel[j].B;
//             c++;
//         }
//         cout << endl;
//         c = 0;
//     }
// }

// void Imagen::Guardar(Imagen a, string nombre, string comentario)
// {
//     ofstream archivo(nombre+".ppm");
//     archivo << "P3" << endl;
//     archivo << "#"+comentario << endl;
//     archivo << a.ancho << " " << a.alto << endl;
//     archivo << a.bpp << endl;

//     int c = 0;
//     float f = float(a.bpp) / (float)a.ancho;

//     for (int i = 0; i < alto; i++)
//     {
//         for (int j = 0; j < ancho; j++)
//         {
//             a.pixel[j].R = c * f;
//             a.pixel[j].G = c * f;
//             a.pixel[j].B = c * f;
            
//             archivo << a.pixel[j].R << endl;
//             archivo << a.pixel[j].G << endl;
//             archivo << a.pixel[j].B << endl;
//             c++;
//         }
//         c = 0;
//     }
// }

// void Imagen::Editar(Imagen img, string nombre)
// {
//     ifstream archivo(nombre+".ppm");
//     string data;
//     string header;
//     getline(archivo, header);

//     string comentario;
//     getline(archivo, comentario);

//     getline(archivo, data, ' ');
//     int ancho = atoi(data.c_str());

//     getline(archivo, data);
//     int alto = atoi(data.c_str());
    
//     getline(archivo, data);
//     int bpp = atoi(data.c_str());

//     Imagen temp;
//     temp.Crear(ancho, alto, bpp);

//     for (int i = 0; i < alto; i++)
//     {
//         for (int j = 0; j < ancho; j++)
//         {
//             temp.pixel[j].R = img.pixel[j].R;
//             temp.pixel[j].G = img.pixel[j].G;
//             temp.pixel[j].B = img.pixel[j].B;
            
//         }
//     }

//     temp.Imprimir();
// }