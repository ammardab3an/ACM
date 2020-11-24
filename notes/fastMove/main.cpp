#include<windows.h>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char * argv[]){

    string Destination(argv[0]);
    string fileName = string(argv[0]).substr(string(argv[0]).rfind('\\'), string::npos);
    int len0 = string("going" + fileName).size();
    Destination.replace(Destination.size() - len0, string::npos,
                        "done" + fileName.substr(0, fileName.size() -4));

    for(int i = 1; i < argc; i++){

        string Source = string(argv[i]);
        string nDis = Destination + Source.substr(Source.rfind('\\'), string::npos);
        int m = MoveFile(Source.c_str(), nDis.c_str());

        if(!m) {
            cout << "Error Code : " << GetLastError() << endl;
            cout << Source << endl << nDis << endl;
            cout << string(20, '-') << endl;
            system("PAUSE");
        }
        else
            cout << "Done" << endl;
    }
}
