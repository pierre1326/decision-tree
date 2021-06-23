#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>

using namespace std;

class File {
  
  public:

    /**
     * Constructor por defecto
     **/
    File();

    /**
     * Carga un archivo en la ruta dada
     * 
     * @param path  Ruta del archivo 
     * @return  Texto dentro del archivo
     **/
    string load(string path);

    /**
     * Escribe la informacion dentro del documento
     * 
     * @param path  Ruta del archivo
     * @param text  Texto a escribir
     * @return  Resultado de exito al escribir
     **/
    bool write(string path, string text);

};

#endif