A lista deve estar ordenada porque a busca binária funciona dividindo-a em metades, eliminando a metade que não contém o valor procurado em cada iteração. Se a lista não for ordenada, não há como garantir que o elemento procurado está em uma das metades eliminadas.

Exemplo de erro em lista desordenada:
Lista: {5, 12, 7, 19}
Procurando o valor 7, a divisão binária eliminaria 7 incorretamente.
