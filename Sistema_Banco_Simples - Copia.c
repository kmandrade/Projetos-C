#include <stdio.h>
#include <ctype.h>
#include <string.h>

float mont_banco=0;
int aux_agencia[10],aux_cliente[100],aux_conta[100];
char aux[2];

typedef struct
{
    int codigo;
    char nome[200];
    int codigo_cliente;
} Agencia;

Agencia agencia[10];

typedef struct
{
    char nome[100];
    char sexo;
    int codigo;
} Cliente;

Cliente cliente[100];

typedef struct
{
    float saldo;
    int codigo_agencia;
    int codigo_cliente;
    int codigo;
} Conta;

Conta conta[100];

void vetor_auxiliar()
{
    int i;
    for(i=0;i<10;i++){
        aux_agencia[i]=0;
    }

    for(i=0;i<100;i++){
		aux_conta[i]=0;
		aux_cliente[i]=0;
	}
}

int inicializar()
{
	aux_agencia[0]=1;
	strcpy(agencia[0].nome,"Agencia do DCOMP");
	agencia[0].codigo = 1;

	aux_cliente[0]=1;
	strcpy(cliente[0].nome,"Antonio da Silva");
	cliente[0].sexo = 'M';
	cliente[0].codigo = (agencia[0].codigo*100)+1;
	agencia[0].codigo_cliente = cliente[0].codigo;

	aux_conta[0]=1;
	conta[0].saldo=500;
	conta[0].codigo_agencia = agencia[0].codigo;
	conta[0].codigo_cliente = cliente[0].codigo;
	conta[0].codigo = (agencia[0].codigo*1000)+1;
	mont_banco+=conta[0].saldo;
}

int montante_banco()
{
	printf("Este e o montante total do banco do DCOMP: ");
	printf("%.2f reais\n\n", mont_banco);
	menu();
}

int cadastrar_agencia()
{
    printf("\nVoce selecionou: Cadastrar agencia\n");
    printf("Se selecionou a opcao errada, digite 0 para retornar\n");
    printf("No maximo 10 agencias podem ser cadastradas\n");
    printf("Digite quantas agencias deseja cadastrar: \n");

    int num_agencias;
    scanf("%d", &num_agencias);
    gets(aux);

    if(num_agencias==0) {
        menu_agencia();
    }
    else {
        while(num_agencias>10 || num_agencias<0){
            if(num_agencias>10)
            printf("O numero de agencias nao pode exceder 10\nDigite outro valor: ");
            if(num_agencias<0)
            printf("O numero de agencias nao pode ser negativo\nDigite outro valor: ");

            scanf("%d", &num_agencias);
        	gets(aux);
		}
        int i;
        for( i=0;i<num_agencias;i++){
                while(aux_agencia[i]==1){
                    i++;
                }
            printf("Digite o nome da agencia %d:", i+1);
            gets(agencia[i].nome);
            agencia[i].codigo=i+1;
            aux_agencia[i]=1;
        }
    }
    printf("\nO que deseja fazer agora?\n");
    menu_agencia();
}

int agencias_existentes()
{
    int j=0;
    printf("\nEstas sao as agencias existentes no momento: \n");
    int i;
    for(i=0;i<10;i++){
        if(aux_agencia[i]==1){
            printf("\nNome da agencia %d: %s", i+1,agencia[i].nome);
            printf("\nCodigo da agencia %d: %d\n", i+1,agencia[i].codigo);
            j++;
        }
    }

    if(j==0){
        printf("\nNenhuma agencia esta cadastrada atualmente\n");
	}
	menu_agencia();
}

