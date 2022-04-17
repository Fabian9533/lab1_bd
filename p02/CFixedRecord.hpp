
#include "SAlumno.hpp"

class FixedRecord 
{
    private:
    std::string filename ;

    public:
    FixedRecord (std::string &filename_) { filename = filename_; };
    ~FixedRecord(){};
    std::vector<Alumno> load(){
        vector<Alumno> vrecord;
        Alumno record;

        ifstream file;

        file.open(filename,ios::binary);

        file.seekg(sizeof(int),ios::beg);

        while(file.read((char*) &record, sizeof(Alumno))){
                vrecord.push_back(record);
        }
        file.close();
        return vrecord;
    };

    void add(Alumno record){
        ofstream file(filename, ios::app | ios::binary);

        file.write((char*) &record, sizeof(Alumno));
        file.close();
    };


    Alumno readRecord(int pos){
        std::ifstream file(filename, ios::binary);
        
        Alumno record;
        file.seekg(pos * sizeof(Alumno), ios::beg);
        file.read((char*) &record, sizeof(Alumno));
        file.close();

        return record;
    };

};
