import matplotlib.pyplot as plt
import numpy as np

# Função para visualizar a execução do Merge Sort
def plot_merge_sort(arr):
    plt.figure(figsize=(10, 6))
    plt.bar(range(len(arr)), arr, color='skyblue')
    plt.title("Merge Sort - Etapas")
    plt.xlabel("Índice")
    plt.ylabel("Valor")
    plt.grid(True)
    plt.show()

# Função para visualizar a execução do Quick Sort
def plot_quick_sort(arr):
    plt.figure(figsize=(10, 6))
    plt.bar(range(len(arr)), arr, color='lightgreen')
    plt.title("Quick Sort - Etapas")
    plt.xlabel("Índice")
    plt.ylabel("Valor")
    plt.grid(True)
    plt.show()

# Função para visualizar a execução do Selection Sort
def plot_selection_sort(arr):
    plt.figure(figsize=(10, 6))
    plt.bar(range(len(arr)), arr, color='salmon')
    plt.title("Selection Sort - Etapas")
    plt.xlabel("Índice")
    plt.ylabel("Valor")
    plt.grid(True)
    plt.show()

# Lista de exemplo para ordenação
arr_merge = [38, 27, 43, 3, 9, 82, 10]
arr_quick = [38, 27, 43, 3, 9, 82, 10]
arr_selection = [38, 27, 43, 3, 9, 82, 10]

# Plotando os gráficos
plot_merge_sort(arr_merge)
plot_quick_sort(arr_quick)
plot_selection_sort(arr_selection)