int remover_agencia ()
{

    int codigo,j=0;
    char opcao_add[2];
    printf("Digite o codigo da agencia que deseja remover: ");

    scanf("%d", &codigo);
    int i;
    for (i=0;i<10;i++){
        if(codigo == agencia[i].codigo){
            printf("\nA agencia %s tem codigo igual a: %d\n",
                    agencia[i].nome, codigo);
            j++;
        }
    }

    if(j==0){
        printf("\nnenhuma agencia possui o codigo %d", codigo);
        printf(" deseja adicionar outro codigo (S ou N)?\n");

        scanf("%[^\n]", &opcao_add);

        if (strcmp(opcao_add, "S")==0)
            remover_agencia();

        if (strcmp(opcao_add, "N")==0)
            menu_agencia();

        while(strcmp(opcao_add, "S")!=0)
            printf("por favor, digite S ou N (com letra maiuscula): ");

    }
    else{
            int i;
        for(i=0;i<10;i++){
            if(codigo == agencia[i].codigo){
                printf("Deseja remover a agencia %s e todos os seus dados? (S ou N)",
                        agencia[i].nome);
                scanf("%s", &opcao_add);
                if(strcmp(opcao_add, "S")==0){
                    aux_agencia[i]=0;
                    printf("A agencia %s foi removida do banco\n",
                            agencia[i].nome);
                }
                else if(strcmp(opcao_add, "N")==0){
                    printf("A agencia %s continuara existente no banco",
                            agencia[i].nome);
                }
                while(strcmp(opcao_add, "S")!=0 && strcmp(opcao_add, "N")!=0){
                    printf("por favor, digite S ou N (com letra maiuscula):");
                    scanf("%s",&opcao_add);
                }
            }
        }
    }
    menu_agencia();
}

int cadastrar_cliente() //relacionar clientes com agencias
{
	int l=0;
	int i;
	for(i=0;i<10;i++){
		if(aux_agencia[i]==1)
			l++;
	}

	if(l==0) {
		printf("\nNao e possivel cadastrar clientes sem nenhuma agencia criada\n");
		printf("Retornando ao menu principal...\n\n");
		menu();
	}

    printf("\nVoce selecionou: Cadastrar cliente\n");
    printf("Se selecionou a opcao errada, digite 0 para retornar\n");
    printf("No maximo 100 clientes podem ser cadastrados\n");
    printf("Digite quantos clientes deseja cadastrar: \n");

    int num_clientes=0;

    scanf("%d", &num_clientes);

    if(num_clientes == 0) {
        menu_cliente();
    }

	else {

		int num_agencia,i=0,j=0,cod_cliente;
		char adicionar[2];
		printf("\nInsira o codigo da agencia que deseja cadastrar seu cliente: ");
		scanf("%d", &num_agencia);

		for(i=0;i<10;i++){
			if(num_agencia==agencia[i].codigo){
				j++;
				cod_cliente=i+1;
				printf("voce inseriu o codigo da agencia: %s\n",
						agencia[i].nome);
			}
		}

            while(j==0) {
                printf("Codigo invalido\n");
                printf("Estas sao as agencias existentes no momento: \n");
                int i;
                for(i=0;i<10;i++){
                    if(aux_agencia[i]==1){
                    printf("\nNome da agencia %d: %s", i+1,agencia[i].nome);
                    printf("\nCodigo da agencia %d: %d\n", i+1,agencia[i].codigo);
                    }
                }
                printf("Digite novamente o codigo da agencia desejada: ");
                scanf("%d", &num_agencia);
                if(num_agencia==agencia[i].codigo){
                    j++;
                    cod_cliente=i+1;
                    printf("voce inseriu o codigo da agencia: %s\n",
                            agencia[i].nome);
                }
            }

        if(j!=0) {
                int i;
            for(i=0;i<num_clientes;i++){
            	while(aux_cliente[i]==1){
            		i++;
            		num_clientes++;
				}
				aux_cliente[i]=1;

                printf("digite o nome do cliente %d: ", i+1);
                gets(cliente[i].nome);
				gets(aux);

                cliente[i].codigo = (cod_cliente*100)+i+1;
                conta[i].codigo_cliente = cliente[i].codigo;
                conta[i].codigo_agencia = cod_cliente;
                conta[i].codigo = (cod_cliente*1000)+i+1;
                conta[i].saldo = 0;

				printf("Digite o sexo do cliente (M ou F): ");
                scanf("%c", &cliente[i].sexo);
                gets(aux);

				//} while (cliente[i].sexo != 'M' && cliente[i].sexo != 'F')
            }

            	printf("Deseja adicionar mais clientes? (S ou N)");
                gets(adicionar);
                gets(aux);

                while (1){
                	if(strcmp(adicionar,"S")!=0 && strcmp(adicionar,"N")!=0){
						printf("\nPor favor, insira S ou N: ");
						gets(adicionar);
					}
					else{
						if(strcmp(adicionar,"S")==0){
                		cadastrar_cliente();
               			}

                		if(strcmp(adicionar,"N")==0){
                		menu_cliente();
                		};
					}
				}
        }
	}
}

