import matplotlib.pyplot as plt
import numpy as np

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
  plik = "dual_pivot_data.txt"
  swaps_d, comparisons_d = wczytaj_dane(plik)

  swaps_sum_d = [0 for i in range(50001)]
  for n, swaps_n in swaps_d:
    swaps_sum_d[n] += swaps_n

  plt.plot([n for n, _ in swaps_d], [swaps_sum_d[n]/(k*n*np.log(n)) for n, _ in swaps_d], label="DualPivotSort")
  plt.xlabel("n")
  plt.ylabel("y")
  plt.title("Average swaps / nln(n)")
  plt.legend()
  plt.show()

if __name__ == "__main__":
  main()
