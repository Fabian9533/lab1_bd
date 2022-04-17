#include    <iostream>
#include    <cstdlib>
#include    <string>
#include    <vector>
#include    <fstream>
#include    <sys/types.h>
#include    <sys/stat.h>
#include    <fcntl.h>
using namespace std;

struct Alumno
{
    char codigo [5];
    char nombre [11];
    char apellidos [20];
    char carrera [15];
};

char* complete (char buffer [],int size){
    string temp = buffer;
    for(int i=0;i<size;i++){
        buffer[i] = (i<temp.size())? temp[i]:' ';
    }
    buffer[size-1] = '\0';

    return buffer;
}

ostream & operator << (ostream & stream, Alumno & p)
{
    stream << complete(p.codigo,5);
    stream << " ";
    stream << complete(p.nombre,11);
    stream << " ";
    stream << complete(p.apellidos,20);
    stream << " ";
    stream << complete(p.carrera,15);
    stream << " ";
    stream << "\n";
    stream << flush;
    return stream;
}

istream & operator >> (istream & stream, Alumno & p)
{
    stream.get(p.codigo,5);
    stream.get(p.nombre,11);
    stream.get(p.apellidos,20);
    stream.get(p.carrera,15);
    stream.get();
    return stream;

}