int clientes_existentes()
{
	int j=0;
    printf("\nEstes sao os clientes existentes no momento: \n");
    int i;
    for(i=0;i<100;i++){
        if(aux_cliente[i]==1){
            printf("\nNome do cliente %d: %s", i+1, cliente[i].nome);
            printf("\nCodigo do cliente %d: %d\n", i+1, cliente[i].codigo);
            printf("Sexo do cliente %d: %c\n", i+1, cliente[i].sexo);
            printf("Codigo da agencia do cliente %d: %d\n", i+1,(cliente[i].codigo-1)/100);
            j++;
        }
    }

    if(j==0){
		printf("\nNenhum cliente esta cadastrado atualmente\n");
	}
	menu_cliente();
}

int contas_cliente()
{
	printf("\nVoce selecionou: Exibir quantas contas um cliente possui\n");
    printf("Se selecionou a opcao errada, digite 0 para retornar\n");
    printf("Insira o codigo do cliente como resposta\n");
	printf("Deseja verificar a conta de qual cliente?\n");

	int opcao,j=0;
	scanf("%d", &opcao);
	if(opcao==0){
		menu_cliente();
	}
	else{
            int i;
		for(i=0;i<100;i++){
			if(opcao==cliente[i].codigo && aux_cliente[i]==1){
				j++;
				printf("voce selecionou o codigo do cliente %s\n",
				 cliente[i].nome);
			}
		}
		if(j==0){
			printf("Nenhum cliente possui codigo igual a %d\n\n", opcao);
			contas_cliente();
		}
		else{
		    int i;
			for(i=0;i<100;i++){
				if(opcao==conta[i].codigo_cliente && aux_conta[i]==1){
					printf("Conta %d do cliente %d\n", i+1,opcao);
					printf("saldo: %.2f\n", conta[i].saldo);
					printf("pertence a agencia: %d\n", conta[i].codigo_agencia);
					printf("codigo da conta: %d\n", conta[i].codigo);
				}
			}
		}
		menu_cliente();
	}
}

int saldo_total()
{
	printf("em construcao");
}

int saldo_agencia()
{
	printf("em construcao");
}

