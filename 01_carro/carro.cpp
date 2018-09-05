// carro.cpp.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#include <iostream>
#include <clocale>
#include <cstdio>
#include <sstream>


using namespace std;
struct Car{ 
	float lim_tank;
	float kilometragem;
	int lim_passageiros;
	float tank_atual;
	int pas_atual;
		
	Car(int pas_atual = 0, float tank_atual = 0, float Kilometragem = 0,int lim_passageiros = 2, int lim_tank = 10){
		this->pas_atual = pas_atual;
		this->tank_atual = tank_atual;
		this->kilometragem = Kilometragem;
        this->lim_passageiros = lim_passageiros;
        this->lim_tank = lim_tank;
	}

	string toString() {
		stringstream saida;
		saida << "pass: " << pas_atual << "fuel: " << tank_atual << "Kilometragem: " << kilometragem; 
		return saida.str();
	}


	bool toboard() {
		if (this->pas_atual >= this->lim_passageiros) {
			cout << "  fail: limite de pessoas atingido querida";
            return false;
		}
        this->pas_atual += 1;
		return true;
	}

	bool land() {
		if (this->pas_atual == 0){
			cout << "  Fail: ninguém no carro";
			return false;
		}
		else
		{
			this->pas_atual -= 1;
			return true;
		}
	}
	void fuel( float qtgasolina) {
		this->tank_atual += qtgasolina ;
		
		if(this->tank_atual > this->lim_tank) {
			this->tank_atual = this->lim_tank;
		}
	}

	bool drive(float kilometragem){
		if (this->pas_atual == 0)
			puts("  fail: do not have passager in the car!");
		
		else if (this->tank_atual == 0)
			puts("  fail: you need fuel!");

		else if ((this->tank_atual) < (kilometragem / 10))
			puts("  fail: fuel not to endure the travel");
		else{
			this->tank_atual = tank_atual - kilometragem / 1;
			this->kilometragem = this->kilometragem + kilometragem;
			return true;
		}
		return false;
	}

};

int main() {

	setlocale(LC_ALL, "Portuguese");

	string op;
	Car Carro;
	cout << "Bem vindo ao painel de controle do seu carro\n";
	cout << "o que vc deseja fazer?  ";
	while (true) {
		cin >> op;
		
		if (op == "fim") break;
		if (op == "help") {
			cout << "  in; out; show; fuel; drive; \n";
		}
		else if (op == " in") {
			if (Carro.toboard())
				puts("  done");
		}
		else if (op == "out") {
			if (Carro.land())
				puts("  done");
		}
		else if (op == "show") {
			cout << Carro.toString() << endl;
		}
		else if (op == "drive") {

		}
	}

	return 0;

}
	

