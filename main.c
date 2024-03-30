#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float InserirNotas();
float CalcMedia(float n1, float n2);
int idAluno();

int main(int argc, char const *argv[])
{
    
    //declaração de Variaveis
    int opcao_Menu,i,j;
    float NotasP1[5],NotasP2[5],Medias[5];
    char Nomes[5][50];
    //setando as variaveis
    for (i=0; i < 6; i++)
    {
        NotasP1[i] = 0;
        NotasP2[i] = 0;
        Medias[i] = 0;
    }
    //função memset para setar matriz para caracteres vazio ' '
    memset(Nomes, ' ',sizeof(Nomes));
    // Menu
    while (opcao_Menu != 5)
    {   
        //Incluido indice para os vetores
        fflush(stdin);
        i = idAluno();
        system("cls");
        // Menu
        printf("MENU\n\t1.0 Inserir Nome Alunos\n\t2.0 Inserir Notas P1\n\t3.0 Inserir Notas P2\n\t4.0 Relatorio Media Final\n\t5.0 Sair\n");
        printf("O que deseja fazer ? ");
        scanf("%d", &opcao_Menu);
        switch (opcao_Menu)
        {
            //Opções Menu
            case 1:
                system("cls");
                setbuf(stdin,0);
                printf("Digite o Nome do Aluno(a): ");
                fgets(Nomes[i], 50, stdin);
                Nomes[i][strlen(Nomes[i])-1] = '\0';
                break;
            case 2:
                system("cls");
                fflush(stdin);
                NotasP1[i] = InserirNotas();
                break;
            case 3:
                system("cls");
                fflush(stdin);
                NotasP2[i] = InserirNotas();
                break;
            case 4:   
                system("cls");
                for (j = 0; j < 5; j++)
                {
                    
                    Medias[j] = CalcMedia(NotasP1[j],NotasP2[j]);
                    
                }
                printf("RELATORIO DA SALA\n");
                for (j = 0; j < 5; j++)
                {
                    
                    printf("NOME ALUNO(A): %s\n", Nomes[j]);
                    printf("Identificacao: %d\n", j);
                    printf("NOTAS P1:.....  %.2f\n", NotasP1[j]);
                    printf("NOTAS P2:.....  %.2f\n", NotasP2[j]);
                    printf("MEDIA FINAL:... %.2f\n", Medias[j]);
                    if (Medias[j] >= 6.0)
                    {
                        printf("SITUACAO: APROVADO\n");
                        printf("-------------------------\n");
                    }
                    else if (NotasP1[j] < 2 && NotasP2[j]>= 2)
                    {
                        printf("SITUACAO: EXAME P3\n Substituir Notas P1\n");
                        printf("-------------------------\n");
                    }  
                            else if (NotasP2[j] < 2 && NotasP1[j] >= 2)
                            {
                                printf("SITUACAO: EXAME P3\n Substituir Notas P2\n");
                                printf("-------------------------\n");
                            }
                                else 
                                {
                                    printf("SITUACAO: REPROVADO\n");
                                    printf("-------------------------\n");
                                }
                    
                }
                break;
            case 5:
                system("cls");
                opcao_Menu = 5;
                return opcao_Menu;
                break;
            default:
                system("cls");
                printf("OPCAO INVALIDA! TENTE NOVAMENTE");
                break;
        }
    } 
    system("pause");   
    return 0;
}

float InserirNotas()
{   
    float nota;

    printf("Digite a nota do Aluno: ");
    scanf("%f", &nota);
    fflush(stdin);

    return nota;

}

float CalcMedia(float n1, float n2)
{   
    float med;
    
    med = (n1 + n2)/2.0;
    fflush(stdin);

    return med;


}
int idAluno()
{
    int ide;

    printf("Digite o Id do Aluno: ");
    scanf("%d", &ide);

    return ide;
}

