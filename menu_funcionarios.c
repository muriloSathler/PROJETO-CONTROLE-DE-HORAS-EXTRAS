#include <stdio.h>

int usuario_logado_id = 10; // Valor simulado (logado)
void menu_funcionario();
void registrar_horas_extra();
void listar_horas_funcionario();

int main() {
    menu_funcionario();
    return 0;
}

void menu_funcionario() {
    int opcao;

    while (1) {
        printf("\n=== MENU FUNCIONARIO ===\n");
        printf("1 - Registrar horas extras\n");
        printf("2 - Ver minhas horas\n");
        printf("3 - Logout\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                registrar_horas_extra();
                break;
            case 2:
                listar_horas_funcionario();
                break;
            case 3:
                printf("\nDeslogando...\n");
                usuario_logado_id = -1;
                return;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                break;
        }
    }
}

void registrar_horas_extra() {
    int horas;
    printf("\n=== REGISTRAR HORAS EXTRAS ===\n");
    printf("Digite a quantidade de horas: ");
    scanf("%d", &horas);

    printf("\nHoras extras registradas com sucesso!\n");
    printf("Funcionario ID: %d\n", usuario_logado_id);
    printf("Horas registradas: %d\n", horas);
}

void listar_horas_funcionario() {
    printf("\n=== MINHAS HORAS EXTRAS ===\n");

    // Exemplo estático — no futuro será buscado de arquivo
    printf("Funcionario ID: %d\n", usuario_logado_id);
    printf("Horas pendentes: 4\n");
    printf("Horas aprovadas: 7\n");
}
