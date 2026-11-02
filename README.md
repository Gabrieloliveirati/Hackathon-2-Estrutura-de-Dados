# Hackathon 2 – Estrutura de Dados: Árvores e Ordenação

## Equipe
- Nome da equipe: [Normandmax]
- Integrantes: [Gabriel Dos Santos Oliveira]
- Responsabilidades: [Gabriel Dos Santos Oliveira]

## Ambiente
- Linguagem: C++17
- Compilador: g++ (GCC)
- Sistema utilizado:  Windows 11]

## Organização
- `desafios/01` até `desafios/15`: um executável independente por desafio.
- `testes/01` até `testes/15`: entradas e saídas esperadas.
- `scripts/testar.py`: compila e executa os casos `.in`, comparando com `.out`.

## Compilação e execução
Exemplo para o desafio 01:

```bash
g++ -std=c++17 -O2 -Wall -Wextra desafios/01/main.cpp -o desafio01
./desafio01 < testes/01/exemplo.in
```

No PowerShell:

```powershell
g++ -std=c++17 -O2 -Wall -Wextra desafios/01/main.cpp -o desafio01.exe
Get-Content testes/01/exemplo.in | .\desafio01.exe
```

## Testes automatizados
Execute:

```bash
python scripts/testar.py
```

Cada desafio deve possuir pelo menos quatro entradas distintas: exemplo do caderno, caso mínimo, caso de borda e caso adicional não trivial. Registre também um teste de escala próximo ao limite e a verificação automática do resultado.

## Desafios implementados
1. Retrato de uma árvore — contagem de folhas e nós internos.
2. Três percursos — pré-ordem, em ordem e pós-ordem iterativos.
3. Construção de uma BST — inserção e percurso em ordem.
4. Busca com profundidade — consulta iterativa em BST.
5. Altura e níveis — BFS para altura e largura.
6. Remoção em uma BST — remoção usando sucessor em ordem.
7. Diagnóstico de balanceamento — cálculo de altura em pós-ordem.
8. Seleção em ação — selection sort e contadores.
9. Inserção estável de registros — insertion sort e deslocamentos.
10. Merge sort e inversões — contagem durante intercalação.
11. Quicksort com três regiões — partição Dutch National Flag, pivô pseudoaleatório.
12. Reconstrução balanceada — extração em ordem e construção pelo ponto médio.
13. Catálogo com consultas por faixa — operações em BST.
14. Ranking com índice balanceado — merge sort e BST com tamanho de subárvore.
15. Central dinâmica de pedidos — AVL com frequência e tamanho total.

## Complexidades
| Desafio | Tempo principal | Memória auxiliar |
|---|---:|---:|
| 01 | O(n) | O(n) |
| 02 | O(n) | O(n) |
| 03 | O(nh) | O(n) |
| 04 | O(nh + qh) | O(n) |
| 05 | O(n) | O(n) |
| 06 | O(nh + qh) | O(n) |
| 07 | O(n) | O(n) |
| 08 | O(n²) | O(1) |
| 09 | O(n²) | O(1), além dos registros |
| 10 | O(n log n) | O(n) |
| 11 | Esperado O(n log n); pior O(n²) | O(log n) de pilha |
| 12 | O(nh) | O(n) |
| 13 | O(h + 1) por operação simples; O(h + k + 1) por faixa | O(n) |
| 14 | O(n log n) de preparação; O(log n) por consulta | O(n) |
| 15 | O(log(m + 1)) por I/R/K; O(t + 1) por L | O(m) |

## Decisões de implementação
- Árvores binárias são representadas por nós com ponteiros para filhos.
- Duplicatas são ignoradas nas BSTs, exceto no desafio 15, que armazena frequência.
- O desafio 06 e o 13 usam o sucessor em ordem na remoção de nós com dois filhos.
- O desafio 10 usa `long long` para a contagem de inversões.
- O desafio 11 usa semente fixa para reprodutibilidade dos testes.
- O desafio 15 atualiza altura e quantidade total após inserções, remoções e rotações.

## Fontes consultadas e uso de IA
- Enunciado: Hackathon 2 – Estrutura de Dados: Árvores e Ordenação (PDF fornecido pelo professor).
- Documentação da linguagem C++: [adicionar links efetivamente consultados].
- Uso de IA: [descrever honestamente quais trechos foram sugeridos, revisados ou adaptados com auxílio de IA].
- Todos os integrantes devem revisar, testar e conseguir explicar os códigos entregues.

## Limitações conhecidas
- As BSTs dos desafios 03, 04, 06, 12 e 13 não são balanceadas e podem atingir altura O(n).
- O desafio 07 usa recursão para calcular alturas; para uma árvore degenerada muito profunda, a pilha de chamadas pode ser um limite prático.
- O script automatizado compara casos presentes nas pastas; os quatro casos exigidos e os testes de escala precisam ser adicionados e conferidos pela equipe antes da entrega.

## Checklist final
- [ ] Nome da equipe e integrantes preenchidos.
- [ ] Responsabilidades registradas.
- [ ] Quatro testes distintos por desafio.
- [ ] Testes de escala próximos aos limites.
- [ ] Todos os testes automatizados aprovados.
- [ ] Compilação feita em cópia limpa.
- [ ] Commit final identificado por hash.
- [ ] Repositório acessível à organização.
- [ ] URL do repositório e hash enviados à organização.
