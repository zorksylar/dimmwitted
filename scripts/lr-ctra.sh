#!/bin/bash

bin=./dw-lr-train
data_in=./format/ctra.dw


$bin -s 0.01 -e 10 -r 0.0001 $data_in

