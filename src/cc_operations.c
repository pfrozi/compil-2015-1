#include "cc_operations.h"
#include <stdio.h>

int r3, r2;
int PC;
int l1, l2, l3;

//nop não faz nada
void nop() {
	/*não faz nada*/ 
}

//add r1, r2 => r3 r3 = r1 + r2
void add(int r1, int r2) {
	r3 = r1 + r2;

}

//sub r1, r2 => r3 r3 = r1 - r2
void sub(int r1, int r2) {
	r3 = r1 - r2;

}

//mult r1, r2 => r3 r3 = r1 * r2
void mult(int r1, int r2) {
	r3 = r1 * r2;

}

//div r1, r2 => r3 r3 = r1/r2
void div(int r1, int r2) {
	r3 = r1 / r2;

}

//addI r1, c2 => r3 r3 = r1 + c2
void addI(int r1, int c2) {
	r3 = r1 + c2;

}

//subI r1, c2 => r3 r3 = r1 - c2
void subI(int r1, int c2) {
	r3 = r1 - c2;
}

//rsubI r1, c2 => r3 r3 = c2 - r1
void rsubI(int r1, int c2) {
	r3 = c2 - r1;
}

//multI r1, c2 => r3 r3 = r1 * c2
void multI(int r1, int c2) {
	r3 = r1 * c2;
}

//divI r1, c2 => r3 r3 = r1/c2
void divI(int r1, int c2) {
	r3 = r1/c2;
}

//rdivI r1, c2 => r3 r3 = c2/r1
void rdivI(int r1, int c2) {
	r3 = c2/r1;
}

//lshift r1, r2 => r3 r3 = r1 << r2
void lshift(int r1, int r2) {
	r3 = r1 << r2;

}

//lshiftI r1, c2 => r3 r3 = r1 << c2
void lshiftI(int r1, int c2) {
	r3 = r1 << c2;
}

//rshift r1, r2 => r3 r3 = r1 >> r2
void rshift(int r1, int r2) {
	r3 = r1 >> r2;
}

//rshiftI r1, c2 => r3 r3 = r1 >> c2
void rshiftI(int r1, int c2) {
	r3 = r1 >> c2; 
}

//and r1, r2 => r3 r3 = r1 ^ r2
void and(int r1, int r2) {
	r3 = r1 & r2;
}

//andI r1, c2 => r3 r3 = r1 ^ c2
void andI(int r1, int c2) {
	r3 = r1 & c2;
}

//or r1, r2 => r3 r3 = r1 _ r2
void or(int r1, int r2) {
	r3 = r1 | r2;
}

//orI r1, c2 => r3 r3 = r1 | c2
void orI(int r1, int c2) {
	r3 = r1 | c2;
}

//xor r1, r2 => r3 r3 = r1 xor r2
void xor(int r1, int r2) {	
	r3 = r1 ^ r2;
}

//xorI r1, c2 => r3 r3 = r1 xor c2
void xorI(int r1, int c2) {
	r3 = r1 ^ c2;
}

//loadI c1 => r2 r2 = c1
void loadI(c1) {
	r2 = c1;
}

//load r1 => r2 r2 = Memoria(r1)
void load(int r1) {
	//r2 = Memoria(r1);
}

//loadAI r1, c2 => r3 r3 = Memoria(r1 + c2)
void loadAI(int r1, int c2) {
	//r3 = Memoria(r1 + c2);
}

//loadA0 r1, r2 => r3 r3 = Memoria(r1 + r2)
void loadA0(int r1, int r2) {
	//r3 = Memoria(r1 + r2);
}

//cload r1 => r2 caractere load
void cload(int r1) {

}

//cloadAI r1, c2 => r3 caractere loadAI
void cloadAI(int r1, int c2) {

}

//cloadA0 r1, r2 => r3 caractere loadA0
void cloadA0(int r1, int r2) {

}

//store r1 => r2 Memoria(r2) = r1
void store(int r1) {
	//Memoria(r2) = r1;
}

//storeAI r1 => r2, c3 Memoria(r2 + c3) = r1
void storeAI(int r1) {
	//Memoria(r2 + c3) = r1;
}

//storeA0 r1 => r2, r3 Memoria(r2 + r3) = r1
void storeA0(int r1) {
	//Memoria(r2 + r3) = r1;
}

//cstore r1 => r2 caractere store
void cstore(int r1) {

}

//cstoreAI r1 => r2, c3 caractere storeAI
void cstoreAI(int r1) {

}

//cstoreA0 r1 => r2, r3 caractere storeA0
void cstoreA0(int r1) {

}

//i2i r1 => r2 r2 = r1 para inteiros
void i2i(int r1) {

}

//c2c r1 => r2 r2 = r1 para caracteres
void c2c(int r1) {

}

//c2i r1 => r2 converte um caractere para um inteiro
void c2i(int r1) {

}

//i2c r1 => r2 converte um inteiro para caractere
void i2c(int r1) {

}

//jumpI -> l1 PC = l1
void jumpI(int l1) {
	//PC = l1
}

//jump -> r1 PC = r1
void jump(int r1) {
	//PC = r1
}

//cbr r1 -> l2, l3 PC = l2 se r1 = true, senão PC = l3
void cbr(int r1) {
	if(r1) {
		//PC = l2;
	}
	else {
		//PC = l3;
	}
}

//cmp_LT r1, r2 -> r3 r3 = true se r1 < r2, senão r3 = false
void cmp_LT(int r1, int r2) {
	r3 = (r1 < r2);
}

//cmp_LE r1, r2 -> r3 r3 = true se r1 <= r2, senão r3 = false
void cmp_LE(int r1, int r2) {
	r3 = (r1 <= r2);
}

//cmp_EQ r1, r2 -> r3 r3 = true se r1 = r2, senão r3 = false
void cmp_EQ(int r1, int r2) {
	r3 = (r1 = r2);
}

//cmp_GE r1, r2 -> r3 r3 = true se r1 >= r2, senão r3 = false
void cmp_GE(int r1, int r2) {
	r3 = (r1 >= r2);
}

//cmp_GT r1, r2 -> r3 r3 = true se r1 > r2, senão r3 = false
void cmp_GT(int r1, int r2) {
	r3 = (r1 > r2);
}

//cmp_NE r1, r2 -> r3 r3 = true se r1 != r2, senão r3 = false
void cmp_NE(int r1, int r2) {
	r3 = (r1 != r2);
}

