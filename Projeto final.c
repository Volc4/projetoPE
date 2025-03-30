#include <stdio.h>
#include <string.h>
#define fteto 1000  //max de bonus inicialmente
#define fvalor 0.5	//valor de um bonus inicialmente
#define fvB 100		//valor nescessario para receber um bonus inicialmente
#define MAX 200		//tamnho maximo de clientes maximo inicialmente

typedef struct Compra{
	float valortotal;			//valor total da compra
	int compracancel;			//informa se ela foi cancelada (so pode ser 1 ou 0)
	int bonus;					//quantos bonus vinculados a compra
	float umbonus;				//quanto valia um bonus no momento da compra
}tCompra;						//registro da compra

typedef struct Cliente{
	char nome[100]; 			//nome
	char cpf[12];				//cpf
	char telefone[15];			//telefone do cliente
	int bonus;					//bonus do cliente
	float totalEmCompras;		//valor total de compras do cliente
	tCompra ultimacompra;		//registro da ultima compra
}tCliente;						//registro do cliente

typedef struct Bonus{
	int teto;					//teto de bonus
	float valor;				//valor de um bonus
	float valorBonificado;		//valor necessario pra receber o bonus
}tBonus;						//registro do bonus

void fConfigB(tBonus *pBonus){
	
	int Op;
	do{
	printf("MENU CONFIGURA BONUS\n1- Alterar teto\n2- Alterar valor de um bonus\n3- Alterar valor para receber bonus\n0- Sair\n");
	scanf("%d", &Op);
	switch(Op){
	case 1:
	do{
	printf("Qual o novo valor do teto?\n");
	scanf("%d", &pBonus->teto);
	if(pBonus->teto < 0){
		printf("Erro: valor negativo. Digite novamente: \n");
	}else{
		printf("o novo teto agora e:	%d\n",pBonus->teto);
	}
	}while(pBonus->teto<0);
		break;
	case 2:
	do{
	printf("Qual o novo valor de 1 Bonus?\n");
	scanf("%f", &pBonus->valor);
	if(pBonus->valor<0){
		printf("Erro: valor negativo. Digite novamente: \n");
	}
	}while(pBonus->valor<0);
		break;
	case 3:
	do{
		printf("Qual o novo valor para receber bonus? \n");
		scanf("%f", &pBonus->valorBonificado);
	if(pBonus->valorBonificado<0){
		printf("Erro: valor negativo. Digite novamente: \n");
	}
	}while(pBonus->valorBonificado<0);
		break;
	case 0:
		break;
	default:
		printf("opcao invalida, tente novamente.\n");
	}
	}while(Op!=0);
	printf("------------------------------------------------------------\n");
	printf("teto atual:	%d	valor do bonus atual:	%.2f valor para receber bonus atual:	%.2f\n", pBonus->teto,pBonus->valor,pBonus->valorBonificado);
	printf("------------------------------------------------------------\n");
	return;
}

void fCad(tCliente *pontcliente, int *cont ){

int i,flag=0;
char stringReferencia [12];

if(*cont == (MAX)){
	printf("---ERRO: maximo de clientes atingido---\n");
	return;
}

getchar();
printf("Qual o CPF?\n");

do{
scanf(" %12[^\n]s", stringReferencia);
getchar();

if(strlen(stringReferencia)!=11){
	printf("---ERRO: Cpf invalido---\n");
}

}while(strlen(stringReferencia)!=11);

	for(i=0;i<*cont;i++){
		if(strcmp(stringReferencia, pontcliente[i].cpf)==0){
			flag=1;
		}
	}
	if(flag==0){
		strcpy(pontcliente[*cont].cpf,stringReferencia);
	}else{
		printf("---ERRO: CPF ja cadastrado---\n");
	return;
	}

	do{
	printf("Qual o nome?\n");
	scanf(" %100[^\n]s", pontcliente[*cont].nome);
	getchar();
	if(strlen(pontcliente[*cont].nome)<3){
		printf("o nome deve ter ao menos 3 caracteres\n");
	}
	}while(strlen(pontcliente[*cont].nome)<3);

	printf("Qual o telefone?\n");
	scanf(" %15[^\n]s", pontcliente[*cont].telefone);
	getchar();

	pontcliente[*cont].bonus = 0;
	pontcliente[*cont].totalEmCompras = 0;
	printf("------------------------------------------------------------\n");
	printf("OS DADOS DO CLIENTE SAO:\n");
	printf("cpf:\t%s\n", pontcliente[*cont].cpf);
	printf("nome:\t%s\n", pontcliente[*cont].nome);
	printf("telefone:\t%s\n", pontcliente[*cont].telefone);
	printf("bonus:\t%d\n", pontcliente[*cont].bonus);
	printf("total em compras:\t%.2f\n", pontcliente[*cont].totalEmCompras);
	printf("OBRIGADO PELA PREFERENCIA!!!\n");
	printf("------------------------------------------------------------\n");
	(*cont)++;
	return;
}

