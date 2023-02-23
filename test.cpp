
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

int raw2txt(const string file_in, const int img_width, const string file_out)
{
    int cnt = 0;
    char *data = new char[4];
    ifstream r_f(file_in, ios::binary);
    ofstream w_f(file_out, ios::out);
    if (!r_f || !w_f)
        return -1;
    while (r_f >> *data)
    {
        cout << data << endl;
        w_f << abs(int(*data)) << " ";
        if ((++cnt %= img_width) == 0)
        {
            cout << cnt << endl;
            w_f << "\n";
        }
    }
    r_f.close();
    w_f.close();
    return 0;
}

int input_check(const int argc, const char *const *argv)
{
    string name;
    if (argc != 3)
    {
        cout << "*** input is invalid ! *** " << endl;
        cout << "such as: raw2txt <img_width> <img_name> " << endl;
        return -1;
    }
    name = name.insert(0, argv[2]);
    if (name.substr(name.length() - 3, name.length()) != "raw")
    {
        cout << "Your input file [ " << name << " ] is not RAW format!" << endl;
        return -1;
    }
    return 1;
}

int main(int argc, char **argv)
{
    if (input_check(argc, argv) == -1)
        return 0;
    int img_width = atoi(argv[1]);
    string img_name = argv[2];
    //for debug
    // int img_width =512;
    // string img_name = "./lena512.raw";
    stringstream text_name;
    text_name << img_name << ".txt";

    cout << "*** You Input Information ***" << endl;
    cout << "img_width:  " << img_width << endl;
    cout << "img_name :  " << img_name << endl;
    cout << text_name.str() << endl;
    if (raw2txt(img_name, img_width, text_name.str()) == -1)
    {
        cout << img_name << " read ERROR !" << endl;
    }
    return 0;
}
