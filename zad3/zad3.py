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
  plik1 = "merge_data.txt"
  plik2 = "mysort_data.txt"
  swaps_d, comparisons_d = wczytaj_dane(plik1)
  swaps_q, comparisons_q = wczytaj_dane(plik2)
  
  swaps_sum_d = [0 for i in range(50001)]
  for n, swaps_n in swaps_d:
    swaps_sum_d[n] += swaps_n

  swaps_sum_q = [0 for i in range(50001)]
  for n, swaps_n in swaps_q:
    swaps_sum_q[n] += swaps_n

  comp_sum_d = [0 for i in range(50001)]
  for n, comparisons_n in comparisons_d:
    comp_sum_d[n] += comparisons_n

  comp_sum_q = [0 for i in range(50001)]
  for n, comparisons_n in comparisons_q:
    comp_sum_q[n] += comparisons_n
  
  plt.subplot(221)
  plt.plot([n for n, _ in swaps_d], [swaps_sum_d[n]/k for n, _ in swaps_d], label="MergeSort")
  plt.plot([n for n, _ in swaps_q], [swaps_sum_q[n]/k for n, _ in swaps_q], label="MySort")
  plt.xlabel("n")
  plt.ylabel("swaps")
  plt.title("Average swaps")
  plt.legend()

  plt.subplot(222)
  plt.plot([n for n, _ in comparisons_d], [comp_sum_d[n]/k for n, _ in comparisons_d ], label="MergeSort")
  plt.plot([n for n, _ in comparisons_q], [comp_sum_q[n]/k for n, _ in comparisons_q ], label="MySort")
  plt.xlabel("n")
  plt.ylabel("comparisons")
  plt.title("Average comparisons")
  plt.legend()

  plt.subplot(223)
  plt.plot([n for n, _ in swaps_d], [swaps_sum_d[n]/(k*n) for n, _ in swaps_d], label="MergeSort")
  plt.plot([n for n, _ in swaps_q], [swaps_sum_q[n]/(k*n) for n, _ in swaps_q], label="MySort")
  plt.xlabel("n")
  plt.ylabel("swaps")
  plt.title("Average swaps / n")
  plt.legend()

  plt.subplot(224)
  plt.plot([n for n, _ in comparisons_d], [comp_sum_d[n]/(k*n) for n, _ in comparisons_d ], label="MergeSort")
  plt.plot([n for n, _ in comparisons_q], [comp_sum_q[n]/(k*n) for n, _ in comparisons_q ], label="MySort")
  plt.xlabel("n")
  plt.ylabel("comparisons")
  plt.title("Average comparisons / n")
  plt.legend()

  plt.show()

if __name__ == "__main__":
  main()
