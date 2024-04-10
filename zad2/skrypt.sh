#!/bin/bash

for n in $(seq 1000 1000 50000); do
  for i in $(seq 1 100); do
    ./Random $n | ./Hybrid
    ./Random $n | ./Quick
  done
done
