Explicação sobre Estabilidade na Ordenação
Algoritmos Estáveis:
Um algoritmo de ordenação é considerado estável quando ele mantém a ordem relativa dos elementos com chaves iguais. Ou seja, se dois elementos possuem o mesmo valor, o que aparece primeiro na entrada aparecerá primeiro na saída.
Exemplos: Merge Sort, Bubble Sort, Insertion Sort.
Algoritmos Instáveis:
Um algoritmo é considerado instável quando ele pode alterar a ordem relativa dos elementos com chaves iguais.
Exemplos: Quick Sort, Selection Sort.
Demonstração com Exemplo:
Imagine um vetor de objetos onde cada objeto é uma estrutura com um valor e um nome. Por exemplo, o vetor de pares de números (valor, nome):

Valor: 10, Nome: "A"
Valor: 10, Nome: "B"
Valor: 5, Nome: "C"
Valor: 10, Nome: "C"

Merge Sort (Estável) manteria a ordem "A", "B" para os valores 10.
Quick Sort (Instável) pode alterar essa ordem, dependendo do critério de divisão (pivot).