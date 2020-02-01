#include <fstream>
#include <iostream>
#include <string>
// #include "Imagen.h"
#include "Funciones.h"
using namespace std;

Imagen CrearCargar()
{
    int r = -1;
    Funciones f;
    cout << "(1) Trabajar sobre una imagen existente" << endl;
    cout << "(2) Trabajar sobre una imagen nueva" << endl;
    cout << "Accion: "; cin >> r;
    switch (r)
    {
    case 1:
        {
            string nombre; Imagen img;
            cout << "------------------------------" << endl << "Carga de imagen" << endl << "Nombre de la imagen: ";
            cin >> nombre;
            try
            {
                img = f.Cargar(nombre);
            }
            catch(exception& e)
            {
                cerr << "Error al cargar la imagen" << e.what() << endl;
            }
            cout << endl << "Imagen cargarda!" << endl << "------------------------------" << endl;

            return img;  
        }
        break;

    case 2:
        {
            Imagen img;
            int alto, ancho, bpp;
            cout << "------------------------------" << endl << "Creacion de imagen" << endl;
            cout << "Ancho de la imagen: "; cin >> ancho ;
            cout << "Alto de la imagen: "; cin >> alto ;
            cout << "Profundidad de bits de la imagen: "; cin >> bpp ;

            img.Crear(ancho, alto, bpp);

            return img;
        }
        break;
    
    default:
        cout << "Opcion invalida" << endl;
        Imagen error;
        return error;
        break;
    }
}

int main()
{
    int respuesta = -1, resEdicion = -1;
    string nombre;
    Funciones f;
    Imagen img;

    // Imagen img = f.Cargar(nombre);
    // f.Imprimir(img);
    cout << "******** Programa de edicion de imagenes ********" << endl;
    do
    {
        cout << "Opciones de edicion:" << endl;
        cout << "(1) Degradado (Izquierda a derecha)" << endl;
        cout << "(2) Degradado (Derecha a izquierda)" << endl;
        cout << "(3) Degradado (Arriba a bajo)" << endl;
        cout << "(4) Degradado (Abajo a arriba)" << endl;
        cout << "(5) Imagen negativa" << endl;
        cout << "(6) Escala de grises" << endl;
        cout << "(7) Salir del programa" << endl;
        cout << "Accion: "; cin >> respuesta;
        switch (respuesta)
        {
        case 1:
            {
                int ans = -1;
                string n;
                Imagen img = CrearCargar();
                Imagen copia = f.Copiar(img);
                f.DegradadoID(copia);
                cout << "------------------------------" << endl << "Imagen generada correctamente" << endl;
                // f.Imprimir(copia);
                cout << "Desea guardar la nueva imagen? (1 = si, 0 = no): "; cin >> ans;
                if(ans == 1)
                {
                    cout << "Nombre del nuevo archivo: "; cin >> n;
                    f.Guardar(copia, n);
                }
            }
            break;
        case 2:
            {
                int ans = -1;
                string n;
                Imagen img = CrearCargar();
                Imagen copia = f.Copiar(img);
                f.DegradadoDI(copia);
                cout << "------------------------------" << endl << "Imagen generada correctamente" << endl;
                // f.Imprimir(copia);
                cout << "Desea guardar la nueva imagen? (1 = si, 0 = no): "; cin >> ans;
                if(ans == 1)
                {
                    cout << "Nombre del nuevo archivo: "; cin >> n;
                    f.Guardar(copia, n);
                }
            }
            break;
        case 3:
            {
                int ans = -1;
                string n;
                Imagen img = CrearCargar();
                Imagen copia = f.Copiar(img);
                f.DegradadoArAb(copia);
                cout << "------------------------------" << endl << "Imagen generada correctamente" << endl;
                // f.Imprimir(copia);
                cout << "Desea guardar la nueva imagen? (1 = si, 0 = no): "; cin >> ans;
                if(ans == 1)
                {
                    cout << "Nombre del nuevo archivo: "; cin >> n;
                    f.Guardar(copia, n);
                }
            }
            break;
        case 4:
            {
                int ans = -1;
                string n;
                Imagen img = CrearCargar();
                Imagen copia = f.Copiar(img);
                f.DegradadoAbAr(copia);
                cout << "------------------------------" << endl << "Imagen generada correctamente" << endl;
                // f.Imprimir(copia);
                cout << "Desea guardar la nueva imagen? (1 = si, 0 = no): "; cin >> ans;
                if(ans == 1)
                {
                    cout << "Nombre del nuevo archivo: "; cin >> n;
                    f.Guardar(copia, n);
                }
            }
            break;
        case 5:
            {
                int ans = -1;
                string n;
                Imagen img = CrearCargar();
                Imagen copia = f.Copiar(img);
                f.Negativo(copia);
                cout << "------------------------------" << endl << "Imagen generada correctamente" << endl;
                // f.Imprimir(copia);
                cout << "Desea guardar la nueva imagen? (1 = si, 0 = no): "; cin >> ans;
                if(ans == 1)
                {
                    cout << "Nombre del nuevo archivo: "; cin >> n;
                    f.Guardar(copia, n);
                }
            }
            break;
        case 6:
            {
                int ans = -1;
                string n;
                Imagen img = CrearCargar();
                Imagen copia = f.Copiar(img);
                // f.EscalaGrises(copia);
                f.Potencia(copia);
                cout << "------------------------------" << endl << "Imagen generada correctamente" << endl;
                // f.Imprimir(copia);
                cout << "Desea guardar la nueva imagen? (1 = si, 0 = no): "; cin >> ans;
                if(ans == 1)
                {
                    cout << "Nombre del nuevo archivo: "; cin >> n;
                    f.Guardar(copia, n);
                }
            }
            break;
        case 7:
            cout << "Programa finalizado :)";
            return 0;
            break;
        default:
            cout << "opcion invalida, intente de nuevo..." << endl << "---------------------------------------" << endl;
            break;
        }
    } while (respuesta != 0);
    

    return 0;
}