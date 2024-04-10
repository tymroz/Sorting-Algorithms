import matplotlib.pyplot as plt

k = 100

def wczytaj_dane(plik):
  swaps = []
  comparisons = []
  with open(plik, "r") as f:
    for line in f:
      n, swaps_n, comparisons_n = line.split()
      swaps.append([int(n), int(swaps_n)])
      comparisons.append([int(n), int(comparisons_n)])
  return swaps, comparisons

def main():
  plik2 = "quick_data.txt"
  plik3 = "hybrid_data.txt"
  swaps_q, comparisons_q = wczytaj_dane(plik2)
  swaps_h, comparisons_h = wczytaj_dane(plik3)

  swaps_sum_q = [0 for i in range(50001)]
  for n, swaps_n in swaps_q:
    swaps_sum_q[n] += swaps_n

  swaps_sum_h = [0 for i in range(50001)]
  for n, swaps_n in swaps_h:
    swaps_sum_h[n] += swaps_n

  comp_sum_q = [0 for i in range(50001)]
  for n, comparisons_n in comparisons_q:
    comp_sum_q[n] += comparisons_n

  comp_sum_h = [0 for i in range(50001)]
  for n, comparisons_n in comparisons_h:
    comp_sum_h[n] += comparisons_n
  
  plt.subplot(221)
  plt.plot([n for n, _ in swaps_q], [swaps_sum_q[n]/k for n, _ in swaps_q], label="QuickSort")
  plt.plot([n for n, _ in swaps_h], [swaps_sum_h[n]/k for n, _ in swaps_h], label="HybridSort")
  plt.xlabel("n")
  plt.ylabel("swaps")
  plt.title("Average swaps")
  plt.legend()

  plt.subplot(222)
  plt.plot([n for n, _ in comparisons_q], [comp_sum_q[n]/k for n, _ in comparisons_q ], label="QuickSort")
  plt.plot([n for n, _ in comparisons_h], [comp_sum_h[n]/k for n, _ in comparisons_h ], label="HybridSort")
  plt.xlabel("n")
  plt.ylabel("comparisons")
  plt.title("Average comparisons")
  plt.legend()

  plt.subplot(223)
  plt.plot([n for n, _ in swaps_q], [swaps_sum_q[n]/(k*n) for n, _ in swaps_q], label="QuickSort")
  plt.plot([n for n, _ in swaps_h], [swaps_sum_h[n]/(k*n) for n, _ in swaps_h], label="HybridSort")
  plt.xlabel("n")
  plt.ylabel("swaps")
  plt.title("Average swaps / n")
  plt.legend()

  plt.subplot(224)
  plt.plot([n for n, _ in comparisons_q], [comp_sum_q[n]/(k*n) for n, _ in comparisons_q ], label="QuickSort")
  plt.plot([n for n, _ in comparisons_h], [comp_sum_h[n]/(k*n) for n, _ in comparisons_h ], label="HybridSort")
  plt.xlabel("n")
  plt.ylabel("comparisons")
  plt.title("Average comparisons / n")
  plt.legend()

  plt.show()

if __name__ == "__main__":
  main()