int cadastrar_conta() //ADICIONE A OPCAO DE CADASTRAR EM AGENCIAS DIFERENTES
{
	int opcao,j=0,adicionar,cod_agencia;
	printf("\nVoce selecionou: Cadastrar conta\n");
    printf("Se selecionou a opcao errada, digite 0 para retornar\n");
    printf("Insira o codigo do cliente que deseja criar a conta: ");
    scanf("%d", &opcao);

    if(opcao==0){
    	menu_conta();
	}

	else{
        int i;
	    for(i=0;i<100;i++){
	    	if(opcao==cliente[i].codigo && aux_cliente[i]==1){
	    		j++;
			}
		}

		if(j==0){
			printf("Nenhum cliente possui codigo %d\n", opcao);
			cadastrar_conta();
		}

		else{
			j=0;

			printf("Quantas contas deseja cadastrar para o cliente %d?\n", opcao);
			scanf("%d", &adicionar);
			printf("Em qual agencia deseja cadastrar esta conta?\n");
			scanf("%d", &cod_agencia);
			gets(aux);

			while(j==0){
                    int i;
				for(i=0;i<10;i++){
					if(cod_agencia==agencia[i].codigo && aux_agencia[i]==1){
						j++;
						printf("Voce digitou o codigo da agencia %s\n", agencia[i].nome);
					}
				}
				if(j==0){
					printf("Nenhuma agencia possui codigo %d", cod_agencia);
					scanf("%d", &cod_agencia);
				}
			}
            int i;
			for(i=0;i<adicionar;i++){
				while(aux_agencia[i]==1){
					i++;
					adicionar++;
				}

				aux_conta[i] = 1;
				conta[i].saldo = 0;
				conta[i].codigo_cliente = opcao;
				conta[i].codigo_agencia = cod_agencia;
				conta[i].codigo = (cod_agencia*1000)+(i+1);

				printf("Conta de codigo %d criada\n\n", conta[i].codigo);
			}
		}
	}
	menu_conta();
}

int remover_conta() //VALIDAR O S OU N NO GETS(ESCOLHA)
{
	int opcao;

	printf("\nVoce selecionou: Remover conta\n");
    printf("Se selecionou a opcao errada, digite 0 para retornar\n");
    printf("Digite o codigo da conta que deseja remover: ");
    scanf("%d", &opcao);
    gets(aux);

    if(opcao==0){
		menu_conta();
	}

	int j=0;
	char escolha[2];

	if(opcao!=0) {
            int i;
		for(i=0;i<100;i++){
	    	if(opcao==conta[i].codigo){
	    		j++;
			}
		}

		if(j==0){
				printf("Nenhuma conta possui este codigo\nretornando ao menu da conta...");
				menu_conta();
			}

		else{
			printf("Tem certeza que deseja remover a conta de codigo %d? (S ou N)\n", opcao);
			gets(escolha);
			gets(aux);

			if(strcmp(escolha,"S")==0){
                    int i;
				for(i=0;i<100;i++){
		   			if(opcao==conta[i].codigo){
		   				aux_conta[i]=0;
					}
					mont_banco -= conta[i].saldo;
				}
				printf("A conta %d foi removida\n", opcao);
				printf("retornando ao menu da conta...");
				menu_conta();
			}
			if(strcmp(escolha,"N")==0){
				remover_conta();
			}

		}

	}
}

int transferencia() //SALDO NAO PODE SER NEGATIVO
{
	int j=0,opcao,temp;
	float quantia;
    int i;
	for(i=0;i<100;i++){
		if(aux_conta[i]==1){
			j++;
		}
	}

	if(j<2){
		printf("Nao existem contas o suficiente para realizar uma transferencia\n");
		printf("retornando ao menu de contas");
		menu_conta();
	}
	else{
		printf("\nVoce selecionou: Transferir quantia\n");
	    printf("Se selecionou a opcao errada, digite 0 para retornar\n");
	    printf("Digite o codigo da conta que tera o valor transferido: ");
	    scanf("%d", &opcao);
		temp = opcao;

		char escolha[2];
		j=0;

		if(opcao==0){
			menu_conta();
		}

		else{
                int i;
			for(i=0;i<100;i++){
				if(opcao==conta[i].codigo && aux_conta[i]==1){
					j++;
				}
			}
			if(j==0){
				printf("Nenhuma conta possui este codigo\n");
				transferencia();
			}
			else{
				j=0;
				printf("para qual conta deseja transferir?\n");
				scanf("%d", &opcao);

				while(opcao==temp){
					printf("Voce nao pode transferir para a mesma conta\n");
					printf("Digite o codigo da outra conta que deseja transferir: ");
					scanf("%d", &opcao);
				}
                int i;
				for(i=0;i<100;i++){
					if(opcao==conta[i].codigo && aux_conta[i]==1){
						j++;
					}
				}
				while(j==0){

					printf("Nenhuma conta possui este codigo\n");
					printf("Digite um codigo existente: ");
					scanf("%d", &opcao);
                    int i;
					for(i=0;i<100;i++){
						if(opcao==conta[i].codigo && aux_conta[i]==1){
							j++;
						}
					}
				}
				printf("Digite a quantia que deseja transferir: ");
				scanf("%f", &quantia);;

				for(i=0;i<100;i++){
					if(temp==conta[i].codigo){
						conta[i].saldo -= quantia;
					}
					if(opcao==conta[i].codigo){
						conta[i].saldo += quantia;
					}
				}
			}
			printf("Transferencia efetuada com sucesso!\n");
			menu_conta();
		}
	}
}

