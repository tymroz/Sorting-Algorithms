import matplotlib.pyplot as plt

k = 1

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

  plt.subplot(221)
  plt.plot([n for n, _ in swaps_q], [swaps_n/k for _, swaps_n in swaps_q], label="QuickSort")
  plt.plot([n for n, _ in swaps_h], [swaps_n/k for _, swaps_n in swaps_h], label="HybridSort")
  plt.xlabel("n")
  plt.ylabel("swaps")
  plt.title("Average swaps")
  plt.legend()

  plt.subplot(222)
  plt.plot([n for n, _ in comparisons_q], [comparisons_n/k for _, comparisons_n in comparisons_q ], label="QuickSort")
  plt.plot([n for n, _ in comparisons_h], [comparisons_n/k for _, comparisons_n in comparisons_h ], label="HybridSort")
  plt.xlabel("n")
  plt.ylabel("comparisons")
  plt.title("Average comparisons")
  plt.legend()

  plt.subplot(223)
  plt.plot([n for n, _ in swaps_q], [swaps_n/n for n, swaps_n in swaps_q], label="QuickSort")
  plt.plot([n for n, _ in swaps_h], [swaps_n/n for n, swaps_n in swaps_h], label="HybridSort")
  plt.xlabel("n")
  plt.ylabel("swaps")
  plt.title("Average swaps / n")
  plt.legend()

  plt.subplot(224)
  plt.plot([n for n, _ in comparisons_q], [comparisons_n/n for n, comparisons_n in comparisons_q ], label="QuickSort")
  plt.plot([n for n, _ in comparisons_h], [comparisons_n/n for n, comparisons_n in comparisons_h ], label="HybridSort")
  plt.xlabel("n")
  plt.ylabel("comparisons")
  plt.title("Average comparisons / n")
  plt.legend()

  plt.show()

if __name__ == "__main__":
  main()
