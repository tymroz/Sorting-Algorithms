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
  plik1 = "insertion_data.txt"
  plik2 = "quick_data.txt"
  plik3 = "hybrid_data.txt"
  swaps_i, comparisons_i = wczytaj_dane(plik1)
  swaps_q, comparisons_q = wczytaj_dane(plik2)
  swaps_h, comparisons_h = wczytaj_dane(plik3)

  plt.subplot(121)
  plt.plot([n for n, _ in swaps_i], [swaps_n/k for _, swaps_n in swaps_i], label="InsertionSort")
  plt.xlabel("n")
  plt.ylabel("Suma swaps")
  plt.title("Average swaps")
  plt.legend()

  plt.subplot(122)
  plt.plot([n for n, _ in comparisons_i], [comparisons_n/k for _, comparisons_n in comparisons_i ], label="InsertionSort")
  plt.xlabel("n")
  plt.ylabel("Suma comparisons")
  plt.title("Average comparisons")
  plt.legend()

  plt.show()

if __name__ == "__main__":
  main()
