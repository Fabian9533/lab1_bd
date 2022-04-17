
#include "SAlumno.hpp"

class FixedRecord 
{
    private:
    std::string filename ;

    public:
    FixedRecord (std::string &filename_) { filename = filename_; };
    ~FixedRecord(){};

    void add(Alumno record){
        std::ofstream file;
        file.open(filename,ios::app);
        string line ;
        file<<record;
        file.close();        
    };
    
    std::vector<Alumno> load()
    {
        std::vector<Alumno> vrecord;
        std::ifstream file;
        file.open(filename);
        Alumno record;
        string line ;
        do{
            file>>record;
            vrecord.push_back(record);
        } while(getline(file,line));
        
        file.close();

        return vrecord;
    };


    Alumno readRecord(int pos){
        std::ifstream file;
        file.open(filename);

        Alumno record;

        if(pos==0){
            file>>record;
            file.close();
            return record;
        }
        pos--;
        
        file.seekg(pos * sizeof(record), ios::beg);
        string line;
        getline(file,line);
        file>>record;
        file.close();
        
        return record;
    };

};
