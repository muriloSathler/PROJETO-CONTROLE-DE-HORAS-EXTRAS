#include <stdio.h>

int usuario_logado_id = 1; // Exemplo: gestor logado
void menu_gestor();
void aprovar_horas_extra();
void listar_horas_pendentes();
void gerar_relatorio();

int main() {
    menu_gestor();
    return 0;
}

void menu_gestor() {
    int opcao;

    while (1) {
        printf("\n=== MENU GESTOR ===\n");
        printf("1 - Aprovar horas\n");
        printf("2 - Ver horas pendentes\n");
        printf("3 - Gerar relatorio\n");
        printf("4 - Logout\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                aprovar_horas_extra();
                break;
            case 2:
                listar_horas_pendentes();
                break;
            case 3:
                gerar_relatorio();
                break;
            case 4:
                printf("\nDeslogando...\n");
                usuario_logado_id = -1;
                return;
            default:
                printf("\nOpcao inválida! Tente novamente.\n");
                break;
        }
    }
}

void aprovar_horas_extra() {
    int id_solicitacao, acao;

    printf("\n=== APROVAR HORAS ===\n");
    printf("ID da solicitacao: ");
    scanf("%d", &id_solicitacao);

    printf("1 - Aprovar\n");
    printf("2 - Recusar\n");
    printf("Escolha: ");
    scanf("%d", &acao);

    if (acao == 1) {
        printf("\nSolicitação %d APROVADA.\n", id_solicitacao);
    } else if (acao == 2) {
        printf("\nSolicitação %d RECUSADA.\n", id_solicitacao);
    } else {
        printf("\nOpcao inválida!\n");
    }
}

void listar_horas_pendentes() {
    printf("\n=== HORAS PENDENTES ===\n");
    printf("Funcionario 2 -> 3 horas pendentes\n");
    printf("Funcionario 5 -> 6 horas pendentes\n");
}

void gerar_relatorio() {
    printf("\n=== RELATORIO DE HORAS ===\n");
    printf("Total de funcionarios: 12\n");
    printf("Horas pendentes: 18h\n");
    printf("Horas aprovadas: 42h\n");
}