void fAltCad (tCliente *pontcliente, int *cont){
	
	int i,Op,flag=0,mudar;
	char stringReferencia[12];
	getchar();
	
	do{
	printf("Qual o CPF do cliente?\n");
	scanf(" %12[^\n]s", stringReferencia);
	getchar();

	if(strlen(stringReferencia)!=11){
	printf("---ERRO: Cpf invalido---\n");
	}

	}while(strlen(stringReferencia)!=11);

	for(i =  0; i < *cont; i++){
		
		if(strcmp(stringReferencia, pontcliente[i].cpf)==0){
		mudar= i;
		flag = 1;
		break;
		}
	}
	
	if(flag == 0){
		printf("---ERRO: CPF nao cadastrado.---\n");
		return;
	}else{
		do{
		printf("MENU ALTERA CLIENTE\n1 - Alterar CPF\n2 - Alterar nome\n3 - Alterar telefone\n0 - Voltar ao menu principal\n");
		scanf("%d", &Op);
		getchar();
		switch (Op){
			case 1:
				flag=0;
				do{
				printf("Qual o novo CPF?\n");
				scanf(" %12[^\n]s", stringReferencia);
				getchar();
				
				if(strlen(stringReferencia)!=11){
					printf("---ERRO: formato de cpf invalido---\n");
				}

				}while(strlen(stringReferencia)!=11);
				for(i=0;i < *cont;i++){
					if(strcmp(stringReferencia,pontcliente[i].cpf)==0){
					flag=1;
					break;
					}
				}
				if(flag==1){
				printf("Erro: CPF ja cadastrado.\n");
				break;
				}else{
					strcpy(pontcliente[mudar].cpf, stringReferencia);
				}
				
				break;
			case 2:
			do{
				
				printf("Qual o nome?\n");
				scanf(" %100[^\n]s", pontcliente[mudar].nome);
				getchar();
				if(strlen(pontcliente[mudar].nome)<3){
				printf("o nome deve ter ao menos 3 caracteres\n");
				}

				}while(strlen(pontcliente[mudar].nome)<3);
				
				break;
			case 3:
				
				printf("Qual o telefone?\n");
				scanf(" %15[^\n]s", pontcliente[mudar].telefone);
				getchar();
				break;
			case 0:
			
				printf("------------------------------------------------------------\n");
				printf("os seus novos dados sao:\ncpf:	%s\nnome:	%s\ntelefone:	%s\nbonus: %d\ntotalemcompras: %.2f\n", pontcliente[mudar].cpf, pontcliente[mudar].nome,pontcliente[mudar].telefone, pontcliente[mudar].bonus, pontcliente[mudar].totalEmCompras);
				printf("------------------------------------------------------------\n");
				break;

		}
		}while(Op!=0);
	}
return;
}

