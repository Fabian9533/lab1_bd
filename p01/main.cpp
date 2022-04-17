
#include    "CFixedRecord.hpp"

int main(int argc , char** argv){
    std::string x = "datos1.txt";
    FixedRecord fr (x);

    Alumno alumno={"0008", "Fabian", "Alvarado Vargas", "CS"};
    fr.add(alumno);
   
    return 0;
}