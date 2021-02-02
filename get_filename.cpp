#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

using std::string;
using std::vector;
using std::cout;

bool getFileNames(string folderPath, vector<string> &fileNames);

int main(void){
    string folderPath = "./data/";
    vector<string> file_names;

    getFileNames(folderPath, file_names);
    return 0;
}

bool getFileNames(string folderPath, vector<string> &file_names){
    using namespace std::filesystem;
    directory_iterator iter(folderPath), end;
    std::error_code err;

    for(; iter != end && !err; iter.increment(err)){
        const directory_entry entry = *iter;

        file_names.push_back(entry.path().string());
        cout << file_names.back().c_str() << std::endl;
    }

    if(err){
        cout << err.value() << std::endl;
        cout << err.message() << std::endl;
        return false;
    }
    
   return true;
}
