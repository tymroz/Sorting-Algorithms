#!/bin/bash

for n in $(seq 1000 1000 50000); do
  for i in $(seq 1 10); do
    ./Random $n | ./Insertion
  done
done
