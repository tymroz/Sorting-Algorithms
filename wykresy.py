import matplotlib.pyplot as plt

with open('insertion_data.txt', 'r') as file:
    data = file.readlines()
swaps_insertion = [int(line.split()[0]) for line in data]
comparisons_insertion = [int(line.split()[1]) for line in data]

with open('quick_data.txt', 'r') as file:
    data = file.readlines()
swaps_quick = [int(line.split()[0]) for line in data]
comparisons_quick = [int(line.split()[1]) for line in data]

with open('hybrid_data.txt', 'r') as file:
    data = file.readlines()
swaps_hybrid = [int(line.split()[0]) for line in data]
comparisons_hybrid = [int(line.split()[1]) for line in data]

n_values = [10, 20, 30, 40, 50]

swaps_n_insertion = [swaps_insertion[i] / n_values[i] for i in range(len(n_values))]
swaps_n_quick = [swaps_quick[i] / n_values[i] for i in range(len(n_values))]
swaps_n_hybrid = [swaps_hybrid[i] / n_values[i] for i in range(len(n_values))]

comparisons_n_insertion = [comparisons_insertion[i] / n_values[i] for i in range(len(n_values))]
comparisons_n_quick = [comparisons_quick[i] / n_values[i] for i in range(len(n_values))]
comparisons_n_hybrid = [comparisons_hybrid[i] / n_values[i] for i in range(len(n_values))]

plt.subplot(2, 2, 1)
plt.scatter(n_values, swaps_insertion, color="blue", label='InsertionSort')
plt.scatter(n_values, swaps_quick, color="red", label='QuickSort')
plt.scatter(n_values, swaps_hybrid, color="green", label='HybridSort')
plt.xlabel('n')
plt.ylabel('Count')
plt.title('Average Swaps')
plt.legend()

# Wykres dla porównań
plt.subplot(2, 2, 2)
plt.scatter(n_values, comparisons_insertion, color="blue", label='InsertionSort')
plt.scatter(n_values, comparisons_quick, color="red", label='QuickSort')
plt.scatter(n_values, comparisons_hybrid, color="green", label='HybridSort')
plt.xlabel('n')
plt.ylabel('Count')
plt.title('Average Comparisons')
plt.legend()

plt.subplot(2, 2, 3)
plt.scatter(n_values, swaps_n_insertion, color="blue", label='InsertionSort')
plt.scatter(n_values, swaps_n_quick, color="red", label='QuickSort')
plt.scatter(n_values, swaps_n_hybrid, color="green", label='HybridSort')
plt.xlabel('n')
plt.ylabel('Count')
plt.title('Average Swaps / n')
plt.legend()

plt.subplot(2, 2, 4)
plt.scatter(n_values, comparisons_n_insertion, color="blue", label='InsertionSort')
plt.scatter(n_values, comparisons_n_quick, color="red", label='QuickSort')
plt.scatter(n_values, comparisons_n_hybrid, color="green", label='HybridSort')
plt.xlabel('n')
plt.ylabel('Count')
plt.title('Average Comparisons / n')
plt.legend()

plt.tight_layout()
plt.show()