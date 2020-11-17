#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    float masa_ciala, wzrost, BMI;
    cout << "Podaj swoja mase ciala w [kg]: ";
    cin >> masa_ciala;//wczytywanie masy w kg
    cout << "Podaj swoj wzrost w [m]: ";
    cin >> wzrost;//wczytywanie wzrostu w m
    
    BMI = (masa_ciala)/(wzrost * wzrost);//obliczenie
    
    cout << "Twoj BMI wynosi " << BMI << endl;
    
    
    if (BMI < 16 && BMI > 0)
        cout << "wyglodzenie" << endl;
    else if (BMI >= 16 && BMI < 17)
        cout << "wychudzenie" << endl;
    else if (BMI >= 17 && BMI < 18.5)
        cout << "niedowaga" << endl;
    else if (BMI >= 18.5 && BMI < 25)
        cout << "wartosc prawidlowa" << endl;
    else if (BMI >= 25 && BMI < 30)
        cout << "nadwaga" << endl;
    else if (BMI >= 30 && BMI < 35)
        cout << "I stopien otylosci" << endl;
    else if (BMI >= 35 && BMI < 40)
        cout << "II stopien otylosci" << endl;
    else if (BMI >= 40)
        cout << "otylosc skrajna" << endl;
    else
        cout << "Zle podane dane wejsciowe" << endl;
    
    system("pause");

    return 0;
}
