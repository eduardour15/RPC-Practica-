/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calc.h"


void
calc_1(char *host, int x, int y, int z)
{
	CLIENT *clnt;
	float  *result_1;
	struct Parametros  calculadora_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, calc, calc_ver, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	calculadora_1_arg.a=x;
	calculadora_1_arg.b=y;
	calculadora_1_arg.opc=z;
	result_1 = calculadora_1(&calculadora_1_arg, clnt);
	if (result_1 == (float *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf("EL resultado es %f\n",*result_1);
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;
	int x,y,z;
	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	printf("\t------------------Calculadora----------------------- \n");
	printf("\t----------------------------------------------------\n");
	printf("\nValor 1 ----->");
	scanf("%d",&x);
	printf("\nValor 2 ----->");
	scanf("%d",&y);
	printf("\n\t---------------------MENU--------------------------- \n");
	printf("1. SUMA\n");
	printf("2. RESTA\n");
	printf("3. MULTIPLICACION\n");
	printf("4. DIVISION\n");
	scanf("%d",&z); 
	calc_1 (host,x,y,z);
exit (0);
}