void fCompra (tCliente *pontcliente, int *cont, tBonus *pontbonus){
	
	int Op,i,flag=0,sairLoop=0,PosCpf,UsoBonus,bonusGanhos, bonusUse;
	float valorC,valorCH,valorP;
	char RefCpf[12];
	do{
	
		getchar();
		printf("Qual o CPF do cliente?\n");
		scanf(" %12[^\n]s",	RefCpf);
		getchar();
		
		for(i=0;i <= *cont ;i++){
			if(strcmp(RefCpf,pontcliente[i].cpf)==0){
				flag = 1;
				PosCpf=i;
				break;
			}
		}
		if(flag==0){
			printf("Erro: CPF nao cadastrado.\n");
			return;
		}else{
		
		printf("BONUS = %d. VALOR CORRESPONDENTE = R$ %.2f.\n", pontcliente[PosCpf].bonus, pontbonus->valor * pontcliente[PosCpf].bonus);
		}
		printf("Qual o valor da compra? R$\n");
		
		do{
			scanf("%f", &valorC);
			valorCH = valorC;
			getchar();

			if(valorC<0){
				printf("Erro: valor negativo. Digite novamente:\n");
			}
		}while(valorC<0);

		if(pontcliente[PosCpf].bonus>0){

		printf("Deseja utilizar seu bonus? [1-sim <outro valor>- nao]\n");
		scanf("%d", &UsoBonus);
		if(UsoBonus == 1){
			valorC -= (pontcliente[PosCpf].bonus * pontbonus->valor);
			
			if(valorC<= 0){
				valorC = 0;
			}

			printf("BONUS ATUAL = %d. VALOR DA COMPRA ATUALIZADO = R$ %.2f.", pontcliente[PosCpf].bonus, valorC);
			}
		}
		do{
		printf("Qual o valor do pagamento do cliente? R$\n");
		do{
		scanf("%f", &valorP);
		getchar();
		
		if(valorP<0){
		printf("Erro: valor negativo. Digite novamente:\n");
		}

		}while(valorP<0);
		if(valorP<valorC){	
			printf("Erro: Valor do pagamento inferior ao valor da compra. Deseja desisitir da compra?[1-sim <outro valor>-nao]:\n");
			scanf("%d", &Op);
			getchar();
			
			if(Op==1){
				printf("COMPRA NAO EFETIVADA. Valor devolvido ao cliente: R$ %.2f.\n", valorP);
					return;
			}
		}
		}while(valorP < valorC);
		
		if((valorP - valorC) > 0){
			printf("TROCO = R$ %.2f\n", valorP - valorC);
		}
		if(valorP >= valorC){
			sairLoop=1;
		}
		
	}while(Op!=0 && sairLoop != 1);

	if(UsoBonus == 1){
		bonusUse = valorCH/pontbonus->valor;
		if(bonusUse > pontcliente[PosCpf].bonus){
		bonusUse = pontcliente[PosCpf].bonus;
		}
		
		pontcliente[PosCpf].bonus -= bonusUse;
		printf("bonus utilizados: %d, valor da compra apos uso do bonus: %.2f, valor cheio da compra: %.2f\n", bonusUse, valorC,valorCH);
		pontcliente[PosCpf].ultimacompra.bonus = 0;
	
	}else{
		
		bonusGanhos = (valorC / pontbonus->valorBonificado); 
		if(bonusGanhos > pontbonus->teto){
			bonusGanhos=pontbonus->teto;
		}

		pontcliente[PosCpf].bonus += bonusGanhos;
		pontcliente[PosCpf].ultimacompra.bonus = bonusGanhos;	

	}
	pontcliente[PosCpf].ultimacompra.valortotal = valorCH;
	pontcliente[PosCpf].ultimacompra.umbonus = pontbonus->valor;
	pontcliente[PosCpf].ultimacompra.compracancel = 0;
	pontcliente[PosCpf].totalEmCompras += valorCH;
	return;
}

