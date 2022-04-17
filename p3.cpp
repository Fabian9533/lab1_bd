#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

struct Alumno
{
    string Nombre;
    string Apellidos;
    string Carrera;
    float mensualidad;

};

class VariableRecord
{
private:
    string file_name;
public:
    VariableRecord(string name){
        file_name=name;
    }

    void load();
    void add(Alumno alumno);
    Alumno readRecord(int pos);
};

Alumno VariableRecord::readRecord(int pos){
    ifstream file(file_name);
    Alumno alumno;
    int temp1 = 0;
    string reg;
    while(getline(file,reg) && !file.eof()){
        ++temp1;
        stringstream  separator(reg);
        string campo;
        if(temp1 == pos) {
            temp1=0;
            while(getline(separator,campo,'|')){
                switch(temp1) 
                {
                    case 0:
                        alumno.Nombre = campo;
                        temp1++;
                    break;
                    case 1:
                        alumno.Apellidos = campo;
                        temp1++;
                    break;
                    case 2:
                     alumno.Carrera = campo;
                        temp1++;
                    default: 
                        alumno.mensualidad = atof(campo.c_str());
                }
                  
            }
            break;
        }
    }
    file.close();
    return alumno;   
}

 
void VariableRecord::add(Alumno alumno){
    ofstream archivo(file_name, ios::app | ios::binary);
    string temp;
    archivo << alumno.Nombre;
    archivo << '|';
    archivo << alumno.Apellidos;
    archivo << '|';
    archivo << alumno.Carrera;
    archivo << '|';
    archivo << alumno.mensualidad;
    archivo <<'\n';
    archivo.close();
}


void VariableRecord::load(){
    vector<Alumno> alumnos;
    ifstream file(file_name);
    string registro;
    int temp;
    
    while(getline(file,registro) && !file.eof()){
        string temp1;
        stringstream  separator(registro);
        temp=0;
        Alumno alumno;
        while(getline(separator,temp1,'|')){
            //
            switch(temp) 
            {
                case 0: 
                    alumno.Nombre=temp1;
                    ++temp;
                    break;
                case 1:
                    alumno.Apellidos=temp1;
                    ++temp;
                    break;
                case 2:
                    alumno.Carrera=temp1;
                    ++temp;
                    break;
                default:
                    alumno.mensualidad= atof(temp1.c_str());
                    cout<<alumno.Nombre<<" "<<alumno.Apellidos<<" "<<alumno.Carrera<<" "<<alumno.mensualidad<<endl;
                
            }
        }
    }
    file.close();

    //return alumnos;
    
}

int main(){
    
    VariableRecord ejemplo("datos2.txt");
    
}





























/*
    do{
        this->Register(file,record);
        vrecord.push_back(record);
    } while(getline(file,line));
*/





















/*
    ostream &operator << (ostream & stream, Alumno & p)
    {
        stream << p.codigo;
        stream << p.nombre;
        stream << p.apellidos;
        stream << p.carrera;
        stream << "\n";
        stream << flush;
        return stream;
    }

    istream &operator >> (istream & stream, Alumno & p)
    {
        stream.get(p.codigo,5);
        stream.get(p.nombre,11);
        stream.get(p.apellidos,20);
        stream.get(p.carrera,15);
        stream.get();
        return stream;

    }


        size_t sizeBytes(){
        size_t size=0;
        size+=sizeof(mensualidad);
        size+=Nombre.length()*sizeof(char);
        size+=Apellidos.length()*sizeof(char);
        size+=Carrera.length()*sizeof(char);
        return size;
    }
*/