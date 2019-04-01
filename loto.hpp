#ifndef	MODULE01_H
#define MODULE01_H


#include <systemc>
#include <iostream>
#include <deque>

SC_MODULE(Module01)
{
public:
	SC_HAS_PROCESS(Module01);

	Module01(sc_core::sc_module_name name, int limit = 7);
	
		void lotto_machine();
		void player1();
		void player2();
		void player3();
		void result();

protected:
		std::deque<int> ints;
		std::deque<int> ints1;
		std::deque<int> ints2;
		std::deque<int> ints3;
		int limit;
	};
#endif

