#include <iostream>
#include <BTree.h>
#include <BTreeNode.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int escolha;
    BTree arvore(3);  // Ordem da árvore B
    do {
        std::cout << "\nMenu BTree:\n";
        std::cout << "1. Inserir chave\n";
        std::cout << "2. Exibir árvore\n";
        std::cout << "3. Procurar chave\n";
        std::cout << "4. Carregar dados de arquivo\n";
        std::cout << "5. Exportar dados para arquivo\n";
        std::cout << "6. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1: {
                int chave;
                std::cout << "Digite a chave a ser inserida: ";
                std::cin >> chave;
                arvore.insert(chave);
                break;
            }
            case 2:
                std::cout << "Exibindo árvore: ";
                arvore.traverse();
                std::cout << std::endl;
                break;
            case 3: {
                int chave;
                std::cout << "Digite a chave a ser procurada: ";
                std::cin >> chave;
                BTreeNode* resultado = arvore.search(chave);
                if (resultado) {
                    std::cout << "Chave encontrada!" << std::endl;
                } else {
                    std::cout << "Chave não encontrada." << std::endl;
                }
                break;
            }
            case 4: {
                std::string arquivo;
                std::cout << "Digite o nome do arquivo de entrada: ";
                std::cin >> arquivo;
                arvore.loadFromInputFile(arquivo);
                break;
            }
            case 5: {
                std::string arquivo;
                std::cout << "Digite o nome do arquivo de saída: ";
                std::cin >> arquivo;
                arvore.exportToFile(arquivo);
                break;
            }
            case 6:
                std::cout << "Saindo..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida!" << std::endl;
        }
    } while (escolha != 6);
    return 0;
}
