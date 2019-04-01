#include "loto.hpp"
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>

using namespace std;
using namespace sc_core;

Module01::Module01(sc_core::sc_module_name name, int limit) :
	limit(limit)
{
	SC_THREAD(lotto_machine);
	SC_THREAD(player1);
	SC_THREAD(player2);
	SC_THREAD(player3);
	SC_THREAD(result);
	srand(time(NULL));

}

void Module01::lotto_machine()
{
	int niz[limit];
	int brojevi = rand()%39 + 1;
	for (int i = 0; i < limit; i++){
	
		int brojevi = rand()%39 + 1;
		niz[i] = brojevi;
		ints.push_back(niz[i]);
	//	std::cout <<"Niz: " << niz[i] << "\n";
	}
	wait(1, sc_core::SC_SEC);
	//std::cout << "Niz : " << niz[i] << "\n";
}

void Module01::player1()
{
	int play = rand()%2;
	if (play == 1){
	
		int niz1[limit];
		for(int j = 0; j < limit; j++){
			int brojevi1 = rand()%39 + 1;
			niz1[j] = brojevi1;
			ints1.push_back(niz1[j]);
		}

	}
}



void Module01::player2()
{
	int play1 = rand()%2;
	if (play1 == 1){	
		int niz2[limit];
		for(int j = 0; j < limit; j++){
			int brojevi2 = rand()%39 + 1;
			niz2[j] = brojevi2;
			ints2.push_back(niz2[j]);
		}
	}
}



void Module01::player3()
{
	int play2 = rand()%2;
	if (play2 == 1){
	
		int niz3[limit];
		for(int j = 0; j < limit; j++){
		int brojevi3 = rand()%39 + 1;
			niz3[j] = brojevi3;
			ints3.push_back(niz3[j]);
		}
	}
}

int maximum(int a, int b, int c)
{
	int max=(a<b)? b:a;
	return ((max<c)? c:max);
}

void Module01::result()
{
	

		int k=0;
		int l=0;
		int n=0;		
		int comb[limit];
		int comb_p1[limit];
		int comb_p2[limit];
		int comb_p3[limit];
		int pog_p1[limit];
		int pog_p2[limit];
		int pog_p3[limit];
		for(int j=0;j<limit;j++){
			comb[j] = ints.front();
			comb_p1[j] = ints1.front();
			comb_p2[j] = ints2.front();
			comb_p3[j] = ints3.front();

			ints.pop_front();
			ints1.pop_front();
			ints2.pop_front();
			ints3.pop_front();	

		}
			
		std:: cout<<"Dobitna kombinacija: ";
		for(int i = 0;i<limit;i++){	
		std::cout <<  comb[i] << " ";
		}
		std::cout<< "\n";		
	////////////////////////////////////////////////////////
		std:: cout<<"Player1: ";
		for(int i = 0;i<limit;i++){
		std::cout<<comb_p1[i]<< " ";


			for(int j=0;j<limit;j++){

				if(comb[j]==comb_p1[i]){
				
				pog_p1[k]=comb[j];
				k++;
				}
			}		
		}
		std::cout<<"\n" << "Pogodjeni: ";
		for(int i=0; i<k;i++){
			std::cout<<pog_p1[i]<<" ";
		}
		std::cout<< "\n";		
////////////////////////////////////////////////////////////////////////////////
		std:: cout<<"Player2: ";
		for(int i = 0;i<limit;i++){	
		std::cout <<  comb_p2[i] << " ";
			for(int j=0; j<limit;j++){
				
				if(comb[j]==comb_p2[i]){
				pog_p2[l]=comb[j];
				l++;
				}	

			}
		}
		std::cout<<"\n"<<"Pogodjeni:";
		for(int i=0; i<l; i++){
			std::cout<<pog_p2[i]<< " ";
		}
		std::cout<< "\n";		
/////////////////////////////////////////////////////////////////////////
		
		std:: cout<<"Player3: ";
		for(int i = 0;i<limit;i++){	
		std::cout <<  comb_p3[i] << " ";
			for(int j=0;j<limit;j++){
				if(comb[j]==comb_p3[i]){
				pog_p3[n]=comb[j];
				n++;
				}
			}
		}
		std::cout<<"\n"<<"Pogodjeni:";
		for(int i=0; i<n;i++){
			std::cout<<pog_p3[i]<< " ";
		}
		std::cout<< "\n";	
////////////////////////////////////////////////////////////////////////////////
		if(k==0 && l==0 && n==0){
			std::cout<<"Nema pobjednika."<<"\n";
		}
		else if(maximum(k, l, n)==k && maximum(k, l, n)==l && maximum(k, l, n)==n){
			std::cout<<"Pobjednici su:";
			std::cout<<"Player 1, Player2 i Player3"<<"\n";
		}

		else if(maximum(k, l, n)==k && maximum(k, l, n)==l){
			std::cout<<"Pobjednici su: ";
			std::cout<<"Player 1 i Player 2"<<"\n";
		}

		else if(maximum(k, l, n)==k && maximum(k, l, n)==n){
			std::cout<<"Pobjednici su: ";
			std::cout<<"Player 1 i Player 3"<<"\n";
		}	

		else if(maximum(k, l, n)==l && maximum(k, l, n)==n){
			std::cout<<"Pobjednici su: ";
			std::cout<<"Player 2 i Player 3"<<"\n";
		}

		else if(maximum(k, l, n)==k){
			std::cout <<"Pobjednik je: ";
			std::cout<<"Player1"<< "\n";
		}
		else if(maximum(k, l, n)== l){	
			std::cout <<"Pobjednik je: ";
			std::cout<<"Player2"<< "\n";
		}
		else if(maximum(k, l, n)==n){
			std::cout <<"Pobjednik je: ";
			std::cout<<"Player3"<<"\n";
		}
}
