O Shell Sort utiliza sublistas criadas por "gaps" para ordenar elementos distantes antes de ordenar elementos adjacentes.
Testando diferentes sequências de intervalos (ex.: Shell, Knuth, Hibbard) impacta a eficiência:
Shell (n/2, n/4, ...): Simples e eficiente.
Knuth (3k-1): Reduz comparações.
Hibbard (2k-1): Melhora desempenho médio.