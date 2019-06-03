#include<iostream>
#include<fstream>

// std::ostream& operator << (std::ostream& out, int a){
//     return out;
// }


void writeToFile(){

    std::ofstream output("out.txt", std::ios::app);

    // output.open("out.txt");

    output << "some random text";

    output.close();
}


void readFromFile() {
    std::ifstream input("in.txt");
    // std::ofstream output("out.txt", std::ios::app);


    // std::ifstream input_alt;
    // input_alt.open("in.txt", std::ios::in);

    while(!input.eof()){
        char temp;
        if (input >> temp) {
            std::cout << temp;
        }
    }

    input.close();
}





void readFromFile(const char* filename) {
    std::ifstream inputStream(filename, std::ios::binary);
    int extractedData;
    while(inputStream.read((char*)& extractedData, sizeof(int))){
        std::cout<<extractedData<<std::endl;
    }
    inputStream.close();
}

void writeToBinaryFile(const char* filename){
    std::ofstream outputStream(filename, std::ios::binary);
    //outpuStream.open(filename, ios::binary)

    for(int i=0;i<10;i++){
        outputStream.write((const char*)& i, sizeof(int));
    }
    outputStream.close();
}


int main() {
    // writeToFile();
    readFromFile();
}