void fCancel (tCliente *pontcliente, int *cont, tBonus *pontbonus){	

	int i, PosCpf, Op, Opi, flag=0, valorBonus;
	float valorCompra;
	char stringReferencia[12];
	do{
	printf("Qual o CPF do cliente?\n");
	getchar();
	scanf(" %12[^\n]s", stringReferencia);
	getchar();
	for(i=0; i <= *cont; i++){

		if(strcmp(pontcliente[i].cpf ,stringReferencia) == 0){
			flag = 1;
			PosCpf = i;
			break;		
		}
	}
	if(flag == 0){
		printf("Erro: CPF nao cadastrado. Deseja informar outro CPF [1-sim, <outro valor>-nao]\n");
		scanf("%d", &Op);
		if(Op!=1){
			return;
		}
	}
	}while(flag != 1);
	
	do{
	printf("MENU CANCELA COMPRA 1 - Ultima compra 2 - Outra compra 3 - Exibir dados da ultima compra 0 - Sair\n");
	scanf("%d", &Op);
	switch(Op){
		case 1:
			
			if(pontcliente[PosCpf].ultimacompra.compracancel == 1){
				
				printf("ERRO: Ultima compra ja cancelada!\n");
				break;
				
			}else{
				printf("valor total da ultima compra: %.2f\nbonus ganhos na compra: %d\nvalor de um bonus no momento da compra: %.2f\n",	pontcliente[PosCpf].ultimacompra.valortotal,	pontcliente[PosCpf].ultimacompra.bonus,	pontcliente[PosCpf].ultimacompra.umbonus);
				printf("Tem certeza que deseja cancelar a ultima compra? [1-sim, <outro valor>-nao]\n");
				scanf("%d", &Opi);
				if(Opi!=1){
					printf("COMPRA NAO CANCELADA!\n");
					
					break;
				}else{
					
					printf("COMPRA CANCELADA!\n");
					
					printf("bonus da ultima compra: %d\n", pontcliente[PosCpf].ultimacompra.bonus);
					
					pontcliente[PosCpf].bonus -= pontcliente[PosCpf].ultimacompra.bonus;
					
					if (pontcliente[PosCpf].ultimacompra.valortotal > pontbonus->valor && pontcliente[PosCpf].ultimacompra.bonus == 0){
						pontcliente[PosCpf].bonus += pontcliente[PosCpf].ultimacompra.valortotal / pontbonus->valor;
					}

					printf("bonus total do cliente: %d\n", pontcliente[PosCpf].bonus);
					pontcliente[PosCpf].totalEmCompras -= pontcliente[PosCpf].ultimacompra.valortotal;
					pontcliente[PosCpf].ultimacompra.compracancel = 1;
					break;
				}
			}

			break;
		case 2:
			do{
			printf("Qual o valor da compra a ser cancelada?\n");
			scanf("%f", &valorCompra);
			if(valorCompra<0){
				printf("Erro: valor negativo.\n");
			}
			}while(valorCompra<0);
			valorBonus = valorCompra/pontbonus->valorBonificado;
			
			if(valorBonus<1){
				valorBonus = 0;
			}

			if(valorBonus>pontbonus->teto){
				valorBonus = pontbonus->teto;
			}
			
			valorBonus = valorBonus * 2;
			printf("BONUS A SER DESCONTADO = %d. Tem certeza que deseja cancelar a compra? [1-sim, <outro valor> -nao]\n", valorBonus);
			scanf("%d",&Opi);
			
			if(Opi!=1){
				printf("COMPRA NAO CANCELADA!\n");
				break;
			}else{
				printf("COMPRA CANCELADA!\n");
			
				if(pontcliente[PosCpf].bonus - valorBonus <= 0){	
					printf("AVISO: SEUS BONUS ZERARAM!\n");
					pontcliente[PosCpf].bonus = 0;
					}else{
					pontcliente[PosCpf].bonus-= valorBonus;
					}
					
					pontcliente[PosCpf].totalEmCompras -= valorCompra;
			
				if(pontcliente[PosCpf].totalEmCompras <= 0){
					pontcliente[PosCpf].totalEmCompras= 0;
				}
			}
			break;
		case 3:
			printf("------------------------------------------------------------\n");
			printf("NOME DO CLIENTE:\t%s\n", pontcliente[PosCpf].nome);
			printf("CPF DO CLIENTE:\t%s\n", pontcliente[PosCpf].cpf);
			printf("VALOR DA COMPRA:\tR$ %.2f\n", pontcliente[PosCpf].ultimacompra.valortotal);
			printf("PONTOS ADQUIRIDOS COM A COMPRA:\t%d\n", pontcliente[PosCpf].ultimacompra.bonus);
			printf("VALOR DE UM BONUS NA EPOCA DA COMPRA: R$\t%.2f\n", pontcliente[PosCpf].ultimacompra.umbonus);
			printf("------------------------------------------------------------\n");
			break;
	}
	
	}while(Op!=0);
	return;
}

