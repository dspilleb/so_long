#!/bin/bash

for file in $(find . -name '*.png'); do
    convert $file -crop 28x28+10+16 -scale 96x96 ${file%.png}.xpm
	rm $file
done