#!/usr/bin/env bash

ls # should only have sisop zip

unzip sisop.zip

cd sisop

I11GVOQQ8Y=$(find . -type f -name I11GVOQQ8Y)

echo $I11GVOQQ8Y

ln $I11GVOQQ8Y ./I11GVOQQ8Y

rm $I11GVOQQ8Y

JPI040GPV8=$(find . -name "JPI040GPV8" -type d)

echo $JPI040GPV8

mkdir -p "My Collection"

# pakai for loop untuk melakukan symlink untuk tiap2 dir dibawah $JPI040GPV8
# untuk tiap item gunakan command ln -s (untuk softlink) {source} {destination}

for item in $JPI040GPV8/*; do ln -s $(pwd)/$item "$(pwd)/My Collection/$(basename $item)"; done

find . -type d -empty -delete

L3TB91=$(find . -type d -name L3TB91)

ln -s $L3TB91 ./sys

LASTFILE=$(ls -p | grep -v / | sort | tail -n 1)

ls -Rl . >$LASTFILE
