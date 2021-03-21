#include <iostream>
#include <string>

using std::string, std::cout, std::cin, std::endl;

int main(){
    char op;
    cout << "Digite a questão desejada (entre a~e) ou x para sair." << endl;
    while(cin >> op){
        switch(op){          
            case 'a':{
                for (int i=1; i<6; i++){
                    string a(i,'*');
                    cout << a << endl;
                }
                cout << "----------" << endl;
                break;
            }
            
            case 'b':{
                for (int i=5; i>0; i--){
                    string a(i,'*');
                    cout << a << endl;                  
                }
                cout << "----------" << endl;
                break;
            }
            
            case 'c':{
                for (int i=5; i>0; i--){
                    string a(i,'*'), s((5-i),' ');
                    cout << (s + a) << endl;
                }
                cout << "----------" << endl;
                break;
            }

            case 'd':{
                for (int i=1; i<6; i++){
                    string a(i,'*'), s((5-i),' ');
                    cout << (s + a) << endl;
                }
                cout << "----------" << endl;
                break;
            }

            case 'e':{
                int c = 2, sp=3;
                for (int i=1; i<6 && i>0; i+=c){
                    string a(i,'*'), s(c<0?++sp:--sp,' ');
                    cout << (s + a) << endl;
                    if (i==5){c = -2;}
                    
                }
                cout << "----------" << endl;
                break;
            }

            case 'x':
                return 0;
        }
    }

    return 0;
}