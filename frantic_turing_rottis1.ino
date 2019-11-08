int segA = 0,
		segB = 1,
		segC = 2,
		segD = 3,
		segE = 4,
		segF = 5,
		segG = 6,
		botA = A0,
		botB = A1,
		botC = A2,
		botD = A3;

void setup()
{
	pinMode(segA, OUTPUT); //A -
	pinMode(segB, OUTPUT); //B -
	pinMode(segC, OUTPUT); //C -
	pinMode(segD, OUTPUT); //D -
	pinMode(segE, OUTPUT); //E -
	pinMode(segF, OUTPUT); //F -
	pinMode(segG, OUTPUT); //G -
}

void loop()
{
	bool A = digitalRead(botA); //1 entradas 4x
	bool B = digitalRead(botB); //2
	bool C = digitalRead(botC); //3
	bool D = digitalRead(botD); //4

	digitalWrite(segA, acendeA(A, B, C, D)); // saídas 7x
	digitalWrite(segB, acendeB(A, B, C, D));
	digitalWrite(segC, acendeC(A, B, C, D));
	digitalWrite(segD, acendeD(A, B, C, D));
	digitalWrite(segE, acendeE(A, B, C, D));
	digitalWrite(segF, acendeF(A, B, C, D));
	digitalWrite(segG, acendeG(A, B, C, D));
}

bool acendeA(bool A, bool B, bool C, bool D)
{
	return (!B && !D) || (A) || (B && D) || (B && C) || (C && D);
}

bool acendeB(bool A, bool B, bool C, bool D)
{
	//bool isAceso = (!B && !D) || (!C && !D) || (!B) || (A && !C) || (!A && C && D);
	return (!A && !C && !D) || (A && !C && D) || (!A && C && D) || (!B);
}

bool acendeC(bool A, bool B, bool C, bool D)
{
	return (!A && !C) || (!A && D) || (!A && B) || (A && !B) || (!C && D);
}

bool acendeD(bool A, bool B, bool C, bool D)
{
	return (!A && !B && !C && !D) || (A && !C) || (B && !C && D) || (A && !B && D) || (!A && !B && C) || (B && C && !D);
}

bool acendeE(bool A, bool B, bool C, bool D)
{
	return (!B && !D) || (A && B) || (A && !B && C) || (C && !D);
}

bool acendeF(bool A, bool B, bool C, bool D)
{
	return (!C && !D) || (B && !C) || (A && D) || (A && C) || (B && C && !D);
}

bool acendeG(bool A, bool B, bool C, bool D)
{
	return (!A && B && !C) || (A && !B) || (!A && !B && C) || (A && C) || (C && !D);
}
