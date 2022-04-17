
#include    "CFixedRecord.hpp"

int main(int argc , char** argv){
    std::string x = "datos.dat";

    FixedRecord fr ( x );
    vector<Alumno> aea = fr.load();
    
    return 0;
}