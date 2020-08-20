#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    unsigned int size_of_input = atoi(argv[1]), size_of_output = atoi(argv[2]);
    
    int feature [size_of_input];
    int weight [size_of_input][size_of_output];
    int result [size_of_output];
    
    ifstream feaFile(argv[3]);
    ifstream weightFile(argv[4]);
    
    if(feaFile.is_open()){
        for(int i = 0; i < size_of_input ; i++){
                string str;
                getline(feaFile,str);
                if(!str.compare("") || feaFile.eof()) break;
                feature[i] = stoi(str);
                cout << feature[i] << endl;
        }
        feaFile.close();
    }
    else cout << "Error : feature cannot be open" << endl;
    
    if(weightFile.is_open()){
        for(int i = 0; i < size_of_input ; i++){
            for(int j = 0; j < size_of_output; j++){
                string str;
                getline(weightFile,str);
                if(!str.compare("") || weightFile.eof()) break;
                weight[i][j] = stoi(str);
                cout << weight[i][j] << endl;
            }
        }
        feaFile.close();
    }
    else cout << "Error : feature cannot be open" << endl;
    
    for(int i = 0; i < size_of_output; i++) result[i] = 0;
    
    for(int i = 0; i < size_of_output; i++){
        for(int j = 0; j < size_of_input; j++){
            result[i] += feature[j] * weight[j][i];
            cout << feature[j] << " " << weight[j][i] << " " << endl;
        }
    }
    
    ofstream writeDUMP;
    writeDUMP.open("/Users/laurent01/Desktop/Test_Dump",ios::in|ios::app);
    if(writeDUMP.is_open()){
        for(int i = 0; i < size_of_output; i++){
            stringstream stream;
            stream << dec << result[i];
            cout << result[i] << endl;
            string result(stream.str());
            writeDUMP << result << "\n";
        }
        writeDUMP.close();
    }
    else cout << "ERROR : File is not open" << endl;

    return 0;
}
