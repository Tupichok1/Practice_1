#include "createDirectory.h"

using json = nlohmann::json;
using namespace std;
namespace fs = std::filesystem;

void createDirectory() {
    json objJson;
    fstream fileInput("awd.json");
    fileInput >> objJson;
    fileInput.close();
    string nameOfTable = objJson["name"];
    if ( fs::exists(nameOfTable) ) {
        return;
    }
    fs::create_directory(nameOfTable);
    for ( auto& [tableName, columns] : objJson["structure"].items() ) {
        string path = nameOfTable + "/" + tableName;
        string CSVPath = path + "/" + "1.csv";
        string pk_sequence = tableName + "_pk";
        string pk_sequence_path = path + "/" + tableName + "_pk_sequence";
        fs::create_directory(path);
        ofstream csv(CSVPath);
        ofstream pkSequence(pk_sequence_path);
        for ( auto column : columns ) {
            csv << string(column) << ",";
        }
        csv << string(pk_sequence);
        pkSequence << 1;
    }
}