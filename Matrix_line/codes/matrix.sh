#!/bin/bash

python3 matrix.py

cd /sdcard/iithfwc/trunk/Matrix_line/Documents

pdflatex matrix.tex

termux-open matrix.pdf
