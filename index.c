#include <stdio.h>
#include <string.h>

struct Usuario {
    int id;
    char nome[50];
    char senha[20];
    int tipo;
};

struct Usuario usuarios[10];
int total_usuarios = 0;

void iniciar_sistema();
void mostrar_menu_principal();
void cadastrar_usuario();
void login();

int main() {
    iniciar_sistema();
    mostrar_menu_principal();
    return 0;
}

void iniciar_sistema() {
    printf("=== Sistema de login ===\n\n");

    usuarios[0].id = 1;
    strcpy(usuarios[0].nome, "admin");
    strcpy(usuarios[0].senha, "admin");
    usuarios[0].tipo = 2;

    total_usuarios = 1;

    printf("Usuario admin criado! \nUse: admin / admin\n\n");
}

void mostrar_menu_principal() {
    int opcao;

    while (1) {
        printf("\n=== Menu Principal ===\n");
        printf("1. Fazer Login\n");
        printf("2. Cadastrar Usuario\n");
        printf("3. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            login();
        } else if (opcao == 2) {
            cadastrar_usuario();
        } else if (opcao == 3) {
            printf("Saindo...\n");
            break;
        } else {
            printf("Opcao invalida!\n");
        }
    }
}

void cadastrar_usuario() {
    struct Usuario novo;
    int tipo;

    if (total_usuarios >= 10) {
        printf("Limite de usuarios atingido!\n");
        return;
    }

    novo.id = total_usuarios + 1;

    printf("\n=== Cadastrar usuario ===\n");
    printf("Nome: ");
    scanf(" %[~\n]", novo.nome);
    printf("Senha: ");
    scanf("%s", novo.senha);

    printf("Tipo (1-Funcionario, 2-Gestor): ");
    scanf("%d", &tipo);
    novo.tipo = (tipo == 1 || tipo == 2) ? tipo : 1;

    usuarios[total_usuarios++] = novo;

    printf("\nUsuario cadastrado com sucesso!\n");
    printf("ID: %d | Nome: %s | Tipo: %s\n",
            novo.id, novo.nome, novo.tipo == 1 ? "Funcionario" : "Gestor");
}

void login() {
    char nome[50], senha[20];
    int i, logado = 0;

    printf("\n=== Login ===\n");
    printf("Nome: ");
    scanf("%[~\n]", nome);
    printf("Senha: ");
    scanf("%s", senha);

    for (i = 0; i < total_usuarios; i++) {
        if (strcmp(usuarios[i].nome, nome) == 0 &&
            strcmp(usuarios[i].senha, senha) == 0) {
            printf("\n Bem-vindo, %s! (Tipo: %s)\n",
                    usuarios[i].nome,
                    usuarios[i].tipo == 1 ? "Funcionario" : "Gestor");
            logado = 1;
            break;
        }
    }

    if (!logado) {
        printf("Nome ou senha incorretos!\n");
    }
}