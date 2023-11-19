#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->key) {
        root->left = insert(root->left, value);
    } else if (value > root->key) {
        root->right = insert(root->right, value);
    }

    return root;
}

struct TreeNode* search(struct TreeNode* root, int value) {
    if (root == NULL || root->key == value) {
        return root;
    }

    if (value < root->key) {
        return search(root->left, value);
    }

    return search(root->right, value);
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}

struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct TreeNode* deleteNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->key) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->key) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void displayMenu() {
    printf("\nOperacoes disponiveis:\n");
    printf("1. Inserir elemento na arvore\n");
    printf("2. Buscar elemento na arvore\n");
    printf("3. Remover elemento da arvore\n");
    printf("4. Mostrar valor minimo\n");
    printf("5. Mostrar valor maximo\n");
    printf("6. Percorrer a arvore em ordem simetrica\n");
    printf("7. Percorrer a arvore em pre-ordem\n");
    printf("8. Percorrer a arvore em pos-ordem\n");
    printf("9. Sair\n");
    printf("Escolha uma operacao: ");
}

int main() {
    struct TreeNode* root = NULL;
    int choice, value;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("%d encontrado na arvore.\n", value);
                } else {
                    printf("%d nao encontrado na arvore.\n", value);
                }
                break;
            case 3:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    root = deleteNode(root, value);
                    printf("%d removido da arvore.\n", value);
                } else {
                    printf("Numero nao existente, informe um numero existente na arvore.\n");
                }
                break;
            case 4:
                if (root != NULL) {
                    struct TreeNode* minNode = minValueNode(root);
                    printf("Valor minimo na arvore: %d\n", minNode->key);
                } else {
                    printf("Arvore vazia.\n");
                }
                break;
            case 5:
                while (root != NULL && root->right != NULL) {
                    root = root->right;
                }
                if (root != NULL) {
                    printf("Valor maximo na arvore: %d\n", root->key);
                } else {
                    printf("Arvore vazia.\n");
                }
                break;
            case 6:
                printf("Ordem simetrica (Esquerda, Raiz, Direita): ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 7:
                printf("Pre-ordem (Raiz, Esquerda, Direita): ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 8:
                printf("Pos-ordem (Esquerda, Direita, Raiz): ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 9:
                exit(0);
            default:
                printf("Escolha invalida. Por favor, escolha novamente.\n");
        }
    }

    return 0;
}
