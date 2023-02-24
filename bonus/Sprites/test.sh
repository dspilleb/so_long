#!/bin/bash

for file in $(find . -name '*.png'); do
	convert $file -flop ${file%.png}.png
    convert $file -trim -scale 96x96 ${file%.png}.xpm
	rm $file
done