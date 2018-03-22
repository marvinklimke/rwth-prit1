/*
 * Caesar.cpp
 *
 *  Created on: 17.04.2016
 *      Autor: Marvin Klimke
 *      Matr.: 000000
 *      Datum: 17.04.2016
 */

#include <iostream>

/**
 * @brief Verschl�sselungsfunktion
 * Verschl�sselt ein Zeichen c unter Verwendung der Lookup-Table.
 */
char encrypt_mkl(char c)
{
	char lookup_enc[2][26] = {	{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
								{ 'N', 'O', 'L', 'J', 'C', 'Z', 'B', 'G', 'A', 'T', 'Q', 'F', 'S', 'E', 'V', 'I', 'U', 'X', 'K', 'W', 'D', 'Y', 'R', 'M', 'P', 'H' } };

	int index_c = (int)c - (int)('A');
	return lookup_enc[1][index_c];
}

/**
 * @brief Entschl�sselungsfunktion
 * Entschl�sselt ein Zeichen c unter Verwendung der Lookup-Table.
 */
char decrypt_mkl(char c)
{
	char lookup_dec[2][26] = {	{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
								{ 'I', 'G', 'E', 'U', 'N', 'L', 'H', 'Z', 'P', 'D', 'S', 'C', 'X', 'A', 'B', 'Y', 'K', 'W', 'M', 'J', 'Q', 'O', 'T', 'R', 'V', 'F' } };

	int index_c = (int)c - (int)('A');
	return lookup_dec[1][index_c];
}

/**
 * @brief Ver- und Entschl�sselungsfunktion ROT13
 * Verschl�sselt oder Entschl�sselt ein Zeichen c unter Verwendung der ROT13-Standard-Lookup-Table.
 */
char rot13(char c)
{
	char lookup[2][26] = {	{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
							{ 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M' } };

	int index_c = (int)c - (int)('A');
	return lookup[1][index_c];
}

/**
 * @brief Hauptprogramm zum Testen der Verschl�sselung
 */
int main(void)
{
	char wort[6];
	std::cout << "Bitte geben Sie ein Wort aus f�nf Gro�buchstaben ein: ";
	std::cin  >> wort;

	char wort_enc[6];

	wort_enc[0] = encrypt_mkl(wort[0]);
	wort_enc[1] = encrypt_mkl(wort[1]);
	wort_enc[2] = encrypt_mkl(wort[2]);
	wort_enc[3] = encrypt_mkl(wort[3]);
	wort_enc[4] = encrypt_mkl(wort[4]);
	wort_enc[5] = '\0';

	std::cout << "Das verschl�sselte Wort: " << wort_enc << std::endl;

	char wort_dec[6];

	wort_dec[0] = decrypt_mkl(wort_enc[0]);
	wort_dec[1] = decrypt_mkl(wort_enc[1]);
	wort_dec[2] = decrypt_mkl(wort_enc[2]);
	wort_dec[3] = decrypt_mkl(wort_enc[3]);
	wort_dec[4] = decrypt_mkl(wort_enc[4]);
	wort_dec[5] = '\0';

	std::cout << "Das entschl�sselte Wort: " << wort_dec << std::endl;

	char wort_enc_rot13[6];

	wort_enc_rot13[0] = rot13(wort[0]);
	wort_enc_rot13[1] = rot13(wort[1]);
	wort_enc_rot13[2] = rot13(wort[2]);
	wort_enc_rot13[3] = rot13(wort[3]);
	wort_enc_rot13[4] = rot13(wort[4]);
	wort_enc_rot13[5] = '\0';

	std::cout << "Das ROT13-verschl�sselte Wort: " << wort_enc_rot13 << std::endl;

	char wort_dec_rot13[6];

	wort_dec_rot13[0] = rot13(wort_enc_rot13[0]);
	wort_dec_rot13[1] = rot13(wort_enc_rot13[1]);
	wort_dec_rot13[2] = rot13(wort_enc_rot13[2]);
	wort_dec_rot13[3] = rot13(wort_enc_rot13[3]);
	wort_dec_rot13[4] = rot13(wort_enc_rot13[4]);
	wort_dec_rot13[5] = '\0';

	std::cout << "Das ROT13-entschl�sselte Wort: " << wort_dec_rot13 << std::endl;

	return 0;
}

// E.O.F.
