#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Cliente{
    bool existe;
    string id;
    string fone;
    Cliente(string id = "fulano", string fone = "0000", bool existe = true){
        this->existe = existe;
        this->id = id;
        this->fone = fone;
    }
    string toString(){
        stringstream ss;
        if(!existe)
            ss << "-";
        else
            ss << this->id << ":" << this->fone;
        return ss.str();
    }
    
};

struct Sala{
    vector<Cliente> cadeiras;

    Sala(int qtd = 0){
        for(int i = 0; i < qtd; i++)
            cadeiras.push_back(Cliente("", "", false));
    }

    bool reservar(Cliente cliente, int indCadeira){
        
    }

    string toString(){
        stringstream ss;
        ss << "[ ";
        for(Cliente cliente : cadeiras)
            ss << cliente.toString() << " ";
        ss << "]";
        return ss.str();
    }
};

int main(){
    Sala sala;
    string op;
    while(true){
        cin >> op;
        if(op == "show"){
            cout << sala.toString() << endl;
        }else if(op == "init"){
            int qtd;
            cin >> qtd;
            sala = Sala(qtd);
            cout << "sala criada com " << qtd << " cadeiras" << endl;
        }
    }
}