int depositar_quantia()
{
	printf("\nVoce selecionou: Depositar quantia em uma conta \n");
    printf("Se selecionou a opcao errada, digite 0 para retornar\n");
    printf("Digite o codigo da conta que deseja depositar: ");

    int opcao,j=0;
	float deposito;
    scanf("%d", &opcao);

    if(opcao==0){
    	menu_conta();
	}

	else{
            int i;
		for(i=0;i<100;i++){
			if(opcao==conta[i].codigo && aux_conta[i]==1){
				j++;
			}
		}
		if(j==0){
			printf("Nenhuma conta possui codigo %d: \n\n", opcao);
			depositar_quantia();
		}

		else{
			printf("quantos reais deseja depositar na conta?\n");
			scanf("%f", &deposito);
			int i;
			for(i=0;i<100;i++){
				if(opcao==conta[i].codigo && aux_conta[i]==1){
					conta[i].saldo += deposito;
					mont_banco += deposito;
				}
			}
			printf("Deposito de %.2f reais realizado com sucesso!\n", deposito);
		}
		menu_conta();
	}
}

int contas_existentes()
{
	int j=0;
	int i;
	for(i=0;i<100;i++){
		if(aux_conta[i]==1){
			j++;
		}
	}

	if(j==0){
		printf("nao existe nenhuma conta criada no momento\n");
		printf("retornando ao menu de contas...\n\n");
		menu_conta();
	}

	else{
		printf("essas sao as contas existentes no momento:\n\n");
		int i;
		for(i=0;i<100;i++){
			if(aux_conta[i]==1){
				printf("\nCodigo da conta: %d\n", conta[i].codigo);
				printf("Saldo da conta: %.2f\n", conta[i].saldo);
				printf("Pertence ao cliente de codigo: %d\n", conta[i].codigo_cliente);
				printf("Pertecence a agencia de codigo: %d\n", conta[i].codigo_agencia);
			}
		}
	}
	menu_conta();
}

int remover_cliente() //VALIDAR O S OU N NO GETS(ESCOLHA)
{
	int opcao;

	printf("\nVoce selecionou: Remover Cliente\n");
    printf("Se selecionou a opcao errada, digite 0 para retornar\n");
    printf("Digite o codigo do cliente que deseja remover: ");
    scanf("%d", &opcao);
    gets(aux);
    int j=0;
	char escolha[2];

	if(opcao==0){
		menu_cliente();
	}

	else{
        int i;
	    for(i=0;i<100;i++){
	    	if(opcao==cliente[i].codigo){
	    		j++;
			}
		}

		if(j==0){
			printf("Codigo do cliente nao existe\nretornando ao menu do cliente...");
			menu_cliente();
		}

		else{
			printf("Tem certeza que deseja remover o cliente de codigo %d? (S ou N)\n", opcao);
			gets(escolha);
			if(strcmp(escolha,"S")==0){
                    int i;
				for(i=0;i<100;i++){
	    			if(opcao==cliente[i].codigo){
	    				aux_cliente[i]=0;
					}
				}
				printf("cliente %d foi removido\n", opcao);
				printf("retornando ao menu do cliente...");
				menu_cliente();
			}
		}
	}
}

