# Implementação de Árvore B - Técnicas de Programação

## Descrição do Projeto

O objetivo deste trabalho é implementar um pequeno programa em C++, usando um projeto no Code::Blocks. O trabalho vale 25 (vinte e cinco) pontos da média final. A realização é em dupla.

Serão anulados trabalhos cuja cópia da internet for comprovada em qualquer momento, bem como cópia de trabalhos de outros alunos (sendo anuladas todas as cópias).

É recomendável que o trabalho seja testado em outra plataforma além do Windows.

Além da resolução do problema, será avaliado na entrevista:
- clareza e entendimento do código;
- quem fez o que da dupla;
- lógica;
- aplicação dos conceitos de POO;

# Especificação do Projeto
A dupla deve implementar uma árvore B serializável com suporte para armazenamento de dados em disco. A árvore B será utilizada para organizar dados em disco, 
e a ordenação polifásica será aplicada em dois cenários principais:

## Cenário 1: Construção Inicial da Árvore
1. Entrada: Um arquivo contendo uma grande quantidade de dados desordenados.
2. Etapas:
   - Leitura de Blocos: Leia blocos de dados que caibam na memória principal.
   - Ordenação Local: Ordene cada bloco em memória utilizando um algoritmo como quicksort ou heapsort.
   - Gravação de Blocos Ordenados: Escreva os blocos ordenados em arquivos temporários.
   - Intercalação Polifásica: Combine os blocos ordenados em uma única sequência ordenada usando ordenação polifásica. Essa sequência ordenada será inserida na árvore B.
   - Inserção na Árvore B: Insira os dados ordenados sequencialmente na árvore, garantindo eficiência e balanceamento.

## Cenário 2: Exportação de Dados Ordenados
1. Objetivo: Obter todos os dados armazenados na árvore B em ordem crescente e exportá-los para um arquivo.
2. Etapas:
   - Percurso em Ordem: Leia as páginas da árvore B em ordem crescente. Cada página contém múltiplos registros.
   - Intercalação de Páginas: Use ordenação polifásica para combinar as páginas da árvore e produzir um arquivo de saída completamente ordenado.

# Estrutura do Código Necessária

1. Classe da Árvore B:
   - Implementar inserção, remoção, busca, e balanceamento de nós.
   - Serialização/Deserialização de páginas da árvore B para arquivos binários.
    
2. Módulo de Ordenação Polifásica:
   - Implementação do algoritmo polifásico para arquivos.
   - Funções para:
       - Gerar blocos ordenados a partir dos dados.
       - Distribuir os blocos ordenados entre arquivos temporários.
       - Intercalar arquivos temporários até obter uma sequência completamente ordenada.
3. Interface do Programa:
   - Construir a árvore B a partir de um arquivo desordenado.
   - Exportar os dados da árvore em ordem crescente.
   - Inserir, remover, buscar e exibir a árvore.
4. Funções Auxiliares:
   - Gerenciamento de arquivos temporários.
   - Serialização e deserialização dos dados.
   