void fConsult(tCliente *pontcliente, int *pcont, tBonus *pontbonus){
	
	int i,flag=0,PosCpf;
	char stringReferencia[12];

		printf("Qual o CPF do cliente?\n");
		getchar();
		scanf(" %12[^\n]s", stringReferencia);
		for(i=0;i <= *pcont; i++){
			if(strcmp(stringReferencia,pontcliente[i].cpf)==0){
				
				PosCpf = i;
				flag = 1;
			}
		}
		if(flag == 0){
			printf("Erro: CPF nao cadastrado.\n");
			return;
		}
		if(flag == 1){
			printf("------------------------------------------------------------\n");
			printf("BONUS =\t%d.\nVALOR CORRESPONDENTE = R$\t%.2f.\n", pontcliente[PosCpf].bonus, (pontcliente[PosCpf].bonus * pontbonus->valor));
			printf("------------------------------------------------------------\n");
		}

	return;
}

void fDados	 (tCliente *pontcliente, int *pcont){
	int i; 

	if(*pcont<=0){
		printf("Erro: sem clientes cadastrados\n");
		return;
	}

	printf("RELATORIO DE DADOS DOS CLIENTES\n");

	for(i = 0;i < *pcont; i++){
		printf("------------------------------------------------------------\n");
		printf("Nome:\t%s\n", pontcliente[i].nome);
		printf("CPF:\t%s\n", pontcliente[i].cpf);
		printf("Telefone:\t%s\n", pontcliente[i].telefone);
		printf("Bonus:\t%d\n", pontcliente[i].bonus);
		printf("Total em compras:\t%.2f\n", pontcliente[i].totalEmCompras);
		printf("------------------------------------------------------------\n");
	}
	return;
}

void fBonus	 (tCliente *pontcliente, int *pcont, tBonus *pontbonus){
	int i;
	
	if(*pcont<=0){
		printf("Erro: sem clientes cadastrados\n");
		return;
	}
	for(i=0;i<*pcont;i++){
		printf("------------------------------------------------------------\n");
		printf("Nome:\t%s\n", pontcliente[i].nome);
		printf("CPF:\t%s\n", pontcliente[i].cpf);
		printf("Bonus:\t%d\n", pontcliente[i].bonus);
		printf("Valor do Bonus: R$\t%.2f\n", (pontcliente[i].bonus * pontbonus->valor));
		printf("------------------------------------------------------------\n");
		
	}
	return;
}