int menu ()
{
    printf("=========================================================\n");
    printf("\t\tBEM VINDO AO BANCO DO DCOMP\n\n");
    printf("Selecione o numero referente ao que deseja fazer:\n");
    printf("1. Gerenciar agencias\n");
    printf("2. Gerenciar clientes\n");
    printf("3. Gerencias contas \n");
    printf("4. Exibir montante do banco\n");
    printf("5. Sair do banco\n");
    printf("=========================================================\n\n");
    printf("Digite sua opcao: ");

	int opcao;
    scanf("%d", &opcao);

    do{
        switch(opcao){
        	default :
                printf("Digite um numero de 1 a 5: ");
                scanf("%d", &opcao);
            case 1 : menu_agencia(); break;
            case 2 : menu_cliente(); break;
            case 3 : menu_conta(); break;
            case 4 : montante_banco(); break;
            case 5 : return 0;
        }
    } while (opcao > 5 || opcao < 1);
}

int menu_agencia ()
{
    printf("\nVoce deseja: \n\n");
    printf("1. Cadastrar uma agencia?\n");
    printf("2. Remover uma agencia?\n");
    printf("3. Ver os nomes e codigos das agencias existentes?\n");
    printf("4. Retornar ao menu anterior?\n");
    printf("\nDigite sua opcao: ");

	int opcao;
    scanf("%d", &opcao);

	do{
        switch(opcao){
            case 1 : cadastrar_agencia(); break;
            case 2 : remover_agencia(); break;
            case 3 : agencias_existentes(); break;
            case 4 : menu(); break;
            default :
                printf("Digite um numero de 1 a 4: ");
                scanf("%d", &opcao);
        }
    } while (opcao > 4 || opcao < 1);
}

int menu_cliente()
{
    printf("\nVoce deseja: \n\n");
    printf("1. Cadastrar um cliente?\n");
    printf("2. Remover um cliente?\n");
    printf("3. Exibir saldo total do cliente?\n");
    printf("4. Exibir saldo do cliente em uma agencia?\n");
    printf("5. Exibir clientes existentes?\n");
    printf("6. Exibir quantas contas um cliente possui?\n");
	printf("7. Retornar ao menu anterior?\n");
    printf("\nDigite sua opcao: ");

	int opcao;
	scanf("%d", &opcao);

	do{
        switch(opcao){
            case 1 : cadastrar_cliente(); break;
            case 2 : remover_cliente(); break;
            case 3 : saldo_total(); break;
            case 4 : saldo_agencia(); break;
            case 5 : clientes_existentes(); break;
            case 6 : contas_cliente(); break;
			case 7 : menu(); break;
            default :
                printf("Digite um numero de 1 a 6: ");
                scanf("%d", &opcao);
        }
    } while (opcao > 6 || opcao < 1);
}

int menu_conta()
{
	printf("\nVoce deseja: \n\n");
    printf("1. Cadastrar uma conta para um cliente?\n");
    printf("2. Apagar uma conta?\n");
    printf("3. Transferir quantia?\n");
    printf("4. Efetuar pagamento?\n");
    printf("5. Exibir as contas existentes?\n");
    printf("6. Depositar quantia em uma conta?\n");
    printf("7. Retornar ao menu anterior?\n");
    printf("\nDigite sua opcao: ");

	int opcao;
    scanf("%d", &opcao);

    do{
        switch(opcao){
            case 1 : cadastrar_conta(); break;
            case 2 : remover_conta(); break;
            case 3 : transferencia(); break;
            case 4 : printf("em construcao"); break;
            case 5 : contas_existentes(); break;
			case 6 : depositar_quantia(); break;
			case 7 : menu(); break;
            default :
                printf("Digite um numero de 1 a 6: ");
                scanf("%d", &opcao);
        }
    } while (opcao > 6 || opcao < 1);
}

int main()
{
	inicializar();
    menu();
}