void fLista  (tCliente *pontcliente, int *pcont){

	int i,Op,cont=0;
	float vBusca,vInicial,vFinal, Troca;
	do{
		cont=0;
		if(*pcont == 0){
			printf("---ERRO: Sem clientes cadastrados---\n");
			return;
		}
		printf("\n------------------------------------------------------------\n");
		printf("RELATORIO DE COMPRAS\n");
		printf("1- Total de compras inferior a um valor\n");
		printf("2- Total de compras superior a um valor\n");
		printf("3- Total de compras igual a um valor\n");
		printf("4- Total de compras em uma faixa\n");
		printf("0- Sair\n");
		printf("------------------------------------------------------------\n");
		scanf("%d", &Op);

		switch (Op){
			case 1:
			printf("Qual o valor?\n");
			do{
				scanf("%f", &vBusca);

				if(vBusca<0){
					printf("Erro: valor negativo. Digite novamente:\n");
				}
				
			}while(vBusca<0);

			for(i=0;i<*pcont;i++){	
				
				if(pontcliente[i].totalEmCompras < vBusca){
					printf("\n------------------------------------------------------------\n");
					printf("\n");
					printf("Nome:\t%s\n", pontcliente[i].nome);
					printf("CPF:\tt%s\n", pontcliente[i].cpf);
					printf("Total em compras:\t%.2f\n", pontcliente[i].totalEmCompras);
					printf("------------------------------------------------------------\n");
					cont++;
				}
			}	
				if(cont==0){
					printf("---ERRO: Nao houve clientes com valores inferiores que esse em compras---\n");
				}
			

				break;
			case 2:
			printf("Qual o valor?\n");
			do{
				scanf("%f", &vBusca);

				if(vBusca<0){
					printf("Erro: valor negativo. Digite novamente:\n");
				}
			}while(vBusca<0);

			for(i=0;i<*pcont;i++){
				if(pontcliente[i].totalEmCompras > vBusca){
					printf("\n------------------------------------------------------------\n");
					printf("\n");
					printf("Nome:\t%s\n", pontcliente[i].nome);
					printf("CPF:\t%s\n", pontcliente[i].cpf);
					printf("Total em compras:\t%.2f\n", pontcliente[i].totalEmCompras);
					printf("------------------------------------------------------------\n");
					cont++;
				}
			}
				if(cont==0){
					printf("---ERRO: Nao houve clientes com valores superiores que esse em compras---\n");
				}

				break;
			case 3:
				
			printf("Qual o valor?\n");
			do{
				scanf("%f", &vBusca);

				if(vBusca<0){
					printf("Erro: valor negativo. Digite novamente:\n");
				}
			}while(vBusca<0);

			for(i=0;i<*pcont;i++){
				if(pontcliente[i].totalEmCompras == vBusca){
					printf("\n------------------------------------------------------------\n");
					printf("\n");
					printf("Nome:\t%s\n", pontcliente[i].nome);
					printf("CPF:\t%s\n", pontcliente[i].cpf);
					printf("Total em compras:\t%.2f\n", pontcliente[i].totalEmCompras);
					printf("------------------------------------------------------------\n");
					cont++;
				}
			}	
				if(cont==0){
					printf("---ERRO: Nao houve clientes com esse valor em compras---\n");
				}

				break;
			case 4:
				
			printf("Qual o valor inicial?\n");
			do{
				scanf("%f", &vInicial);

				if(vInicial<0){
					printf("ERRO: valor negativo. Digite novamente:\n");
				}

			}while(vInicial<0);
			printf("Qual o valor final?\n");
			do{
				scanf("%f", &vFinal);

				if(vFinal<0){
					printf("ERRO: valor negativo. Digite novamente:\n");
				}

			}while(vFinal<0);

			if(vInicial>vFinal){
				Troca = vInicial;
				vInicial = vFinal;
				vFinal = Troca;
			}
				for(i=0;i<*pcont;i++){
				
				if(pontcliente[i].totalEmCompras > vInicial && pontcliente[i].totalEmCompras < vFinal){
					printf("\n------------------------------------------------------------\n");
					printf("\n");
					printf("Nome:\t%s\n", pontcliente[i].nome);
					printf("CPF:\t%s\n", pontcliente[i].cpf);
					printf("Total em compras:\t%.2f\n", pontcliente[i].totalEmCompras);
					printf("------------------------------------------------------------\n");
					cont++;
				}
				}
				
				if(cont==0){
					printf("---ERRO: Nao houve clientes com valores nessa faixa de preco em compras---\n");
				}
				break;
		}
	}while(Op!=0);
	return;
}

int main(){
	int Op;
	int contC=0;
	int *pcont;

	tBonus bonus;
	bonus.teto = fteto;
	bonus.valor = fvalor;
	bonus.valorBonificado=fvB;
	
	tBonus *pBonus;
	pBonus	=	&bonus;

	tCliente cliente[MAX];
	tCliente *pClientes;

	pcont = &contC;
	pClientes = &cliente[0];
	do{
	printf("MENU PRINCIPAL\n");
	printf("01 - Configurar bonus\n");
	printf("02 - Cadastrar cliente\n");
	printf("03 - Alterar cadastro do cliente\n");
	printf("04 - Efetivar compra\n");
	printf("05 - Cancelar compra\n");
	printf("06 - Consultar bonus\n");
	printf("07 - Listar dados de todos os clientes\n");
	printf("08 - Listar bonus de todos os clientes\n");
	printf("09 - Listar clientes pelo valor total de compras\n");
	printf("00 - Sair\n");
	scanf("%d", &Op);
	switch(Op){
	case 1:
		fConfigB(pBonus);
		break;
	case 2:
		fCad(pClientes,pcont);
		break;
	case 3:
		fAltCad(pClientes,pcont);
		break;
	case 4:
		fCompra(pClientes, pcont, pBonus);
		break;
	case 5:
		fCancel(pClientes, pcont, pBonus);
		break;
	case 6:
		fConsult(pClientes, pcont, pBonus);
		break;
	case 7:
		fDados(pClientes,pcont);
		break;
	case 8:
		fBonus(pClientes,pcont,pBonus);
		break;
	case 9:
		fLista(pClientes,pcont);
		break;
	}
	}while(Op!=0);
	return 0;
}